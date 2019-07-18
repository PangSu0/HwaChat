#include <mutex>
#include <thread>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

AVFrame* frame;
// 아래 두개 변수는 각각 OpenCV 이미지(BGR24), ffmpeg 이미지(이 예제에선 YUV420)를 위한 변수이다.
AVPicture src_picture, dst_picture;
void open_video(AVFormatContext* oc, AVCodec* codec, AVStream* st)
{
	int ret;
	AVCodecContext* c = st->codec;

	/* open the codec */
	ret = avcodec_open2(c, codec, NULL);
	if (ret < 0) {
		// ERROR
		fprintf(stderr, "Could not open video codec: ");
		return;
	}

	/* allocate and init a re-usable frame */
	// av_frame_alloc 함수는 frame의 데이터 버퍼를 할당하지 않는다.
	// 데이터를 제외한 나머지 부분만을 할당한다.
	frame = av_frame_alloc();
	if (!frame) {
		// ERROR
		fprintf(stderr, "Could not allocate video frame\n");
		return;
	}
	frame->format = c->pix_fmt;
	frame->width = c->width;
	frame->height = c->height;

	/* Allocate the encoded raw picture. */
	ret = avpicture_alloc(&dst_picture, c->pix_fmt, c->width, c->height);
	if (ret < 0) {
		fprintf(stderr, "Could not allocate picture: ");
		exit(1);
	}
	ret = avpicture_alloc(&src_picture, AV_PIX_FMT_BGR24, c->width, c->height);
	if (ret < 0) {
		fprintf(stderr, "Could not allocate temporary picture:");
		exit(1);
	}

	/* copy data and linesize picture pointers to frame */
	// AVFrame이 AVPicture의 확장 구조체라고 할 수 있다.
	// AVFrame과 AVPicture 구조체의 정의를 보면 알 수 있겠지만, AVFrame의 처음 두개 멤버(이미지 데이터)가 AVPicture와 같다.
	// 위 주석에서 설명됐듯이 av_frame_alloc함수는 데이터 버퍼를 할당하지 않기 때문에, dst_picture에 할당된 데이터 버퍼를 frame 변수가 쓰게 하는 것이다.
	*((AVPicture*)(frame)) = dst_picture;
}

int frame_count = 0;
void write_video_frame(AVFormatContext* oc, AVStream* st, cv::Mat cv_img, int flush)
{
	int ret;
	static struct SwsContext* sws_ctx;
	AVCodecContext* c = st->codec;

	if (!flush) {
		// BGR opencv image to AV_PIX_FMT_YUV420P
		cv::resize(cv_img, cv_img, cv::Size(c->width, c->height));

		// BGR24 이미지를 YUV420 이미지로 변환하기 위한 context를 할당받는다.
		if (!sws_ctx) {
			sws_ctx = sws_getContext(c->width, c->height, AV_PIX_FMT_BGR24,
				c->width, c->height, c->pix_fmt,
				SWS_BICUBIC, NULL, NULL, NULL);
			if (!sws_ctx) {
				fprintf(stderr,
					"Could not initialize the conversion context\n");
				exit(1);
			}
		}

		// OpenCV Mat 데이터를 ffmpeg 이미지 데이터로 복사
		avpicture_fill(&src_picture, cv_img.data, AV_PIX_FMT_BGR24, c->width, c->height);

		// BGR24 이미지를 YUV420이미지로 복사
		sws_scale(sws_ctx,
			(const uint8_t * const*)(src_picture.data), src_picture.linesize,
			0, c->height, dst_picture.data, dst_picture.linesize);
	}

	AVPacket pkt = { 0 };
	int got_packet;
	av_init_packet(&pkt);

	/* encode the image */
	// 스트림의 코덱에 맞게 인코딩하여 pkt변수에 할당된다.
	frame->pts = frame_count;
	ret = avcodec_encode_video2(c, &pkt, flush ? NULL : frame, &got_packet);
	if (ret < 0) {
		fprintf(stderr, "Error encoding video frame:");
		exit(1);
	}
	/* If size is zero, it means the image was buffered. */
	if (got_packet) {
		// 제대로 이미지가 인코딩 됐으면 스트림에 이미지를 쓴다.
		ret = write_frame(oc, &c->time_base, st, &pkt);
	}
	else {
		if (flush)
			video_is_eof = 1;
		ret = 0;
	}

	if (ret < 0) {
		fprintf(stderr, "Error while writing video frame: ");
		exit(1);
	}
	frame_count++;
}

int write_frame(AVFormatContext * fmt_ctx, const AVRational * time_base, AVStream * st, AVPacket * pkt)
{
	/* rescale output packet timestamp values from codec to stream timebase */
	pkt->pts = av_rescale_q_rnd(pkt->pts, *time_base, st->time_base, AVRounding(AV_ROUND_NEAR_INF | AV_ROUND_PASS_MINMAX));
	pkt->dts = av_rescale_q_rnd(pkt->dts, *time_base, st->time_base, AVRounding(AV_ROUND_NEAR_INF | AV_ROUND_PASS_MINMAX));
	pkt->duration = av_rescale_q(pkt->duration, *time_base, st->time_base);
	pkt->stream_index = st->index;

	/* Write the compressed frame to the media file. */
	return av_interleaved_write_frame(fmt_ctx, pkt);
}

//...

// 이미지를 지속적으로 카메라로부터 얻어 전송하는 스레드 함수
void SendStream()
{
	cv::Mat cam_img;

	while (true)
	{
		// 비동기 스트리밍 중지
		mtx_lock.lock();
		bool thread_end = is_streaming;
		mtx_lock.unlock();

		video_cap >> cam_img;

		// end of video stream
		if (cam_img.empty())
		{
			EndStream();
			break;
		}

		// user finish
		if (!thread_end)
		{
			// write last frame
			if (!ffmpeg.StreamImage(cam_img, true))
			{
				// ERROR
				return;
			}
			break;
		}

		// write frame
		if (!ffmpeg.StreamImage(cam_img, false))
		{
			// ERROR
			return;
		}

		// FPS만큼 기다린다.
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / STREAM_FPS));
	}
}

void EndStream()
{
	if (sender)
	{
		mtx_lock.lock();
		is_streaming = false;
		mtx_lock.unlock();

		// wait until finish
		sender->join();

		delete sender;
	}
	if (video_cap.isOpened())
		video_cap.release();
	sender = NULL;

	// 아래 av_write_trailer는 output context를 닫기 전에 호출해야 한다는데 정확히는 몰라서 더 찾아봐야한다..
	/* Write the trailer, if any. The trailer must be written before you
	* close the CodecContexts open when you wrote the header; otherwise
	* av_write_trailer() may try to use memory that was freed on
	* av_codec_close(). */
	if (oc)
		av_write_trailer(oc);

	/* Close each codec. */
	if (video_st)
		close_video(video_st);
	//if (audio_st)
	//  close_audio(audio_st);

	if (fmt && oc)
		if (!(fmt->flags & AVFMT_NOFILE))
			/* Close the output file. */
			avio_close(oc->pb);

	/* free the stream */
	if (oc)
		avformat_free_context(oc);

	oc = NULL;
	fmt = NULL;
	video_st = NULL;
}