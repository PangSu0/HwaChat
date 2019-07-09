#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "Header.h"

namespace HwaChat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std; 
	using namespace defCamera;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnMyCameraON;
	private: System::Windows::Forms::Button^ btnMyCameraOFF;
	private: System::Windows::Forms::PictureBox^ picCam;
	private: System::Windows::Forms::Button^ btnPlay;
	protected:


	protected:

	protected:

	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnMyCameraON = (gcnew System::Windows::Forms::Button());
			this->btnMyCameraOFF = (gcnew System::Windows::Forms::Button());
			this->picCam = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->BeginInit();
			this->SuspendLayout();
			// 
			// btnMyCameraON
			// 
			this->btnMyCameraON->Location = System::Drawing::Point(12, 12);
			this->btnMyCameraON->Name = L"btnMyCameraON";
			this->btnMyCameraON->Size = System::Drawing::Size(105, 42);
			this->btnMyCameraON->TabIndex = 0;
			this->btnMyCameraON->Text = L"카메라ON";
			this->btnMyCameraON->UseVisualStyleBackColor = true;
			this->btnMyCameraON->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// btnMyCameraOFF
			// 
			this->btnMyCameraOFF->Location = System::Drawing::Point(167, 12);
			this->btnMyCameraOFF->Name = L"btnMyCameraOFF";
			this->btnMyCameraOFF->Size = System::Drawing::Size(105, 42);
			this->btnMyCameraOFF->TabIndex = 1;
			this->btnMyCameraOFF->Text = L"종료(&E)";
			this->btnMyCameraOFF->UseVisualStyleBackColor = true;
			this->btnMyCameraOFF->Click += gcnew System::EventHandler(this, &MyForm::BtnMyCameraOFF_Click);
			// 
			// picCam
			// 
			this->picCam->Location = System::Drawing::Point(12, 103);
			this->picCam->Name = L"picCam";
			this->picCam->Size = System::Drawing::Size(475, 336);
			this->picCam->TabIndex = 2;
			this->picCam->TabStop = false;
			// 
			// btnPlay
			// 
			this->btnPlay->Location = System::Drawing::Point(502, 103);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(97, 32);
			this->btnPlay->TabIndex = 3;
			this->btnPlay->Text = L"Start";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MyForm::BtnPlay_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(611, 451);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->picCam);
			this->Controls->Add(this->btnMyCameraOFF);
			this->Controls->Add(this->btnMyCameraON);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->EndInit();
			this->ResumeLayout(false);

		}
		int showMyCamera()
		{
			camera abc;
			Mat frame;
			VideoCapture cam;

			VideoCapture cap;
			int deviceID = 0;             // 0 = open default camera
			int apiID = cv::CAP_ANY;      // 0 = autodetect default API
			cap.open(deviceID + apiID);
			if (!cap.isOpened()) {
				cerr << "ERROR! Unable to open camera\n";
				return -1;
			}
			cout << "Start grabbing" << endl
				<< "Press any key to terminate" << endl;
			for (;;)
			{
				cap.read(frame);
				if (frame.empty()) {
					cerr << "ERROR! blank frame grabbed\n";
					break;
				}

				picCam->Image = abc.Show(frame);
				if (waitKey(5) >= 0)
					break;
			}
			return 0;
		}
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//showMyCamera();
	}
	private: System::Void BtnMyCameraOFF_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
    private: System::Void BtnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
		showMyCamera();
    }
    };
	//void detectAndDraw(Mat& img, CascadeClassifier& cascade,
	//	CascadeClassifier& nestedCascade,
	//	double scale, bool tryflip, Mat glasses)
	//{

	//	Mat output2;
	//	img.copyTo(output2);

	//	double t = 0;
	//	vector<Rect> faces, faces2;
	//	const static Scalar colors[] =
	//	{
	//		Scalar(255,0,0),
	//		Scalar(255,128,0),
	//		Scalar(255,255,0),
	//		Scalar(0,255,0),
	//		Scalar(0,128,255),
	//		Scalar(0,255,255),
	//		Scalar(0,0,255),
	//		Scalar(255,0,255)
	//	};
	//	Mat gray, smallImg;

	//	cvtColor(img, gray, COLOR_BGR2GRAY);
	//	double fx = 1 / scale;
	//	resize(gray, smallImg, cv::Size(), fx, fx, INTER_LINEAR_EXACT);
	//	equalizeHist(smallImg, smallImg);

	//	t = (double)getTickCount();
	//	cascade.detectMultiScale(smallImg, faces,
	//		1.1, 2, 0
	//		//|CASCADE_FIND_BIGGEST_OBJECT
	//		//|CASCADE_DO_ROUGH_SEARCH
	//		| CASCADE_SCALE_IMAGE,
	//		cv::Size(30, 30));

	//	t = (double)getTickCount() - t;

	//	Mat result;

	//	printf("detection time = %g ms\n", t * 1000 / getTickFrequency());
	//	for (size_t i = 0; i < faces.size(); i++)
	//	{
	//		Rect r = faces[i];
	//		Mat smallImgROI;
	//		vector<Rect> nestedObjects;
	//		cv::Point center;
	//		Scalar color = colors[i % 8];
	//		int radius;



	//		double aspect_ratio = (double)r.width / r.height;

	//		if (0.75 < aspect_ratio && aspect_ratio < 1.3)
	//		{
	//			center.x = cvRound((r.x + r.width * 0.5) * scale);
	//			center.y = cvRound((r.y + r.height * 0.5) * scale);
	//			radius = cvRound((r.width + r.height) * 0.25 * scale);
	//			circle(img, center, radius, color, 3, 8, 0);
	//		}
	//		else
	//			rectangle(img, cv::Point(cvRound(r.x * scale), cvRound(r.y * scale)),
	//				cv::Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
	//				color, 3, 8, 0);
	//		if (nestedCascade.empty()) {
	//			cout << "nestedCascade.empty()" << endl;
	//			continue;
	//		}

	//		smallImgROI = smallImg(r);
	//		nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
	//			1.1, 2, 0
	//			//|CASCADE_FIND_BIGGEST_OBJECT
	//			//|CASCADE_DO_ROUGH_SEARCH
	//			//|CASCADE_DO_CANNY_PRUNING
	//			| CASCADE_SCALE_IMAGE,
	//			cv::Size(20, 20));


	//		cout << nestedObjects.size() << endl;

	//		vector<cv::Point> points;

	//		for (size_t j = 0; j < nestedObjects.size(); j++)
	//		{
	//			Rect nr = nestedObjects[j];
	//			center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
	//			center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
	//			radius = cvRound((nr.width + nr.height) * 0.25 * scale);
	//			circle(img, center, radius, color, 3, 8, 0);

	//			cv::Point p(center.x, center.y);
	//			points.push_back(p);
	//		}


	//		if (points.size() == 2) {

	//			cv::Point center1 = points[0];
	//			cv::Point center2 = points[1];

	//			if (center1.x > center2.x) {
	//				cv::Point temp;
	//				temp = center1;
	//				center1 = center2;
	//				center2 = temp;
	//			}


	//			int width = abs(center2.x - center1.x);
	//			int height = abs(center2.y - center1.y);

	//			if (width > height) {

	//				float imgScale = width / 330.0;

	//				int w, h;
	//				w = glasses.cols * imgScale;
	//				h = glasses.rows * imgScale;

	//				int offsetX = 150 * imgScale;
	//				int offsetY = 160 * imgScale;

	//				Mat resized_glasses;
	//				resize(glasses, resized_glasses, cv::Size(w, h), 0, 0);

	//				overlayImage(output2, resized_glasses, result, cv::Point(center1.x - offsetX, center1.y - offsetY));
	//				output2 = result;
	//			}
	//		}
	//	}

	//	if (result.empty())
	//		imshow("result", img);
	//	else
	//		imshow("result", result);

	//}


	//void overlayImage(const Mat & background, const Mat & foreground,
	//	Mat & output, Point2i location)
	//{
	//	background.copyTo(output);


	//	// start at the row indicated by location, or at row 0 if location.y is negative.
	//	for (int y = std::max(location.y, 0); y < background.rows; ++y)
	//	{
	//		int fY = y - location.y; // because of the translation

	//		// we are done of we have processed all rows of the foreground image.
	//		if (fY >= foreground.rows) {
	//			break;
	//		}

	//		// start at the column indicated by location, 

	//		// or at column 0 if location.x is negative.
	//		for (int x = std::max(location.x, 0); x < background.cols; ++x)
	//		{
	//			int fX = x - location.x; // because of the translation.

	//									 // we are done with this row if the column is outside of the foreground image.
	//			if (fX >= foreground.cols) {
	//				break;
	//			}

	//			// determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
	//			double opacity =
	//				((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3])

	//				/ 255.;


	//			// and now combine the background and foreground pixel, using the opacity, 

	//			// but only if opacity > 0.
	//			for (int c = 0; opacity > 0 && c < output.channels(); ++c)
	//			{
	//				unsigned char foregroundPx =
	//					foreground.data[fY * foreground.step + fX * foreground.channels() + c];
	//				unsigned char backgroundPx =
	//					background.data[y * background.step + x * background.channels() + c];
	//				output.data[y * output.step + output.channels() * x + c] =
	//					backgroundPx * (1. - opacity) + foregroundPx * opacity;
	//			}
	//		}
	//	}
	//}


}
