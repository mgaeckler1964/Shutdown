//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Shutdown.res");
USEFORM("ShutdownFrm.cpp", ShutdownForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "Rechnerabschaltung";
		Application->CreateForm(__classid(TShutdownForm), &ShutdownForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
