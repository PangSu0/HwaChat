#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

namespace HwaChat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;

	int showMyCamera();

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
			this->SuspendLayout();
			// 
			// btnMyCameraON
			// 
			this->btnMyCameraON->Location = System::Drawing::Point(26, 105);
			this->btnMyCameraON->Name = L"btnMyCameraON";
			this->btnMyCameraON->Size = System::Drawing::Size(105, 42);
			this->btnMyCameraON->TabIndex = 0;
			this->btnMyCameraON->Text = L"카메라ON";
			this->btnMyCameraON->UseVisualStyleBackColor = true;
			this->btnMyCameraON->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// btnMyCameraOFF
			// 
			this->btnMyCameraOFF->Location = System::Drawing::Point(178, 105);
			this->btnMyCameraOFF->Name = L"btnMyCameraOFF";
			this->btnMyCameraOFF->Size = System::Drawing::Size(105, 42);
			this->btnMyCameraOFF->TabIndex = 1;
			this->btnMyCameraOFF->Text = L"종료(&E)";
			this->btnMyCameraOFF->UseVisualStyleBackColor = true;
			this->btnMyCameraOFF->Click += gcnew System::EventHandler(this, &MyForm::BtnMyCameraOFF_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(325, 251);
			this->Controls->Add(this->btnMyCameraOFF);
			this->Controls->Add(this->btnMyCameraON);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		showMyCamera();
	}
	private: System::Void BtnMyCameraOFF_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
};
	int showMyCamera()
	{
		Mat frame;
		VideoCapture cap;

		int deviceID = 0;
		int apiID = cv::CAP_ANY;

		cap.open(deviceID + apiID);

		//CascadeClassifier face_classifier;
		//face_classifier.load("C:\opencv\sources\data\haarcascades\haarcascade_frontalface_default.xml");

		if (!cap.isOpened()) {
			cerr << "ERROR! Unable to open camera\n";
			return -1;
		}

		for (;;) 
		{
			//bool frame_valid = true;
			cap.read(frame);
			cap >> frame;
			if (frame.empty()) {
				cerr << "ERROR! blank frame grabbed\n";
				//frame_valid = false;
				break;
			}
			/*if (frame_valid) {
				try {
					Mat grayframe;
					cvtColor(frame, grayframe, COLOR_BGR2GRAY);
					equalizeHist(grayframe, grayframe);

					vector<Rect> faces;

					face_classifier.detectMultiScale(grayframe, faces, 1.1, 3, CASCADE_FIND_BIGGEST_OBJECT | CASCADE_SCALE_IMAGE, cv::Size(30, 30));

					for (int i = 0; i < faces.size(); i++) {
						cv::Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
						cv::Point tr(faces[i].x, faces[i].y);

						cv::rectangle(frame, lb, tr, cv::Scalar(0, 255, 0), 3, 4, 0);
					}

					imshow("Live", frame);
				}catch(cv::Exception& e){
					cerr << "Exception occurred. Ignoring frame... " << e.err << endl;
				}
			}*/
			imshow("Live", frame);
			if (waitKey(30) >= 0)
				break;
		}
		return 0;
	}
}
