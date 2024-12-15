/*
	this file was created from C:\CRESD\Source\Shutdown\Shutdown.gui with MG Gui Builder
	+++++++++++++++++++++++
	!!!!! Do not Edit !!!!!
	+++++++++++++++++++++++
*/

#include "C:\CRESD\Source\Shutdown\Shutdown.gui.h"

namespace winlibGUI {

	void ShutdownFORM_form::getControls() {
		ShutdownPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(ShutdownPUSHBUTTON_id));
		LogOffPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(LogOffPUSHBUTTON_id));
		LockPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(LockPUSHBUTTON_id));
		RestartPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(RestartPUSHBUTTON_id));
		SuspendPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(SuspendPUSHBUTTON_id));
		HibernatePUSHBUTTON=static_cast<winlib::PushButton*>(findChild(HibernatePUSHBUTTON_id));
		LABEL=static_cast<winlib::Label*>(findChild(LABEL_id));
		TimeEDIT=static_cast<winlib::EditControl*>(findChild(TimeEDIT_id));
		TimeUPDOWNBUTTON=static_cast<winlib::UpDownButton*>(findChild(TimeUPDOWNBUTTON_id));
		ClosePUSHBUTTON=static_cast<winlib::PushButton*>(findChild(ClosePUSHBUTTON_id));
		TimeLABEL=static_cast<winlib::Label*>(findChild(TimeLABEL_id));
		UnitCOMBOBOX=static_cast<winlib::ComboBox*>(findChild(UnitCOMBOBOX_id));
		mainFRAME=static_cast<winlib::FrameChild*>(findChild(mainFRAME_id));
		ShutdownICON=static_cast<winlib::Label*>(findChild(ShutdownICON_id));
		InfoLabel=static_cast<winlib::Label*>(findChild(InfoLabel_id));
	}	// ShutdownFORM
}	// namespace winlibGUI
