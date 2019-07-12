#pragma once

namespace HwaChat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
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
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelControl2 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl3 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->simpleButton1 = (gcnew DevExpress::XtraEditors::SimpleButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(136, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(604, 729);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// labelControl2
			// 
			this->labelControl2->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 26.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->labelControl2->Appearance->Options->UseFont = true;
			this->labelControl2->Location = System::Drawing::Point(120, 477);
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
			this->labelControl3->Location = System::Drawing::Point(61, 569);
			this->labelControl3->Name = L"labelControl3";
			this->labelControl3->Size = System::Drawing::Size(128, 47);
			this->labelControl3->TabIndex = 6;
			this->labelControl3->Text = L"PORT : ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(209, 490);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(330, 21);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(209, 582);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(330, 21);
			this->textBox2->TabIndex = 8;
			// 
			// simpleButton1
			// 
			this->simpleButton1->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 25));
			this->simpleButton1->Appearance->Options->UseFont = true;
			this->simpleButton1->Location = System::Drawing::Point(636, 490);
			this->simpleButton1->Name = L"simpleButton1";
			this->simpleButton1->Size = System::Drawing::Size(203, 113);
			this->simpleButton1->TabIndex = 9;
			this->simpleButton1->Text = L"CONNECT";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(901, 674);
			this->Controls->Add(this->simpleButton1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->labelControl3);
			this->Controls->Add(this->labelControl2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
