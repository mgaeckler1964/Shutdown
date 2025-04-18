/*
		Project:		Shutdown
		Module:			Shutdown.cpp
		Description:	The application and the window definitions
		Author:			Martin G�ckler
		Address:		Hofmannsthalweg 14, A-4030 Linz
		Web:			https://www.gaeckler.at/

		Copyright:		(c) 1988-2025 Martin G�ckler

		This program is free software: you can redistribute it and/or modify  
		it under the terms of the GNU General Public License as published by  
		the Free Software Foundation, version 3.

		You should have received a copy of the GNU General Public License 
		along with this program. If not, see <http://www.gnu.org/licenses/>.

		THIS SOFTWARE IS PROVIDED BY Martin G�ckler, Linz, Austria ``AS IS''
		AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
		TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
		PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR
		CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
		SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
		LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
		USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
		ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
		OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
		OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
		SUCH DAMAGE.
*/


// --------------------------------------------------------------------- //
// ----- switches ------------------------------------------------------ //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- includes ------------------------------------------------------ //
// --------------------------------------------------------------------- //

#include <gak/fmtNumber.h>

#include <WINLIB/WINLIB.H>
#include <WINLIB/WINAPP.H>

#include "Shutdown_rc.h"
#include "Shutdown.gui.h"

// --------------------------------------------------------------------- //
// ----- imported datas ------------------------------------------------ //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- module switches ----------------------------------------------- //
// --------------------------------------------------------------------- //

#ifdef __BORLANDC__
#	pragma option -RT-
#	pragma option -b
#	pragma option -a4
#	pragma option -pc
#endif

using namespace winlib;
using namespace winlibGUI;

// --------------------------------------------------------------------- //
// ----- constants ----------------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- macros -------------------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- type definitions ---------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- class definitions --------------------------------------------- //
// --------------------------------------------------------------------- //

class ShutdownMainWindow : public ShutdownFORM_form
{
	time_t	m_endTime;
	int		m_controlId;
	bool	m_startAutoExit;

	void ShutdownMainWindow::execShutdown( int mode );

	virtual ProcessStatus handleCreate( void );
	virtual ProcessStatus handleButtonClick( int control );
	virtual void handleTimer( void );
	void startTimer( int control );
	void stopTimer( void );

public:
	ShutdownMainWindow() : ShutdownFORM_form( NULL ) 
	{
		m_endTime = 0;
		m_controlId = 0;
		m_startAutoExit = false;
	}
};

class ShutdownApplication : public GuiApplication
{
	virtual bool 	startApplication( HINSTANCE /*hInstance*/, const char * /*cmdLine*/ )
	{
		doEnableLogEx(gakLogging::llInfo);
		setApplication("Shutdown");
		setComapny("gak");
		return 0;
	}
	virtual CallbackWindow  *createMainWindow( const char * /*cmdLine*/, int /*nCmdShow*/ )
	{
		ShutdownMainWindow	*mainWindow = new ShutdownMainWindow;
		if( mainWindow->create( NULL ) == scERROR )
		{
			MessageBox( NULL, "Could not create window", "Error", MB_ICONERROR );
			delete mainWindow;
			mainWindow = NULL;
		}
		mainWindow->focus();
		mainWindow->DateTimePICKER->focus();

		return mainWindow;
	}
	virtual void deleteMainWindow( BasicWindow  *mainWindow )
	{
		delete mainWindow;
	}

	public:
	ShutdownApplication() : GuiApplication( IDI_SHUTDOWN ) {}
};

// --------------------------------------------------------------------- //
// ----- exported datas ------------------------------------------------ //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- module static data -------------------------------------------- //
// --------------------------------------------------------------------- //

static ShutdownApplication	shutdownApplication;

// --------------------------------------------------------------------- //
// ----- class static data --------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- prototypes ---------------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- module functions ---------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- class inlines ------------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- class constructors/destructors -------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- class static functions ---------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- class privates ------------------------------------------------ //
// --------------------------------------------------------------------- //

void ShutdownMainWindow::startTimer( int control )
{
	if( m_controlId == control )
	{
		execShutdown( control );
	}
	else
	{
		STRING action;

		stopTimer();

		SYSTEMTIME sysTime;
		DateTimePICKER->getSystemTime(sysTime);
		int		totalSeconds = sysTime.wHour * 3600 + sysTime.wMinute * 30 + sysTime.wSecond;

		shutdownApplication.WriteProfile( false, "", "totalSeconds", totalSeconds );
		shutdownApplication.WriteProfile( false, "", "unit", "" );

		m_endTime = time(NULL)+totalSeconds;
		m_controlId = control;
		setTimer(1000);

		switch( control )
		{
			case  ShutdownPUSHBUTTON_id:
				action = loadString(Shutdown_id);
				break;
			case  LogOffPUSHBUTTON_id:
				action = loadString(LogOFF_id);
				break;
			case  LockPUSHBUTTON_id:
				action = loadString(Lock_id);
				break;
			case  RestartPUSHBUTTON_id:
				action = loadString(Restart_id);
				break;
			case SuspendPUSHBUTTON_id:
				action = loadString(Suspend_id);
				break;
			case HibernatePUSHBUTTON_id:
				action = loadString(Hibernate_id);
				break;
		}
		ActionLABEL->setText(action);
	}
}

void ShutdownMainWindow::stopTimer( void )
{
	m_endTime = 0;
	m_controlId = 0;
	TimeLABEL->setText("00:00:00");
	ActionLABEL->setText("");
	removeTimer();
}

