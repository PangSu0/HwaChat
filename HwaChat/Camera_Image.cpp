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
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n");  };

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
//System::Drawing::Bitmap^ Sunglasses(Mat& colorImage) {

//}