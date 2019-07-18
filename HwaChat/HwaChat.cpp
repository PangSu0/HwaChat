#include "pch.h"
#include "LoginForm.h"
#include "SettingForm.h"

using namespace System;
using namespace System::Windows::Forms;

using namespace System;

int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HwaChat::SettingForm form;
	Application::Run(% form);
    return 0;
}
