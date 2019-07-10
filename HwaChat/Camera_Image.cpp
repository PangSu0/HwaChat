#include <iostream>
#include <opencv2\opencv.hpp>
#include "Header.h"

using namespace cv;
using namespace std;
using namespace defCamera;

String nestedCascade_name;
String face_cascade_name;
CascadeClassifier face_cascade, nestedCascade;
vector<Rect> faces;

Camera::Camera(){
}
System::Drawing::Bitmap^ Camera::Show(cv::Mat& colorImage) {
	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ image;
	
	Mat frame_gray;
	
	face_cascade_name = "haarcascade_frontalface_alt.xml";
	if (!face_cascade.load(face_cascade_name)) { exit(0); }

	cvtColor(colorImage, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(colorImage, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(3, 3));

	for (size_t i = 0; i < faces.size(); i++){
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(colorImage, center, Size(faces[i].width / 2, faces[i].height / 2),
			0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);
	}

    image = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);

	return image;
}
System::Drawing::Bitmap^ Camera::Cat(Mat& colorImage) {
	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ image;

	Mat cat = imread("CatEars.png", IMREAD_UNCHANGED);
	if (cat.empty()) { exit(0); }
	face_cascade_name = "haarcascade_frontalface_default.xml";
	if (!face_cascade.load(face_cascade_name)) {exit(0);}

	face_cascade.detectMultiScale(colorImage, faces);

	for (Rect face : faces) {
		float fx = float(face.width) / cat.cols;

		Mat tmp;
		resize(cat, tmp, Size(), fx, fx);
		
		Point pos(face.x, face.y - face.height / 3);

		int sx = std::max(pos.x, 0);
		int sy = std::max(pos.y, 0);
		int ex = std::min(pos.x + tmp.cols, colorImage.cols);
		int ey = std::min(pos.y + tmp.rows, colorImage.rows);

		for (int y = sy; y < ey; y++) {
			int y2 = y - pos.y; 

			Vec3b* pSrc = colorImage.ptr<Vec3b>(y);
			const Vec4b* pOvr = tmp.ptr<Vec4b>(y2);

			for (int x = sx; x < ex; x++) {
				int x2 = x - pos.x;

				float alpha = (float)pOvr[x2][3] / 255.f;

				if (alpha > 0.f) {
					pSrc[x][0] = saturate_cast<uchar>(pSrc[x][0] * (1.f - alpha)
						+ pOvr[x2][0] * alpha);
					pSrc[x][1] = saturate_cast<uchar>(pSrc[x][1] * (1.f - alpha)
						+ pOvr[x2][1] * alpha);
					pSrc[x][2] = saturate_cast<uchar>(pSrc[x][2] * (1.f - alpha)
						+ pOvr[x2][2] * alpha);
				}
			}
		}

	}
	image = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
		System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);

	return image;
}
System::Drawing::Bitmap^ Camera::Glasses(Mat& colorImage) {
	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ image;

	Mat glasses = imread("glasses.png", IMREAD_UNCHANGED);
	if (glasses.empty()) { exit(0); }
	double scale = 1.0;

	nestedCascade_name = "haarcascade_eye_tree_eyeglasses.xml";
	if (!nestedCascade.load(nestedCascade_name)) { exit(0); }
	face_cascade_name = "haarcascade_frontalface_alt.xml";
	if (!face_cascade.load(face_cascade_name)) { exit(0); }

	double t = 0;
	const static Scalar colors[] = {Scalar(255,0,0),Scalar(255,128,0),Scalar(255,255,0),Scalar(0,255,0),Scalar(0,128,255),Scalar(0,255,255),Scalar(0,0,255),Scalar(255,0,255)};
	Mat gray, smallImg;

	cvtColor(colorImage, gray, COLOR_BGR2GRAY);
	double fx = 1 / scale;
	resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);
	equalizeHist(smallImg, smallImg);

	t = (double)getTickCount();
	face_cascade.detectMultiScale(smallImg, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
	t = (double)getTickCount() - t;

	Mat result;

	for (size_t i = 0; i < faces.size(); i++){
		Rect r = faces[i];
		Mat smallImgROI;
		vector<Rect> nestedObjects;
		Point center;
		Scalar color = colors[i % 8];
		int radius;

		double aspect_ratio = (double)r.width / r.height;

		if (0.75 < aspect_ratio && aspect_ratio < 1.3){
			center.x = cvRound((r.x + r.width * 0.5) * scale);
			center.y = cvRound((r.y + r.height * 0.5) * scale);
			radius = cvRound((r.width + r.height) * 0.25 * scale);
			//circle(colorImage, center, radius, color, 3, 8, 0);
		}else
			rectangle(colorImage, Point(cvRound(r.x * scale), cvRound(r.y * scale)),
				Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
				color, 3, 8, 0);
		if (nestedCascade.empty()) { exit(0); }

		smallImgROI = smallImg(r);
		nestedCascade.detectMultiScale(smallImgROI, nestedObjects, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(20, 20));

		vector<Point> points;
		
		for (size_t j = 0; j < nestedObjects.size(); j++){
			Rect nr = nestedObjects[j];
			center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
			center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
			radius = cvRound((nr.width + nr.height) * 0.25 * scale);
			//circle(colorImage, center, radius, color, 3, 8, 0);

			Point p(center.x, center.y);
			points.push_back(p);
		}

		if (points.size() == 2) {
			Point center1 = points[0];
			Point center2 = points[1];

			if (center1.x > center2.x) {
				Point temp;
				temp = center1;
				center1 = center2;
				center2 = temp;
			}

			int width = abs(center2.x - center1.x);
			int height = abs(center2.y - center1.y);

			if (width > height) {
				float imgScale = width / 330.0;

				int w, h;
				w = glasses.cols * imgScale * 0.8;
				h = glasses.rows * imgScale * 0.8;
				
				int offsetX = 150 * imgScale + 25;
				int offsetY = 160 * imgScale;

				Mat resized_glasses;
				resize(glasses, resized_glasses, cv::Size(w, h), 0, 0);

				Point2i location = Point(center1.x - offsetX, center1.y - offsetY);

				int sx = std::max(location.x, 0);
				int sy = std::max(location.y, 0);
				int ex = std::min(location.x + resized_glasses.cols, colorImage.cols);
				int ey = std::min(location.y + resized_glasses.rows, colorImage.rows);

				for (int y = sy; y < ey; y++) {
					int y2 = y - location.y;

					Vec3b* pSrc = colorImage.ptr<Vec3b>(y);
					const Vec4b* pOvr = resized_glasses.ptr<Vec4b>(y2);

					for (int x = sx; x < ex; x++) {
						int x2 = x - location.x;

						float alpha = (float)pOvr[x2][3] / 255.f;

						if (alpha > 0.f) {
							pSrc[x][0] = saturate_cast<uchar>(pSrc[x][0] * (1.f - alpha)
								+ pOvr[x2][0] * alpha);
							pSrc[x][1] = saturate_cast<uchar>(pSrc[x][1] * (1.f - alpha)
								+ pOvr[x2][1] * alpha);
							pSrc[x][2] = saturate_cast<uchar>(pSrc[x][2] * (1.f - alpha)
								+ pOvr[x2][2] * alpha);
						}
					}
				}
			}
		}
	}
	image = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
		System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);

	return image;
}