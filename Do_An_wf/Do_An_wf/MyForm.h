#pragma once

#include <opencv2\opencv.hpp>
#include "Header.h"
#include "Do_an.h"
#include <iostream>
namespace Do_An_wf {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	using namespace cv;
	using namespace tung;
	/// <summary>
	/// Summary for MyForm
	VideoCapture cam;
	camera abc,cba;
	bool Start,quet,xu_ly;
	bool chuot;
	int x = 0, y = 0;
	//cv::Point diem_bd, diem_ht;
	int dem ;
	cv::Point diem_bd, diem_ht;
	bool keo_chuot;
	bool di_chuot;
	bool chup;
	//thuc hien lenh tempalte matching
	bool TemplateMatching;
	Rect HCN;
	string anhmau[5] = { "anhmau0.jpg","anhmau1.jpg","12.jpg","anhmau3.jpg","anhmau4.jpg" };
	//ten win
	string ten_anh = "My Picture";
	string tenmau[10];
	bool connect;
	//
	int Device;
	bool D;
	int d ;
	/// Serial Port
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btn_play;
	private: System::Windows::Forms::Button^  btn_stop;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  btn_exit;
	private: System::Windows::Forms::Button^  btn_quet;
	private: System::Windows::Forms::PictureBox^  pictureBox2;


	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Button^  btn_xu_ly;


	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::GroupBox^  groupBox6;


	private: System::Windows::Forms::Button^  btn_connect;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Button^  btn_thuan;
	private: System::Windows::Forms::Button^  btn_ngung;
	private: System::Windows::Forms::Button^  btn_disconnect;
	private: System::Windows::Forms::Button^  btn_reset;











