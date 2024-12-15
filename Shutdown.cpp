/*
		Project:		Shutdown
		Module:			Shutdown.cpp
		Description:	The application and the window definitions
		Author:			Martin Gäckler
		Address:		Hofmannsthalweg 14, A-4030 Linz
		Web:			https://www.gaeckler.at/

		Copyright:		(c) 1988-2024 Martin Gäckler

		This program is free software: you can redistribute it and/or modify  
		it under the terms of the GNU General Public License as published by  
		the Free Software Foundation, version 3.

		You should have received a copy of the GNU General Public License 
		along with this program. If not, see <http://www.gnu.org/licenses/>.

		THIS SOFTWARE IS PROVIDED BY Martin Gäckler, Austria, Linz ``AS IS''
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
	}
};

class ShutdownApplication : public Application
{
	virtual bool 	startApplication( HINSTANCE /*hInstance*/, const char * /*cmdLine*/ )
	{
		setApplication("Shutdown");
		setComapny("gak");
		return 0;
	}
	virtual CallbackWindow  *createMainWindow( const char * /*cmdLine*/, int /*nCmdShow*/ )
	{
		doDisableLog();
		ShutdownMainWindow	*mainWindow = new ShutdownMainWindow;
		if( mainWindow->create( NULL ) == scERROR )
		{
			MessageBox( NULL, "Could not create window", "Error", MB_ICONERROR );
			delete mainWindow;
			mainWindow = NULL;
		}

		return mainWindow;
	}
	virtual void deleteMainWindow( BasicWindow  *mainWindow )
	{
		delete mainWindow;
	}

	public:
	ShutdownApplication() : Application( IDI_SHUTDOWN ) {}
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
		stopTimer();

		int		totalSeconds = TimeUPDOWNBUTTON->getPosition();
		long	unit = UnitCOMBOBOX->getSelection();

		if( unit == 1 )
		{
			totalSeconds *= 60;
		}
		else if( unit == 0 )
		{
			totalSeconds *= 3600;
		}

		shutdownApplication.WriteProfile( false, "", "totalSeconds", totalSeconds );
		shutdownApplication.WriteProfile( false, "", "unit", unit );

		m_endTime = time(NULL)+totalSeconds;
		m_controlId = control;
		setTimer(1000);
	}
}

void ShutdownMainWindow::stopTimer( void )
{
	m_endTime = 0;
	m_controlId = 0;
	TimeLABEL->setText("00:00:00");
	removeTimer();
}

void ShutdownMainWindow::execShutdown( int control )
{
	HANDLE				token;
	TOKEN_PRIVILEGES	tokenpriv;

	stopTimer();

	// Token für diesen Prozess holen
	if(
		!OpenProcessToken(
			GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token
		)
	)
	{
		messageBox("Fehler beim OpenProcessToken");
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
		messageBox("Fehler bei AdjustTokenPrivileges");
/*@*/	return;
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
	long	unit = shutdownApplication.GetProfile( "", "unit", 2 );

	if( unit == 1 )
	{
		totalSeconds /= 60;
	}
	else if( unit == 0 )
	{
		totalSeconds /= 3600;
	}

	TimeUPDOWNBUTTON->setPosition(short(totalSeconds));
	UnitCOMBOBOX->selectEntry(unit);

	return psDO_DEFAULT;
}

ProcessStatus ShutdownMainWindow::handleButtonClick( int control )
{
	switch( control )
	{
		case ShutdownPUSHBUTTON_id:
		case LogOffPUSHBUTTON_id:
		case LockPUSHBUTTON_id:
		case RestartPUSHBUTTON_id:
		case SuspendPUSHBUTTON_id:
		case HibernatePUSHBUTTON_id:
			startTimer(control);
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
			return ShutdownFORM_form::handleButtonClick( control );
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

