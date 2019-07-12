#pragma once

namespace HwaChat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CreditForm
	/// </summary>
	public ref class CreditForm : public System::Windows::Forms::Form
	{
	public:
		CreditForm(void)
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
		~CreditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: DevExpress::XtraEditors::LabelControl^ labelControl1;
	private: DevExpress::XtraEditors::LabelControl^ labelControl8;
	private: DevExpress::XtraEditors::LabelControl^ labelControl7;
	private: DevExpress::XtraEditors::LabelControl^ labelControl6;
	private: DevExpress::XtraEditors::LabelControl^ labelControl5;
	private: DevExpress::XtraEditors::LabelControl^ labelControl4;
	private: DevExpress::XtraEditors::LabelControl^ labelControl3;
	private: DevExpress::XtraEditors::LabelControl^ labelControl2;
	private: DevExpress::XtraEditors::SimpleButton^ simpleButton1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreditForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelControl1 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl8 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl7 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl6 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl5 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl4 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl3 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl2 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->simpleButton1 = (gcnew DevExpress::XtraEditors::SimpleButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 62);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(604, 549);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// labelControl1
			// 
			this->labelControl1->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 25));
			this->labelControl1->Appearance->Options->UseFont = true;
			this->labelControl1->Location = System::Drawing::Point(731, 62);
			this->labelControl1->Name = L"labelControl1";
			this->labelControl1->Size = System::Drawing::Size(115, 45);
			this->labelControl1->TabIndex = 6;
			this->labelControl1->Text = L"CREDIT";
			// 
			// labelControl8
			// 
			this->labelControl8->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl8->Appearance->ForeColor = System::Drawing::Color::SteelBlue;
			this->labelControl8->Appearance->Options->UseFont = true;
			this->labelControl8->Appearance->Options->UseForeColor = true;
			this->labelControl8->Location = System::Drawing::Point(622, 447);
			this->labelControl8->Name = L"labelControl8";
			this->labelControl8->Size = System::Drawing::Size(94, 27);
			this->labelControl8->TabIndex = 19;
			this->labelControl8->Text = L"2019.07.12";
			// 
			// labelControl7
			// 
			this->labelControl7->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl7->Appearance->ForeColor = System::Drawing::Color::SteelBlue;
			this->labelControl7->Appearance->Options->UseFont = true;
			this->labelControl7->Appearance->Options->UseForeColor = true;
			this->labelControl7->Location = System::Drawing::Point(622, 342);
			this->labelControl7->Name = L"labelControl7";
			this->labelControl7->Size = System::Drawing::Size(236, 27);
			this->labelControl7->TabIndex = 18;
			this->labelControl7->Text = L"SiKeon ， EunJoung ， InA";
			// 
			// labelControl6
			// 
			this->labelControl6->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl6->Appearance->ForeColor = System::Drawing::Color::SteelBlue;
			this->labelControl6->Appearance->Options->UseFont = true;
			this->labelControl6->Appearance->Options->UseForeColor = true;
			this->labelControl6->Location = System::Drawing::Point(622, 296);
			this->labelControl6->Name = L"labelControl6";
			this->labelControl6->Size = System::Drawing::Size(292, 27);
			this->labelControl6->TabIndex = 17;
			this->labelControl6->Text = L"PangSu ， YoungJu ， MinCheol";
			// 
			// labelControl5
			// 
			this->labelControl5->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl5->Appearance->ForeColor = System::Drawing::Color::SteelBlue;
			this->labelControl5->Appearance->Options->UseFont = true;
			this->labelControl5->Appearance->Options->UseForeColor = true;
			this->labelControl5->Location = System::Drawing::Point(622, 198);
			this->labelControl5->Name = L"labelControl5";
			this->labelControl5->Size = System::Drawing::Size(35, 27);
			this->labelControl5->TabIndex = 16;
			this->labelControl5->Text = L"1.0.1";
			// 
			// labelControl4
			// 
			this->labelControl4->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl4->Appearance->Options->UseFont = true;
			this->labelControl4->Location = System::Drawing::Point(622, 392);
			this->labelControl4->Name = L"labelControl4";
			this->labelControl4->Size = System::Drawing::Size(133, 27);
			this->labelControl4->TabIndex = 15;
			this->labelControl4->Text = L"Release Date";
			// 
			// labelControl3
			// 
			this->labelControl3->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl3->Appearance->Options->UseFont = true;
			this->labelControl3->Location = System::Drawing::Point(622, 253);
			this->labelControl3->Name = L"labelControl3";
			this->labelControl3->Size = System::Drawing::Size(61, 27);
			this->labelControl3->TabIndex = 14;
			this->labelControl3->Text = L"Editor";
			// 
			// labelControl2
			// 
			this->labelControl2->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl2->Appearance->Options->UseFont = true;
			this->labelControl2->Location = System::Drawing::Point(622, 142);
			this->labelControl2->Name = L"labelControl2";
			this->labelControl2->Size = System::Drawing::Size(122, 27);
			this->labelControl2->TabIndex = 13;
			this->labelControl2->Text = L"S/W Version";
			// 
			// simpleButton1
			// 
			this->simpleButton1->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 26.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->simpleButton1->Appearance->Options->UseFont = true;
			this->simpleButton1->Location = System::Drawing::Point(659, 524);
			this->simpleButton1->Name = L"simpleButton1";
			this->simpleButton1->Size = System::Drawing::Size(246, 87);
			this->simpleButton1->TabIndex = 20;
			this->simpleButton1->Text = L"EXIT";
			this->simpleButton1->Click += gcnew System::EventHandler(this, &CreditForm::SimpleButton1_Click);
			// 
			// CreditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(954, 667);
			this->Controls->Add(this->simpleButton1);
			this->Controls->Add(this->labelControl8);
			this->Controls->Add(this->labelControl7);
			this->Controls->Add(this->labelControl6);
			this->Controls->Add(this->labelControl5);
			this->Controls->Add(this->labelControl4);
			this->Controls->Add(this->labelControl3);
			this->Controls->Add(this->labelControl2);
			this->Controls->Add(this->labelControl1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"CreditForm";
			this->Text = L"CreditForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SimpleButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
};
}
