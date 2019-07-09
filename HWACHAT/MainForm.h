#pragma once
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/videoio.hpp>
#include "Header.h"

namespace HWACHAT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace std;
	using namespace defCamera;

	camera abc;
	Mat frame;
	VideoCapture cam;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::PictureBox^ picCam;
	private: System::Windows::Forms::Button^ btnPlay;



	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->picCam = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->BeginInit();
			this->SuspendLayout();
			// 
			// picCam
			// 
			this->picCam->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->picCam->Location = System::Drawing::Point(12, 12);
			this->picCam->Name = L"picCam";
			this->picCam->Size = System::Drawing::Size(702, 384);
			this->picCam->TabIndex = 2;
			this->picCam->TabStop = false;
			// 
			// btnPlay
			// 
			this->btnPlay->Location = System::Drawing::Point(998, 12);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(250, 87);
			this->btnPlay->TabIndex = 3;
			this->btnPlay->Text = L"button1";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MainForm::btnPlay_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(1260, 745);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->picCam);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	int LiveCam()
	{
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
			//imshow("Live", frame);
			picCam->Image = abc.Show(frame);
			if (waitKey(5) >= 0)
				break;
			}
		return 0;
		}

	private: System::Void btnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
		LiveCam();
	}
	};
}