	private: System::ComponentModel::IContainer^  components;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_play = (gcnew System::Windows::Forms::Button());
			this->btn_stop = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->btn_quet = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_xu_ly = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_disconnect = (gcnew System::Windows::Forms::Button());
			this->btn_connect = (gcnew System::Windows::Forms::Button());
			this->btn_ngung = (gcnew System::Windows::Forms::Button());
			this->btn_thuan = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(7, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(637, 470);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::click);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::move);
			// 
			// btn_play
			// 
			this->btn_play->Location = System::Drawing::Point(6, 27);
			this->btn_play->Name = L"btn_play";
			this->btn_play->Size = System::Drawing::Size(75, 23);
			this->btn_play->TabIndex = 1;
			this->btn_play->Text = L"Play";
			this->btn_play->UseVisualStyleBackColor = true;
			this->btn_play->Click += gcnew System::EventHandler(this, &MyForm::btn_play_Click);
			// 
			// btn_stop
			// 
			this->btn_stop->Location = System::Drawing::Point(6, 56);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(75, 23);
			this->btn_stop->TabIndex = 2;
			this->btn_stop->Text = L"Stop";
			this->btn_stop->UseVisualStyleBackColor = true;
			this->btn_stop->Click += gcnew System::EventHandler(this, &MyForm::btn_stop_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// btn_exit
			// 
			this->btn_exit->Location = System::Drawing::Point(901, 463);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(87, 45);
			this->btn_exit->TabIndex = 3;
			this->btn_exit->Text = L"Exit";
			this->btn_exit->UseVisualStyleBackColor = true;
			this->btn_exit->Click += gcnew System::EventHandler(this, &MyForm::btn_exit_Click);
			// 
			// btn_quet
			// 
			this->btn_quet->Location = System::Drawing::Point(6, 85);
			this->btn_quet->Name = L"btn_quet";
			this->btn_quet->Size = System::Drawing::Size(126, 23);
			this->btn_quet->TabIndex = 4;
			this->btn_quet->Text = L"quet";
			this->btn_quet->UseVisualStyleBackColor = true;
			this->btn_quet->Click += gcnew System::EventHandler(this, &MyForm::btn_quet_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(4, 14);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 60);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(4, 14);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(100, 60);
			this->pictureBox3->TabIndex = 8;
			this->pictureBox3->TabStop = false;
			// 
			// btn_xu_ly
			// 
			this->btn_xu_ly->Location = System::Drawing::Point(6, 114);
			this->btn_xu_ly->Name = L"btn_xu_ly";
			this->btn_xu_ly->Size = System::Drawing::Size(126, 23);
			this->btn_xu_ly->TabIndex = 9;
			this->btn_xu_ly->Text = L"xu_ly";
			this->btn_xu_ly->UseVisualStyleBackColor = true;
			this->btn_xu_ly->Click += gcnew System::EventHandler(this, &MyForm::btn_xu_ly_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(181, 53);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(33, 20);
			this->textBox3->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(104, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Số linh kiện";
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(4, 14);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 60);
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Location = System::Drawing::Point(5, 8);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(650, 497);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Show video";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->pictureBox2);
			this->groupBox2->Location = System::Drawing::Point(667, 204);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(110, 80);
			this->groupBox2->TabIndex = 19;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Linh Kiện 1";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->pictureBox3);
			this->groupBox3->Location = System::Drawing::Point(667, 290);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(110, 80);
			this->groupBox3->TabIndex = 20;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Linh Kiện 2";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->pictureBox4);
			this->groupBox4->Location = System::Drawing::Point(667, 376);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(110, 80);
			this->groupBox4->TabIndex = 21;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Linh kiện 3";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Web Cam", L"Cam" });
			this->comboBox1->Location = System::Drawing::Point(181, 24);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(70, 21);
			this->comboBox1->TabIndex = 22;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(104, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Chọn Camera";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->btn_play);
			this->groupBox5->Controls->Add(this->comboBox1);
			this->groupBox5->Controls->Add(this->label1);
			this->groupBox5->Controls->Add(this->btn_stop);
			this->groupBox5->Controls->Add(this->btn_xu_ly);
			this->groupBox5->Controls->Add(this->label3);
			this->groupBox5->Controls->Add(this->btn_quet);
			this->groupBox5->Controls->Add(this->textBox3);
			this->groupBox5->Location = System::Drawing::Point(671, 12);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(264, 152);
			this->groupBox5->TabIndex = 24;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Xử lý ảnh";
			// 
			// btn_reset
			// 
			this->btn_reset->Location = System::Drawing::Point(794, 464);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(82, 42);
			this->btn_reset->TabIndex = 24;
			this->btn_reset->Text = L"RESET";
			this->btn_reset->UseVisualStyleBackColor = true;
			this->btn_reset->Click += gcnew System::EventHandler(this, &MyForm::btn_reset_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->btn_disconnect);
			this->groupBox6->Controls->Add(this->btn_connect);
			this->groupBox6->Controls->Add(this->btn_ngung);
			this->groupBox6->Controls->Add(this->btn_thuan);
			this->groupBox6->Controls->Add(this->label7);
			this->groupBox6->Controls->Add(this->label6);
			this->groupBox6->Controls->Add(this->label5);
			this->groupBox6->Controls->Add(this->label4);
			this->groupBox6->Controls->Add(this->label2);
			this->groupBox6->Controls->Add(this->comboBox3);
			this->groupBox6->Controls->Add(this->comboBox2);
			this->groupBox6->Location = System::Drawing::Point(794, 204);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(183, 253);
			this->groupBox6->TabIndex = 25;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Arduino";
			// 
			// btn_disconnect
			// 
			this->btn_disconnect->Location = System::Drawing::Point(87, 223);
			this->btn_disconnect->Name = L"btn_disconnect";
			this->btn_disconnect->Size = System::Drawing::Size(75, 23);
			this->btn_disconnect->TabIndex = 27;
			this->btn_disconnect->Text = L"Disconnect";
			this->btn_disconnect->UseVisualStyleBackColor = true;
			this->btn_disconnect->Click += gcnew System::EventHandler(this, &MyForm::btn_disconnect_Click);
			// 
			// btn_connect
			// 
			this->btn_connect->Location = System::Drawing::Point(6, 223);
			this->btn_connect->Name = L"btn_connect";
			this->btn_connect->Size = System::Drawing::Size(75, 23);
			this->btn_connect->TabIndex = 26;
			this->btn_connect->Text = L"Connect";
			this->btn_connect->UseVisualStyleBackColor = true;
			this->btn_connect->Click += gcnew System::EventHandler(this, &MyForm::btn_connect_Click);
			// 
			// btn_ngung
			// 
			this->btn_ngung->Location = System::Drawing::Point(87, 137);
			this->btn_ngung->Name = L"btn_ngung";
			this->btn_ngung->Size = System::Drawing::Size(75, 23);
			this->btn_ngung->TabIndex = 8;
			this->btn_ngung->Text = L"ngung";
			this->btn_ngung->UseVisualStyleBackColor = true;
			this->btn_ngung->Click += gcnew System::EventHandler(this, &MyForm::btn_ngung_Click);
			// 
			// btn_thuan
			// 
			this->btn_thuan->Location = System::Drawing::Point(6, 137);
			this->btn_thuan->Name = L"btn_thuan";
			this->btn_thuan->Size = System::Drawing::Size(75, 23);
			this->btn_thuan->TabIndex = 7;
			this->btn_thuan->Text = L"thuan";
			this->btn_thuan->UseVisualStyleBackColor = true;
			this->btn_thuan->Click += gcnew System::EventHandler(this, &MyForm::btn_thuan_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::Control;
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(77, 100);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(27, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"OFF";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 100);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(65, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Trạng Thái :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 67);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Buad Rate";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(34, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"COM";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1200", L"9600", L"2000", L"4000" });
			this->comboBox3->Location = System::Drawing::Point(70, 61);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(71, 21);
			this->comboBox3->TabIndex = 1;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"COM1" });
			this->comboBox2->Location = System::Drawing::Point(43, 36);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(98, 21);
			this->comboBox2->TabIndex = 0;
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 520);
			this->Controls->Add(this->btn_reset);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btn_exit);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Do An Phan Loai San Pham";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		disable1();
		comboBox2->DataSource = SerialPort::GetPortNames(); //quet cac cong COM
		comboBox3->SelectedIndex = 1; // chon 9600
		connect = false; 
		di_chuot = false;
		keo_chuot = false;
		chup = false;
		TemplateMatching = false;
		quet = false;
		dem = 0;
		Start = false;
		xu_ly = false;
		D = false;
		comboBox1->SelectedIndex = 0;

		

	}
	private: System::Void btn_play_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox1->Text == "Web Cam")
		{
			Device = 0;
		}
		if (comboBox1->Text == "Cam")
		{
			Device = 1;
		}
		cam.open(Device);
		if (cam.isOpened())
		{
			MessageBox::Show("Quet du 3 anh roi an xu ly","Huong dan");
			Start = true;
			timer1->Start();
		}
		else
		{
			MessageBox::Show("Connect Failed");		
		}
		
	}
	private: System::Void btn_stop_Click(System::Object^  sender, System::EventArgs^  e) {
		//cam.open(0);
		Start = false;
		timer1->Stop();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//setMouseCallback(ten_anh, dk_chuot, &video);
		if (Start == true)
		{		
			ct_chinh();
		}
	}
