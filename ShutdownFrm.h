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
