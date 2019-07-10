#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;



void detectAndDraw(Mat& img, CascadeClassifier& cascade,
	CascadeClassifier& nestedCascade,
	double scale, bool tryflip, Mat glasses);
void overlayImage(const Mat& background, const Mat& foreground,
	Mat& output, Point2i location);

string cascadeName;
string nestedCascadeName;

int main(int argc, const char** argv)
{
	VideoCapture capture;
	Mat frame, image, glasses;

	//얼굴 이미지
	//테스트용
	string inputName;// = "face6.png";

	//선글라스 이미지
	//필요한 모든 외부파일은 소스파일이 존재하는 폴더 안에 있어야 함
	string glassesImage = "sunglasses.png"; 
	bool tryflip = true;
	CascadeClassifier cascade, nestedCascade;
	double scale;

	scale = 1;

	glasses = imread(glassesImage, IMREAD_UNCHANGED);
	if (glasses.empty()) {

		cout << "Could not read image - " << glassesImage << endl;
		return -1;
	}

	//얼굴과 눈을 훈련시킨 XML 파일
	//XML 파일은 opencv-4.1.0 > source > data > haarcascades 에서 복사
	/*if (!nestedCascade.load(samples::findFileOrKeep("haarcascade_eye_tree_eyeglasses.xml")))
		cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;*/
	if (!cascade.load(samples::findFile("haarcascade_frontalface_alt.xml")))
	{
		cerr << "ERROR: Could not load classifier cascade" << endl;
		return -1;
	}
	if (inputName.empty() || (isdigit(inputName[0]) && inputName.size() == 1))
	{
		int camera = inputName.empty() ? 0 : inputName[0] - '0';
		if (!capture.open(camera))
		{
			cout << "Capture from camera #" << camera << " didn't work" << endl;
			return 1;
		}
	}

	////이미지를 불러 온 경우 얼굴을 검출하는 소스코드
	//else if (!inputName.empty())
	//{
	//	image = imread(samples::findFileOrKeep(inputName), IMREAD_COLOR);
	//	if (image.empty())
	//	{
	//		if (!capture.open(samples::findFileOrKeep(inputName)))
	//		{
	//			cout << "Could not read " << inputName << endl;
	//			return 1;
	//		}
	//	}

	//	detectAndDraw(image, cascade, nestedCascade, scale, tryflip, glasses);

	//	waitKey(0);
	//}

	//영상으로부터 얼굴 검출
	if (capture.isOpened())
	{
		cout << "Video capturing has been started ..." << endl;

		for (;;)
		{
			capture >> frame;
			if (frame.empty())
				break;

			Mat frame1 = frame.clone();
			detectAndDraw(frame1, cascade, nestedCascade, scale, tryflip, glasses);

			char c = (char)waitKey(10);
			if (c == 27 || c == 'q' || c == 'Q')
				break;
		}
	}

	return 0;
}

