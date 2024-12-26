/*
	this file was created from C:\CRESD\Source\Shutdown\Shutdown.gui with MG Gui Builder
	+++++++++++++++++++++++
	!!!!! Do not Edit !!!!!
	+++++++++++++++++++++++
*/
#ifndef C__CRESD_SOURCE_SHUTDOWN_SHUTDOWN_GUI_H
#define C__CRESD_SOURCE_SHUTDOWN_SHUTDOWN_GUI_H
#include <winlib/popup.h>
#include <winlib/frame.h>
#include <winlib/scrollFrame.h>
#include <winlib/ControlW.h>
#include <winlib/xmlEditorChild.h>
#include <winlib/gridView.h>

#include <winlib/winApp.h>

namespace winlibGUI {

	const int ActionLABEL_id=135;
	const int ClosePUSHBUTTON_id=139;
	const int Hibernate_id=149;
	const int HibernatePUSHBUTTON_id=134;
	const int InfoLabel_id=142;
	const int Lock_id=147;
	const int LockPUSHBUTTON_id=131;
	const int LogOFF_id=144;
	const int LogOffPUSHBUTTON_id=130;
	const int mainFRAME_id=141;
	const int Restart_id=146;
	const int RestartPUSHBUTTON_id=132;
	const int Shutdown_id=145;
	const int ShutdownFORM_id=128;
	const int ShutdownICON_id=143;
	const int ShutdownPUSHBUTTON_id=129;
	const int Suspend_id=148;
	const int SuspendPUSHBUTTON_id=133;
	const int TimeEDIT_id=136;
	const int TimeLABEL_id=138;
	const int TimeUPDOWNBUTTON_id=137;
	const int UnitCOMBOBOX_id=140;

	class GuiApplication : public winlib::Application {
		public:
		virtual gak::xml::Document *getGuiDoc( void );
		GuiApplication(int iconID=-1) : winlib::Application(iconID) {}
	};

	class ShutdownFORM_form : public winlib::PopupWindow {
		public:
		ShutdownFORM_form(winlib::BasicWindow *owner) : PopupWindow(owner) {}
		winlib::SuccessCode create(winlib::BasicWindow*parent) {
			return PopupWindow::create(parent,"ShutdownFORM");
		}

		winlib::PushButton *ShutdownPUSHBUTTON;
		winlib::PushButton *LogOffPUSHBUTTON;
		winlib::PushButton *LockPUSHBUTTON;
		winlib::PushButton *RestartPUSHBUTTON;
		winlib::PushButton *SuspendPUSHBUTTON;
		winlib::PushButton *HibernatePUSHBUTTON;
		winlib::Label *ActionLABEL;
		winlib::EditControl *TimeEDIT;
		winlib::UpDownButton *TimeUPDOWNBUTTON;
		winlib::Label *TimeLABEL;
		winlib::PushButton *ClosePUSHBUTTON;
		winlib::ComboBox *UnitCOMBOBOX;
		winlib::FrameChild *mainFRAME;
		winlib::Label *InfoLabel;
		winlib::Label *ShutdownICON;
		private:
		virtual void getControls();
	};	// end of ShutdownFORM
	extern const int STRINGLIST_ids[];
	static const int STRINGLIST_count = 6;
}	// namespace winlibGUI

#endif // C__CRESD_SOURCE_SHUTDOWN_SHUTDOWN_GUI_H
