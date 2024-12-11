//---------------------------------------------------------------------------
#include <memory>

#include <vcl.h>
#include <vcl/registry.hpp>

#pragma hdrstop

#include "ShutdownFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TShutdownForm *ShutdownForm;
//---------------------------------------------------------------------------
__fastcall TShutdownForm::TShutdownForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TShutdownForm::startTimer( TButton *button )
{
	unsigned short hour, minute, second, milli;

	startTime = clock();
	DateTimePicker->Time.DecodeTime( &hour, &minute, &second, &milli );
	endTime = startTime +
		hour * 3600 * CLK_TCK +
		minute * 60 * CLK_TCK +
		second * CLK_TCK
	;

	std::auto_ptr<TRegistry> registry( new TRegistry() );
	if( registry->OpenKey( "Software\\CRESD\\Shutdown", true ) )
	{
		int totalSeconds = hour * 3600 + minute * 60 + second;
		registry->WriteInteger( "totalSeconds", totalSeconds );

		registry->CloseKey();
	}

	Timer->Tag = button->Tag;
	Timer->Enabled = true;
	LabelAction->Caption = button->Caption;
}
//---------------------------------------------------------------------------
void TShutdownForm::execShutdown( ShutDownMode mode )
{
	HANDLE				token;
	TOKEN_PRIVILEGES	tokenpriv;

	Timer->Enabled = false;

	// Token für diesen Prozess holen
	if(
		!OpenProcessToken(
			GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token
		)
	)
	{
		ShowMessage("Fehler beim OpenProcessToken");
/*@*/	return;
	}

	// LUID für die Shutdown Privilege holen
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tokenpriv.Privileges[0].Luid);
	tokenpriv.PrivilegeCount=1;
	tokenpriv.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;

	// Shutdown privilege für diesen Prozess setzen
	if(
		!AdjustTokenPrivileges(
			token, false, &tokenpriv, 0, PTOKEN_PRIVILEGES(NULL), 0
		)
	)
	{
		ShowMessage("Fehler bei AdjustTokenPrivileges");
/*@*/	return;
	}

	// Windows beenden und Rechner ausschalten

	switch( mode )
	{
		case  SHUTDOWN:
			if( !ExitWindowsEx( EWX_LOGOFF|EWX_POWEROFF, 0 ) )
			{
				ShowMessage("Fehler beim ExitWindowsEx");
/*@*/			return;
			}
			break;
		case  LOGOFF_USER:
			if( !ExitWindowsEx( EWX_LOGOFF, 0 ) )
			{
				ShowMessage("Fehler beim ExitWindowsEx");
/*@*/			return;
			}
			break;
		case  LOCK_WORKSTATION:
			if( !LockWorkStation() )
			{
				ShowMessage("Fehler bei LockWorkstation");
/*@*/			return;
			}
			break;
		case  RESTART_WORKSTATION:
			if( !ExitWindowsEx( EWX_LOGOFF|EWX_REBOOT, 0 ) )
			{
				ShowMessage("Fehler beim ExitWindowsEx");
/*@*/			return;
			}
			break;
		case SUSPEND:
			if( !SetSystemPowerState( TRUE, FALSE ) )
			{
				ShowMessage("Fehler beim SetSystemPowerState");
/*@*/			return;
			}
			break;
		case HIBERNATE:
			if( !SetSystemPowerState( FALSE, FALSE ) )
			{
				ShowMessage("Fehler beim SetSystemPowerState");
/*@*/			return;
			}
			break;
	}
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TShutdownForm::ButtonShutdownClick(TObject *Sender)
{
	TButton *button = dynamic_cast<TButton*>( Sender );
	if( button )
	{
		if( !Timer->Enabled || Timer->Tag != button->Tag )
		{
			startTimer( button );
		}
		else
		{
			execShutdown( ShutDownMode(button->Tag) );
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TShutdownForm::TimerTimer(TObject *)
{
	clock_t	timeLeft = endTime - clock();
	int		seconds = timeLeft / CLK_TCK;
	int		hour = seconds / 3600;
	seconds %= 3600;
	int		minute = seconds / 60;
	seconds %= 60;

	AnsiString	label;
	label.printf( "%02d:%02d:%02d", hour, minute, seconds );
	LabelCountDown->Caption = label;

	if( timeLeft <= 0 )
	{
		execShutdown( ShutDownMode(Timer->Tag) );
	}
}
//---------------------------------------------------------------------------
void __fastcall TShutdownForm::FormShow(TObject *)
{
	int		totalSeconds = 3 * 3600;
	Word	hour, minute, second;

	std::auto_ptr<TRegistry> registry( new TRegistry() );
	if( registry->OpenKey( "Software\\CRESD\\Shutdown", false ) )
	{
		if( registry->ValueExists( "totalSeconds" ) )
		{
			totalSeconds = registry->ReadInteger( "totalSeconds" );
		}
		registry->CloseKey();
	}

	hour = Word(totalSeconds / 3600);
	totalSeconds %= 3600;
	minute = Word(totalSeconds / 60);
	second = Word(totalSeconds % 60);
	DateTimePicker->Time = EncodeTime( hour, minute, second, 0 );
}
//---------------------------------------------------------------------------
void __fastcall TShutdownForm::ButtonCloseClick(TObject *)
{
	if( Timer->Enabled )
	{
		stopTimer();
	}
	else
	{
		Close();
	}
}
//---------------------------------------------------------------------------

