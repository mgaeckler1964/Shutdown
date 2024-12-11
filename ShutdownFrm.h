/*
		Project:		Shutdown
		Module:			ShutdownFrm.h
		Description:	The main form
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

//---------------------------------------------------------------------------

#ifndef ShutdownFrmH
#define ShutdownFrmH
//---------------------------------------------------------------------------
#include <time.h>

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
enum ShutDownMode {
	SHUTDOWN, LOGOFF_USER, LOCK_WORKSTATION, RESTART_WORKSTATION,
	SUSPEND, HIBERNATE
};
//---------------------------------------------------------------------------
class TShutdownForm : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TDateTimePicker *DateTimePicker;
	TLabel *Label1;
	TLabel *LabelCountDown;
	TButton *ButtonShutdown;
	TTimer *Timer;
	TImage *Image1;
	TButton *ButtonLogoff;
	TButton *ButtonLock;
	TButton *ButtonRestart;
	TLabel *LabelAction;
	TButton *ButtonClose;
	TButton *ButtonSuspend;
	TButton *ButtonHibernate;
	void __fastcall ButtonShutdownClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
private:	// Anwender-Deklarationen
	clock_t	startTime, endTime;
	void stopTimer( void )
	{
		Timer->Enabled = false;
		LabelAction->Caption = "";
	}
	void startTimer( TButton *button );
	void execShutdown( ShutDownMode mode );
public:		// Anwender-Deklarationen
	__fastcall TShutdownForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TShutdownForm *ShutdownForm;
//---------------------------------------------------------------------------
#endif