void ShutdownMainWindow::execShutdown( int control )
{
	HANDLE				token;
	TOKEN_PRIVILEGES	tokenpriv;

	stopTimer();

	// Token f�r diesen Prozess holen
	if(
		!OpenProcessToken(
			GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token
		)
	)
	{
		messageBox("Fehler beim OpenProcessToken");
/*@*/	return;
	}

	// LUID f�r die Shutdown Privilege holen
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tokenpriv.Privileges[0].Luid);
	tokenpriv.PrivilegeCount=1;
	tokenpriv.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;

	// Shutdown privilege f�r diesen Prozess setzen
	if(
		!AdjustTokenPrivileges(
			token, false, &tokenpriv, 0, PTOKEN_PRIVILEGES(NULL), 0
		)
	)
	{
		messageBox("Fehler bei AdjustTokenPrivileges");
/*@*/	return;
	}

	// execute autoexit
	if( m_startAutoExit )
	{
		STRING autoexitCmd = CmdEdit->getText();
		if( !autoexitCmd.isEmpty() )
		{
			shutdownApplication.WriteProfile( false, "", "autoexitCmd", autoexitCmd );
			SyncExec( autoexitCmd, SW_SHOW );
		}
	}
	// Windows beenden und Rechner ausschalten
	switch( control )
	{
		case  ShutdownPUSHBUTTON_id:
			if( !ExitWindowsEx( EWX_LOGOFF|EWX_POWEROFF, 0 ) )
			{
				messageBox("Fehler beim ExitWindowsEx");
/*@*/			return;
			}
			break;
		case  LogOffPUSHBUTTON_id:
			if( !ExitWindowsEx( EWX_LOGOFF, 0 ) )
			{
				messageBox("Fehler beim ExitWindowsEx");
/*@*/			return;
			}
			break;
		case  LockPUSHBUTTON_id:
			if( !LockWorkStation() )
			{
				messageBox("Fehler bei LockWorkstation");
/*@*/			return;
			}
			break;
		case  RestartPUSHBUTTON_id:
			if( !ExitWindowsEx( EWX_LOGOFF|EWX_REBOOT, 0 ) )
			{
				messageBox("Fehler beim ExitWindowsEx");
/*@*/			return;
			}
			break;
		case SuspendPUSHBUTTON_id:
			if( !SetSystemPowerState( TRUE, FALSE ) )
			{
				messageBox("Fehler beim SetSystemPowerState");
/*@*/			return;
			}
			break;
		case HibernatePUSHBUTTON_id:
			if( !SetSystemPowerState( FALSE, FALSE ) )
			{
				messageBox("Fehler beim SetSystemPowerState");
/*@*/			return;
			}
			break;
	}
	close();
}

// --------------------------------------------------------------------- //
// ----- class protected ----------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- class virtuals ------------------------------------------------ //
// --------------------------------------------------------------------- //
   
ProcessStatus ShutdownMainWindow::handleCreate( void )
{
	InfoLabel->setText(gak::formatNumber(sizeof(void*)*8) + "-bit");
	
	long	totalSeconds = shutdownApplication.GetProfile( "", "totalSeconds", 3600 );

	SYSTEMTIME	systime;
	DateTimePICKER->getSystemTime(systime);
	systime.wHour = WORD(totalSeconds / 3600);
	totalSeconds %= 3600;
	systime.wMinute = WORD(totalSeconds / 60);
	totalSeconds %= 60;
	systime.wSecond = WORD(totalSeconds);
	DateTimePICKER->setSystemTime(systime);
	focus();
	DateTimePICKER->focus();

	STRING	autoexitCmd = shutdownApplication.GetProfile( "", "autoexitCmd", "" );
	CmdEdit->setText(autoexitCmd );

	return psDO_DEFAULT;
}

ProcessStatus ShutdownMainWindow::handleButtonClick( int buttonID )
{
	m_startAutoExit = false;
	switch( buttonID )
	{
		case ShutdownPUSHBUTTON_id:
		case LogOffPUSHBUTTON_id:
		case RestartPUSHBUTTON_id:
			m_startAutoExit = true;
		case LockPUSHBUTTON_id:
		case SuspendPUSHBUTTON_id:
		case HibernatePUSHBUTTON_id:
			startTimer(buttonID);
			break;

		case ClosePUSHBUTTON_id:
		{
			if( hasTimer() )
			{
				stopTimer();
			}
			else
			{
				close();
			}
			break;
		}

		default:
			return ShutdownFORM_form::handleButtonClick( buttonID );
	}
	return psPROCESSED;
}

void ShutdownMainWindow::handleTimer( void )
{
	char buffer[32];

	time_t	timeLeft = m_endTime - time(NULL);

	if( timeLeft >= 0 )
	{
		int hour = int(timeLeft / 3600);
		timeLeft %= 3600;
		int minute = int(timeLeft / 60);
		timeLeft %= 60;
		int second = int(timeLeft);

		sprintf( buffer, "%02d:%02d:%02d", hour, minute, second );
		TimeLABEL->setText( buffer );
	}
	else
	{
		execShutdown( m_controlId );
	}
}

// --------------------------------------------------------------------- //
// ----- class publics ------------------------------------------------- //
// --------------------------------------------------------------------- //

// --------------------------------------------------------------------- //
// ----- entry points -------------------------------------------------- //
// --------------------------------------------------------------------- //

#ifdef __BORLANDC__
#	pragma option -RT.
#	pragma option -b.
#	pragma option -a.
#	pragma option -p.
#endif

