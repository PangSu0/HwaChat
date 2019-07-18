#pragma once

namespace HWACHAT_OPTION {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OptionForm
	/// </summary>
	public ref class OptionForm : public DevExpress::XtraEditors::XtraForm
	{

	private: System::Windows::Forms::Form^ optionform;
	public:
		OptionForm(System::Windows::Forms::Form^ o)
		{
			optionform = o;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OptionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevExpress::XtraEditors::GroupControl^ groupControl1;
	protected:
	private: DevExpress::XtraEditors::LabelControl^ labelControl2;
	private: DevExpress::XtraEditors::LabelControl^ labelControl1;
	private: DevExpress::XtraEditors::SimpleButton^ simpleButton2;
	private: DevExpress::XtraEditors::SimpleButton^ simpleButton1;
	private: DevExpress::XtraEditors::TrackBarControl^ tbcMic;

	private: DevExpress::XtraEditors::TrackBarControl^ tbcSpeaker;

	private: DevExpress::XtraEditors::SimpleButton^ simpleButton3;

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
			this->groupControl1 = (gcnew DevExpress::XtraEditors::GroupControl());
			this->simpleButton3 = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->labelControl2 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl1 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->simpleButton2 = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->simpleButton1 = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->tbcMic = (gcnew DevExpress::XtraEditors::TrackBarControl());
			this->tbcSpeaker = (gcnew DevExpress::XtraEditors::TrackBarControl());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupControl1))->BeginInit();
			this->groupControl1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbcMic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbcMic->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbcSpeaker))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbcSpeaker->Properties))->BeginInit();
			this->SuspendLayout();
			// 
			// groupControl1
			// 
			this->groupControl1->Controls->Add(this->simpleButton3);
			this->groupControl1->Controls->Add(this->labelControl2);
			this->groupControl1->Controls->Add(this->labelControl1);
			this->groupControl1->Controls->Add(this->simpleButton2);
			this->groupControl1->Controls->Add(this->simpleButton1);
			this->groupControl1->Controls->Add(this->tbcMic);
			this->groupControl1->Controls->Add(this->tbcSpeaker);
			this->groupControl1->Location = System::Drawing::Point(12, 12);
			this->groupControl1->Name = L"groupControl1";
			this->groupControl1->Size = System::Drawing::Size(330, 191);
			this->groupControl1->TabIndex = 0;
			// 
			// simpleButton3
			// 
			this->simpleButton3->Appearance->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->simpleButton3->Appearance->BackColor2 = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->simpleButton3->Appearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(239)));
			this->simpleButton3->Appearance->Options->UseBackColor = true;
			this->simpleButton3->Appearance->Options->UseBorderColor = true;
			this->simpleButton3->ImageOptions->ImageToTextAlignment = DevExpress::XtraEditors::ImageAlignToText::TopCenter;
			this->simpleButton3->Location = System::Drawing::Point(218, 128);
			this->simpleButton3->Name = L"simpleButton3";
			this->simpleButton3->Size = System::Drawing::Size(87, 45);
			this->simpleButton3->TabIndex = 6;
			this->simpleButton3->Text = L"INFO";
			// 
			// labelControl2
			// 
			this->labelControl2->Appearance->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelControl2->Appearance->Options->UseFont = true;
			this->labelControl2->Location = System::Drawing::Point(65, 108);
			this->labelControl2->Name = L"labelControl2";
			this->labelControl2->Size = System::Drawing::Size(28, 18);
			this->labelControl2->TabIndex = 5;
			this->labelControl2->Text = L"Mic";
			// 
			// labelControl1
			// 
			this->labelControl1->Appearance->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelControl1->Appearance->Options->UseFont = true;
			this->labelControl1->Location = System::Drawing::Point(43, 24);
			this->labelControl1->Name = L"labelControl1";
			this->labelControl1->Size = System::Drawing::Size(73, 18);
			this->labelControl1->TabIndex = 4;
			this->labelControl1->Text = L"Speaker";
			// 
			// simpleButton2
			// 
			this->simpleButton2->Location = System::Drawing::Point(137, 129);
			this->simpleButton2->Name = L"simpleButton2";
			this->simpleButton2->Size = System::Drawing::Size(46, 45);
			this->simpleButton2->TabIndex = 3;
			this->simpleButton2->Text = L"MUTE";
			this->simpleButton2->Click += gcnew System::EventHandler(this, &OptionForm::SimpleButton2_Click);
			// 
			// simpleButton1
			// 
			this->simpleButton1->Location = System::Drawing::Point(137, 48);
			this->simpleButton1->Name = L"simpleButton1";
			this->simpleButton1->Size = System::Drawing::Size(46, 45);
			this->simpleButton1->TabIndex = 2;
			this->simpleButton1->Text = L"MUTE";
			this->simpleButton1->Click += gcnew System::EventHandler(this, &OptionForm::SimpleButton1_Click);
			// 
			// tbcMic
			// 
			this->tbcMic->EditValue = nullptr;
			this->tbcMic->Location = System::Drawing::Point(27, 129);
			this->tbcMic->Name = L"tbcMic";
			this->tbcMic->Properties->LabelAppearance->Options->UseTextOptions = true;
			this->tbcMic->Properties->LabelAppearance->TextOptions->HAlignment = DevExpress::Utils::HorzAlignment::Center;
			this->tbcMic->Size = System::Drawing::Size(104, 45);
			this->tbcMic->TabIndex = 1;
			// 
			// tbcSpeaker
			// 
			this->tbcSpeaker->EditValue = nullptr;
			this->tbcSpeaker->Location = System::Drawing::Point(27, 48);
			this->tbcSpeaker->Name = L"tbcSpeaker";
			this->tbcSpeaker->Properties->LabelAppearance->Options->UseTextOptions = true;
			this->tbcSpeaker->Properties->LabelAppearance->TextOptions->HAlignment = DevExpress::Utils::HorzAlignment::Center;
			this->tbcSpeaker->Size = System::Drawing::Size(104, 45);
			this->tbcSpeaker->TabIndex = 0;
			this->tbcSpeaker->EditValueChanged += gcnew System::EventHandler(this, &OptionForm::TbcSpeaker_EditValueChanged);
			// 
			// OptionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(352, 215);
			this->Controls->Add(this->groupControl1);
			this->Name = L"OptionForm";
			this->Text = L"HwaChat_Option";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupControl1))->EndInit();
			this->groupControl1->ResumeLayout(false);
			this->groupControl1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbcMic->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbcMic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbcSpeaker->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbcSpeaker))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void SimpleButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	tbcSpeaker->Value = 0;
}
private: System::Void SimpleButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	tbcMic->Value = 0;
}
private: System::Void TbcSpeaker_EditValueChanged(System::Object^ sender, System::EventArgs^ e) {
	//HRESULT hr = CoInitialize(NULL);
	//if (hr == S_OK)
	//{
	//	IMMDeviceEnumerator* pIMMDeviceEnumerator = NULL;
	//	hr = CoCreateInstance(CLSID_MMDeviceEnumerator, NULL, CLSCTX_ALL,
	//		IID_IMMDeviceEnumerator, (LPVOID*)& pIMMDeviceEnumerator);
	//	if (hr == S_OK)
	//	{
	//		IMMDevice* defaultDevice = NULL;
	//		hr = pIMMDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	//		pIMMDeviceEnumerator->Release();
	//		pIMMDeviceEnumerator = NULL;
	//		if (hr == S_OK) //
	//		{
	//			IAudioEndpointVolume* EndPointVolume = NULL;
	//			hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
	//				CLSCTX_ALL, NULL, (LPVOID*)& EndPointVolume);
	//			defaultDevice->Release();
	//			defaultDevice = NULL;

	//			float Volume = 0; //Scalar volume is from zero to 1.00 in 0.01 step
	//			hr = EndPointVolume->GetMasterVolumeLevelScalar(&Volume);
	//			if (hr == S_OK) //       
	//			{
	//				Volume = tbcSpeaker->Value;
	//				if (Volume >= 1)
	//				{
	//					Volume = Volume / 100; //Adjust to zero to 1.00 in 0.01 step
	//				}
	//				hr = EndPointVolume->SetMasterVolumeLevelScalar((float)Volume, NULL);
	//				EndPointVolume->Release();
	//				EndPointVolume = NULL;
	//			}
	//		}
	//	}
	//	CoUninitialize();
	//}

}
};
}
