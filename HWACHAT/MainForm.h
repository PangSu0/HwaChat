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
	using namespace std;
	using namespace defCamera;

	//camera abc;
	//Mat frame;

	public ref class MainForm : public DevExpress::XtraEditors::XtraForm
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}
	
	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevExpress::XtraEditors::SimpleButton^ btnPlay;
	private: DevExpress::XtraEditors::SimpleButton^ btnClose;
	private: DevExpress::XtraEditors::PictureEdit^ picYourcam;

	private: DevExpress::XtraEditors::SimpleButton^ btnChat;
	private: DevExpress::XtraEditors::SimpleButton^ btnSetting;
	private: DevExpress::XtraEditors::PictureEdit^ picMycam;

	private: DevExpress::XtraBars::Navigation::TileBar^ tileBar1;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup2;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup3;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup4;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup5;
	private: DevExpress::XtraBars::Navigation::TileBarItem^ tileBarItem1;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup6;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup7;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup8;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup9;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup10;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup11;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup12;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup13;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup14;
	private: DevExpress::XtraBars::Navigation::TileBarGroup^ tileBarGroup15;
	private: DevExpress::XtraBars::Navigation::TileBarItem^ tileBarItem2;
	private: DevExpress::XtraBars::Navigation::TileBarItem^ tileBarItem3;





	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			DevExpress::XtraEditors::TileItemElement^ tileItemElement1 = (gcnew DevExpress::XtraEditors::TileItemElement());
			DevExpress::XtraEditors::TileItemElement^ tileItemElement2 = (gcnew DevExpress::XtraEditors::TileItemElement());
			DevExpress::XtraEditors::TileItemElement^ tileItemElement3 = (gcnew DevExpress::XtraEditors::TileItemElement());
			this->btnPlay = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->btnClose = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->picYourcam = (gcnew DevExpress::XtraEditors::PictureEdit());
			this->btnChat = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->btnSetting = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->picMycam = (gcnew DevExpress::XtraEditors::PictureEdit());
			this->tileBar1 = (gcnew DevExpress::XtraBars::Navigation::TileBar());
			this->tileBarGroup2 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarItem2 = (gcnew DevExpress::XtraBars::Navigation::TileBarItem());
			this->tileBarGroup3 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup4 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup5 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarItem1 = (gcnew DevExpress::XtraBars::Navigation::TileBarItem());
			this->tileBarGroup6 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup7 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup8 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarItem3 = (gcnew DevExpress::XtraBars::Navigation::TileBarItem());
			this->tileBarGroup9 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup10 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup11 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup12 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup13 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup14 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			this->tileBarGroup15 = (gcnew DevExpress::XtraBars::Navigation::TileBarGroup());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picYourcam->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMycam->Properties))->BeginInit();
			this->SuspendLayout();
			// 
			// btnPlay
			// 
			this->btnPlay->ImageOptions->ImageToTextAlignment = DevExpress::XtraEditors::ImageAlignToText::TopCenter;
			this->btnPlay->ImageOptions->SvgImage = (cli::safe_cast<DevExpress::Utils::Svg::SvgImage^>(resources->GetObject(L"btnPlay.ImageOptions.SvgImage")));
			this->btnPlay->Location = System::Drawing::Point(658, 320);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(52, 45);
			this->btnPlay->TabIndex = 0;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MainForm::btnPlay_Click);
			// 
			// btnClose
			// 
			this->btnClose->ImageOptions->ImageToTextAlignment = DevExpress::XtraEditors::ImageAlignToText::TopCenter;
			this->btnClose->ImageOptions->SvgImage = (cli::safe_cast<DevExpress::Utils::Svg::SvgImage^>(resources->GetObject(L"btnClose.ImageOptions.SvgImage")));
			this->btnClose->Location = System::Drawing::Point(716, 320);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(52, 45);
			this->btnClose->TabIndex = 1;
			this->btnClose->Click += gcnew System::EventHandler(this, &MainForm::btnClose_Click);
			// 
			// picYourcam
			// 
			this->picYourcam->EditValue = (cli::safe_cast<System::Object^>(resources->GetObject(L"picYourcam.EditValue")));
			this->picYourcam->Location = System::Drawing::Point(12, 12);
			this->picYourcam->Name = L"picYourcam";
			this->picYourcam->Properties->InitialImageOptions->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picYourcam.Properties.InitialImageOptions.Image")));
			this->picYourcam->Properties->ShowCameraMenuItem = DevExpress::XtraEditors::Controls::CameraMenuItemVisibility::Auto;
			this->picYourcam->Size = System::Drawing::Size(640, 480);
			this->picYourcam->TabIndex = 2;
			// 
			// btnChat
			// 
			this->btnChat->Appearance->Font = (gcnew System::Drawing::Font(L"Poor Richard", 35));
			this->btnChat->Appearance->Options->UseFont = true;
			this->btnChat->Location = System::Drawing::Point(657, 371);
			this->btnChat->Name = L"btnChat";
			this->btnChat->Size = System::Drawing::Size(349, 121);
			this->btnChat->TabIndex = 3;
			this->btnChat->Text = L"Chat";
			this->btnChat->Click += gcnew System::EventHandler(this, &MainForm::SimpleButton1_Click);
			// 
			// btnSetting
			// 
			this->btnSetting->ImageOptions->ImageToTextAlignment = DevExpress::XtraEditors::ImageAlignToText::BottomCenter;
			this->btnSetting->ImageOptions->SvgImage = (cli::safe_cast<DevExpress::Utils::Svg::SvgImage^>(resources->GetObject(L"btnSetting.ImageOptions.SvgImage")));
			this->btnSetting->Location = System::Drawing::Point(954, 320);
			this->btnSetting->Name = L"btnSetting";
			this->btnSetting->Size = System::Drawing::Size(52, 45);
			this->btnSetting->TabIndex = 4;
			this->btnSetting->Click += gcnew System::EventHandler(this, &MainForm::BtnSetting_Click);
			// 
			// picMycam
			// 
			this->picMycam->EditValue = (cli::safe_cast<System::Object^>(resources->GetObject(L"picMycam.EditValue")));
			this->picMycam->Location = System::Drawing::Point(658, 12);
			this->picMycam->Name = L"picMycam";
			this->picMycam->Properties->ShowCameraMenuItem = DevExpress::XtraEditors::Controls::CameraMenuItemVisibility::Auto;
			this->picMycam->Size = System::Drawing::Size(348, 302);
			this->picMycam->TabIndex = 5;
			// 
			// tileBar1
			// 
			this->tileBar1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tileBar1->DropDownOptions->BeakColor = System::Drawing::Color::Empty;
			this->tileBar1->Groups->Add(this->tileBarGroup2);
			this->tileBar1->Groups->Add(this->tileBarGroup3);
			this->tileBar1->Groups->Add(this->tileBarGroup4);
			this->tileBar1->Groups->Add(this->tileBarGroup5);
			this->tileBar1->Groups->Add(this->tileBarGroup6);
			this->tileBar1->Groups->Add(this->tileBarGroup7);
			this->tileBar1->Groups->Add(this->tileBarGroup8);
			this->tileBar1->Groups->Add(this->tileBarGroup9);
			this->tileBar1->Groups->Add(this->tileBarGroup10);
			this->tileBar1->Groups->Add(this->tileBarGroup11);
			this->tileBar1->Groups->Add(this->tileBarGroup12);
			this->tileBar1->Groups->Add(this->tileBarGroup13);
			this->tileBar1->Groups->Add(this->tileBarGroup14);
			this->tileBar1->Groups->Add(this->tileBarGroup15);
			this->tileBar1->Location = System::Drawing::Point(0, 506);
			this->tileBar1->MaxId = 5;
			this->tileBar1->Name = L"tileBar1";
			this->tileBar1->ScrollMode = DevExpress::XtraEditors::TileControlScrollMode::ScrollButtons;
			this->tileBar1->Size = System::Drawing::Size(1018, 101);
			this->tileBar1->TabIndex = 6;
			this->tileBar1->Text = L"tileBar1";
			// 
			// tileBarGroup2
			// 
			this->tileBarGroup2->Items->Add(this->tileBarItem2);
			this->tileBarGroup2->Name = L"tileBarGroup2";
			// 
			// tileBarItem2
			// 
			this->tileBarItem2->DropDownOptions->BeakColor = System::Drawing::Color::Empty;
			tileItemElement1->ImageOptions->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"resource.Image")));
			tileItemElement1->ImageOptions->ImageScaleMode = DevExpress::XtraEditors::TileItemImageScaleMode::ZoomInside;
			tileItemElement1->Text = L"";
			this->tileBarItem2->Elements->Add(tileItemElement1);
			this->tileBarItem2->Id = 3;
			this->tileBarItem2->ItemSize = DevExpress::XtraBars::Navigation::TileBarItemSize::Medium;
			this->tileBarItem2->Name = L"tileBarItem2";
			// 
			// tileBarGroup3
			// 
			this->tileBarGroup3->Name = L"tileBarGroup3";
			// 
			// tileBarGroup4
			// 
			this->tileBarGroup4->Name = L"tileBarGroup4";
			// 
			// tileBarGroup5
			// 
			this->tileBarGroup5->Items->Add(this->tileBarItem1);
			this->tileBarGroup5->Name = L"tileBarGroup5";
			// 
			// tileBarItem1
			// 
			this->tileBarItem1->DropDownOptions->BeakColor = System::Drawing::Color::Empty;
			tileItemElement2->ImageOptions->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"resource.Image1")));
			tileItemElement2->ImageOptions->ImageScaleMode = DevExpress::XtraEditors::TileItemImageScaleMode::ZoomInside;
			tileItemElement2->Text = L"";
			this->tileBarItem1->Elements->Add(tileItemElement2);
			this->tileBarItem1->Id = 0;
			this->tileBarItem1->ItemSize = DevExpress::XtraBars::Navigation::TileBarItemSize::Medium;
			this->tileBarItem1->Name = L"tileBarItem1";
			// 
			// tileBarGroup6
			// 
			this->tileBarGroup6->Name = L"tileBarGroup6";
			// 
			// tileBarGroup7
			// 
			this->tileBarGroup7->Name = L"tileBarGroup7";
			// 
			// tileBarGroup8
			// 
			this->tileBarGroup8->Items->Add(this->tileBarItem3);
			this->tileBarGroup8->Name = L"tileBarGroup8";
			// 
			// tileBarItem3
			// 
			this->tileBarItem3->DropDownOptions->BeakColor = System::Drawing::Color::Empty;
			tileItemElement3->ImageOptions->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"resource.Image2")));
			tileItemElement3->ImageOptions->ImageScaleMode = DevExpress::XtraEditors::TileItemImageScaleMode::ZoomInside;
			tileItemElement3->Text = L"";
			this->tileBarItem3->Elements->Add(tileItemElement3);
			this->tileBarItem3->Id = 4;
			this->tileBarItem3->ItemSize = DevExpress::XtraBars::Navigation::TileBarItemSize::Medium;
			this->tileBarItem3->Name = L"tileBarItem3";
			// 
			// tileBarGroup9
			// 
			this->tileBarGroup9->Name = L"tileBarGroup9";
			// 
			// tileBarGroup10
			// 
			this->tileBarGroup10->Name = L"tileBarGroup10";
			// 
			// tileBarGroup11
			// 
			this->tileBarGroup11->Name = L"tileBarGroup11";
			// 
			// tileBarGroup12
			// 
			this->tileBarGroup12->Name = L"tileBarGroup12";
			// 
			// tileBarGroup13
			// 
			this->tileBarGroup13->Name = L"tileBarGroup13";
			// 
			// tileBarGroup14
			// 
			this->tileBarGroup14->Name = L"tileBarGroup14";
			// 
			// tileBarGroup15
			// 
			this->tileBarGroup15->Name = L"tileBarGroup15";
			// 
			// MainForm
			// 
			this->Appearance->BackColor = System::Drawing::Color::White;
			this->Appearance->Options->UseBackColor = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1018, 607);
			this->Controls->Add(this->tileBar1);
			this->Controls->Add(this->picMycam);
			this->Controls->Add(this->btnSetting);
			this->Controls->Add(this->btnChat);
			this->Controls->Add(this->picYourcam);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnPlay);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picYourcam->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMycam->Properties))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
