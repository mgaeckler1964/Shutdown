/*
	this file was created from C:\CRESD\Source\Shutdown\Shutdown.gui with MG Gui Builder
	+++++++++++++++++++++++
	!!!!! Do not Edit !!!!!
	+++++++++++++++++++++++
*/

#include "C:\CRESD\Source\Shutdown\Shutdown.gui.h"

namespace winlibGUI {

	gak::xml::Document *GuiApplication::getGuiDoc() {
		gak::xml::Document *doc = winlib::Application::getGuiDoc();
		if(!doc) {
			gak::STRING xmlSrc = "<?xml version=\"1.0\" encoding=\"iso-8859-1\" ?>\n"
"<gui>\n"
"<forms>\n"
"<form name=\"ShutdownFORM\" style=\"277807104\" width=\"702\" height=\"250\" caption=\"Shutdown\" id=\"128\" baseClass=\"PopupWindow\">\n"
"<child type=\"FrameChild\" name=\"\" caption=\"\" x=\"0\" y=\"88\" width=\"616\" height=\"48\" style=\"1350696960\">\n"
"<layout x=\"0\" y=\"1\" paddingLeft=\"5\" paddingRight=\"5\" paddingTop=\"5\" paddingBottom=\"5\" attachment=\"3\" growWidth=\"1\" growHeight=\"0\" />\n"
"<layoutManager type=\"RowManager\" />\n"
"<child type=\"PushButton\" name=\"ShutdownPUSHBUTTON\" caption=\"&amp;Abschalten\" x=\"8\" y=\"8\" width=\"88\" height=\"32\" style=\"1342242816\" id=\"129\">\n"
"<layout paddingLeft=\"5\" paddingRight=\"5\" paddingTop=\"5\" paddingBottom=\"5\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"LogOffPUSHBUTTON\" caption=\"Ab&amp;melden\" x=\"0\" y=\"0\" width=\"0\" height=\"0\" style=\"1342242816\" id=\"130\">\n"
"<layout paddingLeft=\"5\" paddingRight=\"5\" paddingTop=\"5\" paddingBottom=\"5\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"LockPUSHBUTTON\" caption=\"&amp;Sperren\" x=\"0\" y=\"0\" width=\"0\" height=\"0\" style=\"1342242816\" id=\"131\">\n"
"<layout paddingLeft=\"5\" paddingRight=\"5\" paddingTop=\"5\" paddingBottom=\"5\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"RestartPUSHBUTTON\" caption=\"&amp;Neustart\" x=\"304\" y=\"0\" width=\"80\" height=\"25\" style=\"1342242816\" id=\"132\">\n"
"<layout paddingLeft=\"5\" paddingRight=\"5\" paddingTop=\"5\" paddingBottom=\"5\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"SuspendPUSHBUTTON\" caption=\"&amp;Energie sparen\" x=\"337\" y=\"25\" width=\"80\" height=\"25\" style=\"1342242816\" id=\"133\">\n"
"<layout paddingLeft=\"5\" paddingRight=\"5\" paddingTop=\"5\" paddingBottom=\"5\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"HibernatePUSHBUTTON\" caption=\"&amp;Ruheustand\" x=\"474\" y=\"14\" width=\"80\" height=\"25\" style=\"1342242816\" id=\"134\">\n"
"<layout paddingLeft=\"5\" paddingRight=\"5\" paddingTop=\"5\" paddingBottom=\"5\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"</child>\n"
"<layoutManager type=\"AttachmentManager\" />\n"
"<child type=\"FrameChild\" name=\"\" caption=\"\" x=\"0\" y=\"0\" width=\"688\" height=\"224\" style=\"1342308352\">\n"
"<layout attachment=\"4\" growWidth=\"1\" growHeight=\"1\" />\n"
"<child type=\"FrameChild\" name=\"mainFRAME\" caption=\"\" x=\"352\" y=\"0\" width=\"336\" height=\"224\" style=\"1342308352\" id=\"141\">\n"
"<layout attachment=\"2\" growHeight=\"1\" />\n"
"<child type=\"Label\" name=\"LABEL\" caption=\"Zeit:\" x=\"16\" y=\"24\" width=\"24\" height=\"16\" style=\"1342242827\" id=\"135\" />\n"
"<child type=\"EditControl\" name=\"TimeEDIT\" caption=\"Edit\" x=\"48\" y=\"24\" width=\"90\" height=\"24\" style=\"1350631808\" id=\"136\" />\n"
"<child type=\"UpDownButton\" name=\"TimeUPDOWNBUTTON\" caption=\"\" x=\"296\" y=\"32\" width=\"25\" height=\"24\" style=\"1342242870\" id=\"137\" />\n"
"<child type=\"PushButton\" name=\"ClosePUSHBUTTON\" caption=\"&amp;Beenden\" x=\"240\" y=\"24\" width=\"80\" height=\"24\" style=\"1342242816\" id=\"138\" />\n"
"<child type=\"Label\" name=\"TimeLABEL\" caption=\"00:00:00\" x=\"16\" y=\"64\" width=\"304\" height=\"72\" style=\"1342242827\" id=\"139\" font=\"Courier New;-64;0;0;0;400;0;0;0;0;3;2;1;49\" />\n"
"<child type=\"ComboBox\" name=\"UnitCOMBOBOX\" caption=\"\" x=\"152\" y=\"24\" width=\"80\" height=\"62\" style=\"1342243843\" id=\"140\">\n"
"<items>\n"
"<item>Stunden</item>\n"
"<item>Minuten</item>\n"
"<item>Sekunden</item>\n"
"</items>\n"
"</child>\n"
"</child>\n"
"<child type=\"Label\" name=\"InfoLabel\" caption=\"xx\" x=\"8\" y=\"128\" width=\"80\" height=\"25\" style=\"1342242827\" font=\"Courier New;-11;0;0;0;400;0;0;0;0;3;2;1;49\" id=\"142\" />\n"
"<layoutManager type=\"AttachmentManager\" />\n"
"<child type=\"Label\" name=\"ShutdownICON\" caption=\"#1\" x=\"32\" y=\"32\" width=\"32\" height=\"32\" style=\"1342242819\" id=\"143\" />\n"
"</child>\n"
"</form>\n"
"</forms>\n"
"</gui>";
			return Application::getGuiDoc( xmlSrc );
		}
		return NULL;
	}


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
		InfoLabel=static_cast<winlib::Label*>(findChild(InfoLabel_id));
		ShutdownICON=static_cast<winlib::Label*>(findChild(ShutdownICON_id));
	}	// ShutdownFORM
}	// namespace winlibGUI
