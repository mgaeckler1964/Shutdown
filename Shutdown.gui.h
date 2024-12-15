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

namespace winlibGUI {

	const int ClosePUSHBUTTON_id=138;
	const int HibernatePUSHBUTTON_id=134;
	const int InfoLabel_id=143;
	const int LABEL_id=135;
	const int LockPUSHBUTTON_id=131;
	const int LogOffPUSHBUTTON_id=130;
	const int mainFRAME_id=141;
	const int RestartPUSHBUTTON_id=132;
	const int ShutdownFORM_id=128;
	const int ShutdownICON_id=142;
	const int ShutdownPUSHBUTTON_id=129;
	const int SuspendPUSHBUTTON_id=133;
	const int TimeEDIT_id=136;
	const int TimeLABEL_id=139;
	const int TimeUPDOWNBUTTON_id=137;
	const int UnitCOMBOBOX_id=140;

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
		winlib::Label *LABEL;
		winlib::EditControl *TimeEDIT;
		winlib::UpDownButton *TimeUPDOWNBUTTON;
		winlib::PushButton *ClosePUSHBUTTON;
		winlib::Label *TimeLABEL;
		winlib::ComboBox *UnitCOMBOBOX;
		winlib::FrameChild *mainFRAME;
		winlib::Label *ShutdownICON;
		winlib::Label *InfoLabel;
		private:
		virtual void getControls();
	};	// end of ShutdownFORM
}	// namespace winlibGUI

#endif // C__CRESD_SOURCE_SHUTDOWN_SHUTDOWN_GUI_H
