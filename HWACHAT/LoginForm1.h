#pragma once
#include "MainForm.h"

namespace HWACHAT_LOGINFORM{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	// 배경에 사용할 사진이 필요함.
	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public DevExpress::XtraEditors::XtraForm
	{
	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: DevExpress::XtraEditors::LabelControl^ labelControl2;
	private: DevExpress::XtraEditors::LabelControl^ labelControl3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: DevExpress::XtraEditors::SimpleButton^ simpleButton1;




	protected:

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
			this->labelControl2 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl3 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->simpleButton1 = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->SuspendLayout();
			// 
			// labelControl2
			// 
			this->labelControl2->Appearance->BackColor = System::Drawing::Color::Transparent;
			this->labelControl2->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 26.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->labelControl2->Appearance->Options->UseBackColor = true;
			this->labelControl2->Appearance->Options->UseFont = true;
			this->labelControl2->Location = System::Drawing::Point(120, 556);
			this->labelControl2->Name = L"labelControl2";
			this->labelControl2->Size = System::Drawing::Size(69, 47);
			this->labelControl2->TabIndex = 5;
			this->labelControl2->Text = L"IP : ";
			// 
			// labelControl3
			// 
			this->labelControl3->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 26.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->labelControl3->Appearance->Options->UseFont = true;
			this->labelControl3->Location = System::Drawing::Point(61, 664);
			this->labelControl3->Name = L"labelControl3";
			this->labelControl3->Size = System::Drawing::Size(128, 47);
			this->labelControl3->TabIndex = 6;
			this->labelControl3->Text = L"PORT : ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(209, 572);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(330, 22);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(209, 679);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(330, 22);
			this->textBox2->TabIndex = 8;
			// 
			// simpleButton1
			// 
			this->simpleButton1->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 25));
			this->simpleButton1->Appearance->Options->UseFont = true;
			this->simpleButton1->Location = System::Drawing::Point(636, 572);
			this->simpleButton1->Name = L"simpleButton1";
			this->simpleButton1->Size = System::Drawing::Size(203, 132);
			this->simpleButton1->TabIndex = 9;
			this->simpleButton1->Text = L"CONNECT";
			this->simpleButton1->Click += gcnew System::EventHandler(this, &LoginForm::SimpleButton1_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(901, 786);
			this->Controls->Add(this->simpleButton1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->labelControl3);
			this->Controls->Add(this->labelControl2);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void SimpleButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		HWACHAT::MainForm^ mainform = gcnew HWACHAT::MainForm(this);
		mainform->Show();
	}
};
}