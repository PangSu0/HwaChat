#include "StartForm.h"

using namespace System;
using namespace System::Windows::Forms;

void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HWACHAT1::StartForm startform;
	Application::Run(% startform);

}