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

	Camera camera;
	Mat frame;
	VideoCapture cap;

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

	private: System::Windows::Forms::Button^ btnMyCameraOFF;
	private: System::Windows::Forms::PictureBox^ picCam;
	private: System::Windows::Forms::Button^ btnPlay;
	private: System::Windows::Forms::Button^ btnSunglasses;
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
			this->btnMyCameraOFF = (gcnew System::Windows::Forms::Button());
			this->picCam = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->btnSunglasses = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->BeginInit();
			this->SuspendLayout();
			// 
			// btnMyCameraOFF
			// 
			this->btnMyCameraOFF->Location = System::Drawing::Point(115, 389);
			this->btnMyCameraOFF->Name = L"btnMyCameraOFF";
			this->btnMyCameraOFF->Size = System::Drawing::Size(97, 32);
			this->btnMyCameraOFF->TabIndex = 1;
			this->btnMyCameraOFF->Text = L"종료";
			this->btnMyCameraOFF->UseVisualStyleBackColor = true;
			this->btnMyCameraOFF->Click += gcnew System::EventHandler(this, &MyForm::BtnMyCameraOFF_Click);
			// 
			// picCam
			// 
			this->picCam->Location = System::Drawing::Point(12, 12);
			this->picCam->Name = L"picCam";
			this->picCam->Size = System::Drawing::Size(655, 371);
			this->picCam->TabIndex = 2;
			this->picCam->TabStop = false;
			// 
			// btnPlay
			// 
			this->btnPlay->Location = System::Drawing::Point(12, 389);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(97, 32);
			this->btnPlay->TabIndex = 3;
			this->btnPlay->Text = L"Start";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MyForm::BtnPlay_Click);
			// 
			// btnSunglasses
			// 
			this->btnSunglasses->Location = System::Drawing::Point(218, 389);
			this->btnSunglasses->Name = L"btnSunglasses";
			this->btnSunglasses->Size = System::Drawing::Size(97, 32);
			this->btnSunglasses->TabIndex = 4;
			this->btnSunglasses->Text = L"sunglasses";
			this->btnSunglasses->UseVisualStyleBackColor = true;
			this->btnSunglasses->Click += gcnew System::EventHandler(this, &MyForm::BtnSunglasses_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 430);
			this->Controls->Add(this->btnSunglasses);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->picCam);
			this->Controls->Add(this->btnMyCameraOFF);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->EndInit();
			this->ResumeLayout(false);

		}

		// winform에서 내 화면 띄우기
		int showMyCamera(){

			int deviceID = 0;             // 0 = open default camera
			int apiID = cv::CAP_ANY;      // 0 = autodetect default API
			cap.open(deviceID + apiID);
			
			for (;;){
				cap.read(frame);
				if (frame.empty()) {
					cerr << "ERROR! blank frame grabbed\n";
					break;
				}
				picCam->Image = camera.Show(frame);
				if (waitKey(5) >= 0) break;
			}
			return 0;
		}
	private: System::Void BtnMyCameraOFF_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
    private: System::Void BtnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
		showMyCamera();
    }
	private: System::Void BtnSunglasses_Click(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
