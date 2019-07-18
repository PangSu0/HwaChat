#include "LoginForm1.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HWACHAT_LOGINFORM::LoginForm loginform;
	Application::Run(% loginform);
}