//입력으로 이미지 또는 영상을 사용한 경우 얼굴 검출을 위해 사용하는 함수
void detectAndDraw(Mat & img, CascadeClassifier & cascade,
	CascadeClassifier & nestedCascade,
	double scale, bool tryflip, Mat glasses)
{
	//결과를 보여줄 때 사용하기 위해 원본이미지 복사
	Mat output2;
	img.copyTo(output2);

	double t = 0;
	vector<Rect> faces, faces2;
	const static Scalar colors[] =
	{
		Scalar(255,0,0),
		Scalar(255,128,0),
		Scalar(255,255,0),
		Scalar(0,255,0),
		Scalar(0,128,255),
		Scalar(0,255,255),
		Scalar(0,0,255),
		Scalar(255,0,255)
	};
	Mat gray, smallImg;

	cvtColor(img, gray, COLOR_BGR2GRAY);
	double fx = 1 / scale;
	resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);
	equalizeHist(smallImg, smallImg);

	t = (double)getTickCount();
	//얼굴위치 검출
	cascade.detectMultiScale(smallImg, faces,
		1.1, 2, 0
		//|CASCADE_FIND_BIGGEST_OBJECT
		//|CASCADE_DO_ROUGH_SEARCH
		| CASCADE_SCALE_IMAGE,
		Size(30, 30));

	t = (double)getTickCount() - t;

	Mat result;

	//변수 r에 얼굴 위치를 저장하여 사용
	printf("detection time = %g ms\n", t * 1000 / getTickFrequency());
	for (size_t i = 0; i < faces.size(); i++)
	{
		Rect r = faces[i];
		Mat smallImgROI;
		vector<Rect> nestedObjects;
		Point center;
		Scalar color = colors[i % 8];
		int radius;



		double aspect_ratio = (double)r.width / r.height;

		//얼굴 위치에 원을 그려줌
		if (0.75 < aspect_ratio && aspect_ratio < 1.3)
		{
			center.x = cvRound((r.x + r.width * 0.5) * scale);
			center.y = cvRound((r.y + r.height * 0.5) * scale);
			radius = cvRound((r.width + r.height) * 0.25 * scale);
			circle(img, center, radius, color, 3, 8, 0);
		}
		else
			rectangle(img, Point(cvRound(r.x * scale), cvRound(r.y * scale)),
				Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
				color, 3, 8, 0);
		if (nestedCascade.empty()) {
			cout << "nestedCascade.empty()" << endl;
			continue;
		}

		//얼굴 내부 영역에서 눈 위치 검출
		//smallImgROI = smallImg(r);
		//nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
		//	1.1, 2, 0
		//	//|CASCADE_FIND_BIGGEST_OBJECT
		//	//|CASCADE_DO_ROUGH_SEARCH
		//	//|CASCADE_DO_CANNY_PRUNING
		//	| CASCADE_SCALE_IMAGE,
		//	Size(20, 20));


		//cout << nestedObjects.size() << endl;

		//vector<Point> points;
		////눈 위치에 원을 그려줌
		//for (size_t j = 0; j < nestedObjects.size(); j++)
		//{
		//	Rect nr = nestedObjects[j];
		//	center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
		//	center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
		//	radius = cvRound((nr.width + nr.height) * 0.25 * scale);
		//	circle(img, center, radius, color, 3, 8, 0);

		//	Point p(center.x, center.y);
		//	points.push_back(p);
		//}

		////눈 위치가 2개로 검출 된 경우, x좌표 기준으로 정렬
		//if (points.size() == 2) {

		//	Point center1 = points[0];
		//	Point center2 = points[1];

		//	if (center1.x > center2.x) {
		//		Point temp;
		//		temp = center1;
		//		center1 = center2;
		//		center2 = temp;
		//	}

		//	//눈 위치가 아닌 경우 필터링
		//	//가로 길이와 세로 길이로 판정
		//	int width = abs(center2.x - center1.x);
		//	int height = abs(center2.y - center1.y);

		//	if (width > height) {
		//		//눈 사이 간격과 안경알 사이 간격 비율 계산
		//		float imgScale = width / 330.0;
		//		//계산한 비율로 안경 크기 조정
		//		int w, h;
		//		w = glasses.cols * imgScale * 2;
		//		h = glasses.rows * imgScale * 2;
		//		//오른쪽 안경알을 중심으로 안경의 위치 조정
		//		int offsetX = 150 * imgScale;
		//		int offsetY = 160 * imgScale;

		//		Mat resized_glasses;
		//		resize(glasses, resized_glasses, cv::Size(w, h), 0, 0);
		//		//얼굴 이미지에 안경 이미지 오버랩
		//		overlayImage(output2, resized_glasses, result, Point(center1.x - offsetX, center1.y - offsetY));
		//		output2 = result;
		//	}
		//}
	}

	//안경을 오버랩 못했을 경우 겸출 결과 구현
	if (result.empty())
		imshow("result", img);
	else
		imshow("result", result);

}


void overlayImage(const Mat & background, const Mat & foreground,
	Mat & output, Point2i location)
{
	background.copyTo(output);


	// start at the row indicated by location, or at row 0 if location.y is negative.
	for (int y = std::max(location.y, 0); y < background.rows; ++y)
	{
		int fY = y - location.y; // because of the translation

		// we are done of we have processed all rows of the foreground image.
		if (fY >= foreground.rows) {
			break;
		}

		// start at the column indicated by location, 

		// or at column 0 if location.x is negative.
		for (int x = std::max(location.x, 0); x < background.cols; ++x)
		{
			int fX = x - location.x; // because of the translation.

									 // we are done with this row if the column is outside of the foreground image.
			if (fX >= foreground.cols) {
				break;
			}

			// determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
			double opacity =
				((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3])

				/ 255.;


			// and now combine the background and foreground pixel, using the opacity, 

			// but only if opacity > 0.
			for (int c = 0; opacity > 0 && c < output.channels(); ++c)
			{
				unsigned char foregroundPx =
					foreground.data[fY * foreground.step + fX * foreground.channels() + c];
				unsigned char backgroundPx =
					background.data[y * background.step + x * background.channels() + c];
				output.data[y * output.step + output.channels() * x + c] =
					backgroundPx * (1. - opacity) + foregroundPx * opacity;
			}
		}
	}
}