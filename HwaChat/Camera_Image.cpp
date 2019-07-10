#include <iostream>
#include <opencv2\opencv.hpp>
#include "Header.h"

using namespace cv;
using namespace std;
using namespace defCamera;

String face_cascade_name;
CascadeClassifier face_cascade;
vector<Rect> faces;
Mat frame_gray;

Camera::Camera(){
}
System::Drawing::Bitmap^ Camera::Show(cv::Mat& colorImage) {
	System::IntPtr ptr(colorImage.ptr());
	System::Drawing::Bitmap^ image;

	face_cascade_name = "haarcascade_frontalface_alt.xml";
	if (!face_cascade.load(face_cascade_name)) { exit(0); };

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
	CascadeClassifier face_cascade("haarcascade_frontalface_default.xml");

	if (face_cascade.empty()) {exit(0);	}

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
			int y2 = y - pos.y; // y coordinate in overlay image

			Vec3b* pSrc = colorImage.ptr<Vec3b>(y);
			const Vec4b* pOvr = tmp.ptr<Vec4b>(y2);

			for (int x = sx; x < ex; x++) {
				int x2 = x - pos.x; // x coordinate in overlay image

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