#pragma once
#include "MainForm.h"

namespace HWACHAT1 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public DevExpress::XtraEditors::XtraForm
	{
	public:
		StartForm(void)
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
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: DevExpress::XtraEditors::SimpleButton^ btnMain;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnMain = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->SuspendLayout();
			// 
			// btnMain
			// 
			this->btnMain->Location = System::Drawing::Point(96, 65);
			this->btnMain->Name = L"btnMain";
			this->btnMain->Size = System::Drawing::Size(75, 23);
			this->btnMain->TabIndex = 0;
			this->btnMain->Text = L"simpleButton1";
			this->btnMain->Click += gcnew System::EventHandler(this, &StartForm::btnMain_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btnMain);
			this->Name = L"StartForm";
			this->Text = L"StartForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnMain_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		HWACHAT::MainForm mainForm;
		mainForm.ShowDialog();
		this->Show();
	};
	};
}
