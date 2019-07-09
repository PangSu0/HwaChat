#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HwaChat::MyForm form;
	Application::Run(% form);
} 