public:
	int LiveCam()
	{
		camera abc;
		Mat frame;
		VideoCapture cam;

		int deviceID = 0;             // 0 = open default camera
		int apiID = cv::CAP_ANY;      // 0 = autodetect default API
		cam.open(deviceID + apiID);
		if (!cam.isOpened()) {
			cerr << "ERROR! Unable to open camera\n";
			return -1;
		}
		cout << "Start grabbing" << endl
			<< "Press any key to terminate" << endl;
		for (;;)
		{
			cam.read(frame);
			if (frame.empty()) {
				cerr << "ERROR! blank frame grabbed\n";
				break;
			}
			//imshow("Live", frame);
			picMycam->Image = abc.Show(frame);
			picMycam->IsMirrored;
			if (waitKey(5) >= 0)
				break;
		}
		return 0;
	}

	private: System::Void btnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
		LiveCam();
	}
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		picMycam->Image = nullptr;
	}

	private: System::Void SimpleButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		//this->Hide();
		//HWACHAT1::StartForm firstForm;
		//firstForm.ShowDialog();
		//this->Show();
	}
private: System::Void BtnSetting_Click(System::Object^ sender, System::EventArgs^ e) {
		//this->Hide();
		//HWACHAT1::StartForm firstForm;
		//firstForm.ShowDialog();
		//this->Show();
	
}
};
};