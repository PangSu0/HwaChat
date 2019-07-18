extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
}

#include <iostream>
using namespace std;

int main()
{
	AVCodecContext* m_codecContext;
	AVCodec* m_codec;
	AVFormatContext* m_formatContext;
	AVStream* m_stream;

	unsigned m_outWidth = 768;
	unsigned m_outHeight = 608;

	av_register_all();
	avcodec_register_all();
	avformat_network_init();

	int errorStatus = 0;
	char errorLog[128] = { 0 };
	av_log_set_level(AV_LOG_TRACE);

	string m_output("udp://127.0.0.1:8554/live.sdp");

	if (avformat_alloc_output_context2(&m_formatContext, NULL, "h264", m_output.c_str()) < 0) {
		cerr << "Cannot allocate output context: "
			<< av_make_error_string(errorLog, 128, errorStatus) << endl;
		return -1;
	}

	AVOutputFormat* m_outputFormat = m_formatContext->oformat;

	m_codec = avcodec_find_encoder(AV_CODEC_ID_H264);
	if (!m_codec) {
		cerr << "Cannot find an encoder: "
			<< av_make_error_string(errorLog, 128, errorStatus) << endl;
		return -1;
	}

	m_codecContext = avcodec_alloc_context3(m_codec);
	if (!m_codecContext) {
		cerr << "Cannot allocate a codec context: "
			<< av_make_error_string(errorLog, 128, errorStatus) << endl;
		return -1;
	}

	m_codecContext->pix_fmt = AV_PIX_FMT_YUV420P;
	m_codecContext->width = m_outWidth;
	m_codecContext->height = m_outHeight;

	if (avcodec_open2(m_codecContext, m_codec, NULL) < 0) {
		cerr << "Cannot open codec: "
			<< av_make_error_string(errorLog, 128, errorStatus) << endl;
		return -1;
	}

	m_stream = avformat_new_stream(m_formatContext, m_codec);
	if (!m_stream) {
		cerr << "Cannot create a new stream: "
			<< av_make_error_string(errorLog, 128, errorStatus) << endl;
		return -1;
	}

	av_dump_format(m_formatContext, 0, m_output.c_str(), 1);

	if ((errorStatus = avio_open(&m_formatContext->pb, m_output.c_str(), AVIO_FLAG_WRITE)) < 0) {
		cerr << "Cannot open output: "
			<< av_make_error_string(errorLog, 128, errorStatus) << endl;
		return -1;
	}

	if (avformat_write_header(m_formatContext, NULL) < 0) {
		cerr << "Cannot write header to stream: "
			<< av_make_error_string(errorLog, 128, errorStatus) << endl;
		return -1;
	}

	cout << "All done." << endl;

	return 0;