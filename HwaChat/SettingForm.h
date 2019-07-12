#pragma once

namespace HwaChat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingForm
	/// </summary>
	public ref class SettingForm : public System::Windows::Forms::Form
	{
	public:
		SettingForm(void)
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
		~SettingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: DevExpress::XtraEditors::LabelControl^ labelControl1;
	private: DevExpress::XtraEditors::LabelControl^ labelControl2;
	private: DevExpress::XtraEditors::LabelControl^ labelControl6;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelControl1 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl2 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->labelControl6 = (gcnew DevExpress::XtraEditors::LabelControl());
			this->simpleButton1 = (gcnew DevExpress::XtraEditors::SimpleButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(604, 580);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// labelControl1
			// 
			this->labelControl1->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 25));
			this->labelControl1->Appearance->Options->UseFont = true;
			this->labelControl1->Location = System::Drawing::Point(701, 46);
			this->labelControl1->Name = L"labelControl1";
			this->labelControl1->Size = System::Drawing::Size(129, 45);
			this->labelControl1->TabIndex = 5;
			this->labelControl1->Text = L"SETTING";
			// 
			// labelControl2
			// 
			this->labelControl2->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl2->Appearance->Options->UseFont = true;
			this->labelControl2->Location = System::Drawing::Point(622, 135);
			this->labelControl2->Name = L"labelControl2";
			this->labelControl2->Size = System::Drawing::Size(116, 27);
			this->labelControl2->TabIndex = 7;
			this->labelControl2->Text = L"MIC Volume";
			// 
			// labelControl6
			// 
			this->labelControl6->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 15));
			this->labelControl6->Appearance->Options->UseFont = true;
			this->labelControl6->Location = System::Drawing::Point(622, 258);
			this->labelControl6->Name = L"labelControl6";
			this->labelControl6->Size = System::Drawing::Size(181, 27);
			this->labelControl6->TabIndex = 11;
			this->labelControl6->Text = L"Opponent Volume";
			// 
			// simpleButton1
			// 
			this->simpleButton1->Appearance->Font = (gcnew System::Drawing::Font(L"Haan Baekje B", 25));
			this->simpleButton1->Appearance->Options->UseFont = true;
			this->simpleButton1->Location = System::Drawing::Point(667, 549);
			this->simpleButton1->Name = L"simpleButton1";
			this->simpleButton1->Size = System::Drawing::Size(179, 65);
			this->simpleButton1->TabIndex = 12;
			this->simpleButton1->Text = L"CREDIT";
			this->simpleButton1->Click += gcnew System::EventHandler(this, &SettingForm::SimpleButton1_Click);
			// 
			// SettingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(925, 695);
			this->Controls->Add(this->simpleButton1);
			this->Controls->Add(this->labelControl6);
			this->Controls->Add(this->labelControl2);
			this->Controls->Add(this->labelControl1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"SettingForm";
			this->Text = L"SettingForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SimpleButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
};
}