private: Void ct_chinh()
{	
	int lk=0,lk1,lk2,lk3,lk4,lk5;
	Mat anh_mau1 = imread(anhmau[1]);//mau 1
	Mat anh_mau2 = imread(anhmau[2]);// mau 2
	Mat anh_mau3 = imread(anhmau[3]);
	//Mat anh_mau4=imread(anhmau[4]);
	//Mat anh_mau0=imread(anhmau[0]);
	cam.read(video);
	pictureBox1->Size = System::Drawing::Size(video.cols, video.rows);
	chup_anh(video);
	if (TemplateMatching == false)
	{
		pictureBox1->Image = abc.Show(video);
	}
	else
	{
		lk1=MatchingMethod(anh_mau1, 255, 0, 0, 1);
		lk2=MatchingMethod(anh_mau2, 0, 0, 255, 2);
		lk3 = MatchingMethod(anh_mau3, 0, 255, 0, 3);
		//lk4 = MatchingMethod(anh_mau4, 255, 0, 0, 4);
		//lk5 = MatchingMethod(anh_mau0, 255, 0, 0, 5);
		
		lk = lk1 + lk2 + lk3;
		switch (lk)
		{
		case 0:
			textBox3->Text = "0";
			serialPort1->Write("#ngung\n");
			break;
		case 1:
			textBox3->Text = "1";
			serialPort1->Write("#ngung\n");
			break;
		case 2:
			textBox3->Text = "2";
			serialPort1->Write("#ngung\n");
			break;
		case 3:
			textBox3->Text = "3";
			serialPort1->Write("#thuan\n");
			break;
		case 4:
			textBox3->Text = "4";
			break;
		case 5:
			textBox3->Text = "5";
			break;
		}
		pictureBox1->Image = abc.Show(video);
	}
		waitKey(10);				
}
private: Void chup_anh(Mat frame)
{
	Mat khung;
	Mat anh;
	Mat anh_mau;
	string ten1;
	Bitmap^ bmpSrc;
	Bitmap^ bmpSrc1;
	Bitmap^ bmpSrc2;
	if (chup==true)
	{
		cam.read(anh);
		khung = anh(HCN);
		khung.copyTo(anh_mau);
		bool tg = imwrite(anhmau[dem], anh_mau);
		switch (dem)
		{
		case 1:
			bmpSrc = gcnew Bitmap("anhmau1.jpg");
			pictureBox2->Size= System::Drawing::Size(100, 60);
			anh_mau.create(100,60 , CV_32FC1);
			//tenmau[dem] = ten1;
			pictureBox2->Image = bmpSrc;
			//pictureBox2->Refresh();
			chup = false;
			break;
			
		case 2:
			bmpSrc1 = gcnew Bitmap("12.jpg");
			pictureBox2->Size = System::Drawing::Size(100, 60);
			anh_mau.create(100, 60, CV_32FC1);
			pictureBox3->Image = bmpSrc1;
			//pictureBox3->Refresh();
			chup = false;
			break;
		case 3:
			bmpSrc2 = gcnew Bitmap("anhmau3.jpg");
			pictureBox2->Size = System::Drawing::Size(100, 60);
			anh_mau.create(100, 60, CV_32FC1);
			pictureBox4->Image = bmpSrc2;
			//pictureBox4->Refresh();
			chup = false;
			break;
		case 4:
			break;
		}
	}

}
private: int MatchingMethod(Mat anh_mau, int R, int G, int B, int n) {
	Mat anh_kq;
	int result_cols = video.cols - anh_mau.cols + 1;
	int result_rows = video.rows - anh_mau.rows + 1;
	anh_kq.create(result_cols, result_rows, CV_32FC1);

	matchTemplate(video, anh_mau, anh_kq, 5);
	//threshold(trunggian,trunggian,0.8,1.,CV_THRESH_TOZERO);

	while (1)
	{
		double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
		minMaxLoc(anh_kq, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
		if (maxVal >= 0.8)
		{
			putText(video, tenmau[n], cv::Point(maxLoc.x + anh_mau.cols - 20, maxLoc.y + anh_mau.rows + 20), 2, 1, Scalar(0, 255, 0), 2);
			rectangle(video, maxLoc, cv::Point(maxLoc.x + anh_mau.cols, maxLoc.y + anh_mau.rows), CV_RGB(R, G, B), 2, 8, 0);
			rectangle(anh_kq, maxLoc, cv::Point(maxLoc.x + anh_mau.cols, maxLoc.y + anh_mau.rows), CV_RGB(R, G, B), 2, 8, 0);
			floodFill(video, maxLoc, Scalar(R, G, B), 0, Scalar(.1), Scalar(1.));
			return 1;
		}
		else
		{
			return 0;
			break;
		}
	}

}
private: System::Void btn_exit_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("Are you sure?", "Question", MessageBoxButtons::YesNo, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}
private: System::Void btn_quet_Click(System::Object^  sender, System::EventArgs^  e) {
	if (quet == false)
	{
		btn_quet->Text = "dung quet";
		quet = true;
	}
	else                                                                                                
	{
		btn_quet->Text = "quet";
		quet = false;
	}
}
private: System::Void click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if ((quet)&&(keo_chuot==false))
	{
		x = e->X;
		y = e->Y;
		diem_bd = cv::Point(x, y);
		di_chuot = true;
	}
	if((quet)&&(keo_chuot))
	{
		HCN = Rect(diem_bd,diem_ht);
		chup = true;
		dem = dem + 1;
		di_chuot = false;
		keo_chuot = false;
	}
}
private: System::Void move(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (di_chuot)
	{
		x = e->X;
		y = e->Y;
		diem_ht = cv::Point(x, y);
		rectangle(video, diem_bd, cv::Point(diem_ht.x, diem_ht.y), Scalar(0, 255, 0));
		keo_chuot = true;
	}	
}
private: System::Void btn_xu_ly_Click(System::Object^  sender, System::EventArgs^  e) {
	if (xu_ly == false)
	{
		btn_xu_ly->Text = "dung_xu_ly";
		xu_ly = true;
		TemplateMatching = true;
		quet = false;
		btn_quet->Text = "quet";
		dem = 0;
		di_chuot = false;
		keo_chuot = false;
		chup = false;
	}
	else
	{
		btn_xu_ly->Text = "xu_ly";
		xu_ly = false;
		TemplateMatching = false;
	}	
}
private: Void enable1()
{
	btn_quet->Enabled = true;
	btn_play->Enabled = true;
	btn_stop->Enabled = true;
	btn_xu_ly->Enabled = true;
	comboBox1->Enabled = true;
	textBox3->Enabled = true;
	label1->Enabled = true;
	label3->Enabled = true;
}
private: Void disable1()
{
	btn_quet->Enabled = false;
	btn_play->Enabled = false;
	btn_stop->Enabled = false;
	btn_xu_ly->Enabled = false;
	comboBox1->Enabled = false;
	textBox3->Enabled = false;
	label1->Enabled = false;
	label3->Enabled = false;
}
private: System::Void btn_connect_Click(System::Object^  sender, System::EventArgs^  e) {

	if (!serialPort1->IsOpen)
	{
		serialPort1->PortName = comboBox2->Text;
		serialPort1->Open();
		enable1();
		label7->Text = "ON";
		//connect = true;

	}

/*
	if (connect==false)
	{
		
		//timer2->Start();
		connect = true;
		btn_connect->Text = "disconnect";
		label7->Text = "ON";
	}
	else
	{
		
		//timer2->Start();
		connect = false;
		btn_connect->Text = "Connect";
		label7->Text = "OFF";
	}
	*/
}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (connect==true)
	{
		if (!serialPort1->IsOpen)
		{
			serialPort1->PortName = comboBox2->Text;
			serialPort1->Open();
			//enable1();
			timer2->Stop();
		}
	}
	else
	{
		serialPort1->Close();
		//disable1();
		//timer2->Stop();
	}
}

	private: System::Void btn_thuan_Click(System::Object^  sender, System::EventArgs^  e) {
		if (serialPort1->IsOpen)
		{
			serialPort1->Write("#thuan\n");
		}
		else
		{
			MessageBox::Show("Please!!! Connect arduino");
		}
	}
	
private: System::Void btn_ngung_Click(System::Object^  sender, System::EventArgs^  e) {
	if (serialPort1->IsOpen)
	{
		serialPort1->Write("#ngung\n");
	}
	else
	{
		MessageBox::Show("Please!!! Connect arduino");
	}
	
}
private: System::Void btn_disconnect_Click(System::Object^  sender, System::EventArgs^  e) {
	serialPort1->Write("#ngung\n");
	serialPort1->Close();
	label7->Text = "OFF";
	disable1();
}

private: System::Void btn_reset_Click(System::Object^  sender, System::EventArgs^  e) {
	//pictureBox1->
	disable1();
	comboBox2->DataSource = SerialPort::GetPortNames(); //quet cac cong COM
	comboBox3->SelectedIndex = 1; // chon 9600
	connect = false;
	di_chuot = false;
	keo_chuot = false;
	chup = false;
	TemplateMatching = false;
	quet = false;
	dem = 0;
	Start = false;
	xu_ly = false;
	D = false;
	comboBox1->SelectedIndex = 0;
	serialPort1->Write("#ngung\n");
	serialPort1->Close();
}
};
}
