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
"<form name=\"ShutdownFORM\" style=\"277807104\" width=\"665\" height=\"220\" caption=\"Shutdown\" id=\"128\" baseClass=\"PopupWindow\">\n"
"<child type=\"FrameChild\" name=\"\" caption=\"\" x=\"8\" y=\"152\" width=\"640\" height=\"32\" style=\"1350696960\">\n"
"<layout x=\"0\" y=\"1\" paddingLeft=\"0\" paddingRight=\"0\" paddingTop=\"0\" paddingBottom=\"0\" attachment=\"3\" growWidth=\"1\" growHeight=\"0\" />\n"
"<layoutManager type=\"RowManager\" />\n"
"<child type=\"PushButton\" name=\"ShutdownPUSHBUTTON\" caption=\"&amp;Abschalten\" x=\"0\" y=\"0\" width=\"104\" height=\"16\" style=\"1342242816\" id=\"129\">\n"
"<layout paddingLeft=\"2\" paddingRight=\"2\" paddingTop=\"2\" paddingBottom=\"2\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"LogOffPUSHBUTTON\" caption=\"Ab&amp;melden\" x=\"112\" y=\"8\" width=\"96\" height=\"16\" style=\"1342242816\" id=\"130\">\n"
"<layout paddingLeft=\"2\" paddingRight=\"2\" paddingTop=\"2\" paddingBottom=\"2\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"LockPUSHBUTTON\" caption=\"&amp;Sperren\" x=\"216\" y=\"8\" width=\"96\" height=\"16\" style=\"1342242816\" id=\"131\">\n"
"<layout paddingLeft=\"2\" paddingRight=\"2\" paddingTop=\"2\" paddingBottom=\"2\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"RestartPUSHBUTTON\" caption=\"&amp;Neustart\" x=\"304\" y=\"0\" width=\"80\" height=\"16\" style=\"1342242816\" id=\"132\">\n"
"<layout paddingLeft=\"2\" paddingRight=\"2\" paddingTop=\"2\" paddingBottom=\"2\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"SuspendPUSHBUTTON\" caption=\"&amp;Energie sparen\" x=\"456\" y=\"8\" width=\"96\" height=\"16\" style=\"1342242816\" id=\"133\">\n"
"<layout paddingLeft=\"2\" paddingRight=\"2\" paddingTop=\"2\" paddingBottom=\"2\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"<child type=\"PushButton\" name=\"HibernatePUSHBUTTON\" caption=\"&amp;Ruhezustand\" x=\"568\" y=\"8\" width=\"96\" height=\"16\" style=\"1342242816\" id=\"134\">\n"
"<layout paddingLeft=\"2\" paddingRight=\"2\" paddingTop=\"2\" paddingBottom=\"2\" attachment=\"0\" growWidth=\"1\" growHeight=\"1\" />\n"
"</child>\n"
"</child>\n"
"<layoutManager type=\"AttachmentManager\" />\n"
"<child type=\"FrameChild\" name=\"\" caption=\"\" x=\"0\" y=\"0\" width=\"688\" height=\"224\" style=\"1342308352\">\n"
"<layout attachment=\"4\" growWidth=\"1\" growHeight=\"1\" />\n"
"<child type=\"FrameChild\" name=\"mainFRAME\" caption=\"\" x=\"312\" y=\"0\" width=\"336\" height=\"144\" style=\"1342308352\" id=\"138\">\n"
"<layout attachment=\"2\" growHeight=\"1\" />\n"
"<child type=\"Label\" name=\"\" caption=\"Zeit:\" x=\"16\" y=\"24\" width=\"24\" height=\"16\" style=\"1342242827\" />\n"
"<child type=\"Label\" name=\"TimeLABEL\" caption=\"00:00:00\" x=\"16\" y=\"64\" width=\"304\" height=\"72\" style=\"1342242827\" id=\"135\" font=\"Courier New;-64;0;0;0;400;0;0;0;0;3;2;1;49\" />\n"
"<child type=\"PushButton\" name=\"ClosePUSHBUTTON\" caption=\"&amp;Beenden\" x=\"240\" y=\"24\" width=\"80\" height=\"24\" style=\"1342242816\" id=\"136\" />\n"
"<child type=\"DateTimePicker\" name=\"DateTimePICKER\" caption=\"\" x=\"72\" y=\"24\" width=\"80\" height=\"24\" style=\"1342242825\" id=\"137\" />\n"
"</child>\n"
"<child type=\"Label\" name=\"ShutdownICON\" caption=\"#1\" x=\"32\" y=\"32\" width=\"32\" height=\"32\" style=\"1342242819\" id=\"139\" />\n"
"<child type=\"Label\" name=\"ActionLABEL\" caption=\"\" x=\"32\" y=\"80\" width=\"0\" height=\"0\" style=\"1342242827\" id=\"140\" font=\"Courier New;-24;0;0;0;400;0;0;0;0;3;2;1;49\" />\n"
"<layoutManager type=\"AttachmentManager\" />\n"
"<child type=\"Label\" name=\"InfoLabel\" caption=\"\" x=\"8\" y=\"128\" width=\"0\" height=\"0\" style=\"1342242827\" font=\"Courier New;-11;0;0;0;400;0;0;0;0;3;2;1;49\" id=\"141\" />\n"
"</child>\n"
"</form>\n"
"</forms>\n"
"<strings>\n"
"<list name=\"STRINGLIST\">\n"
"<string name=\"LogOFF\" caption=\"Abmelden\" id=\"142\" />\n"
"<string name=\"Shutdown\" caption=\"Abschalten\" id=\"143\" />\n"
"<string name=\"Restart\" caption=\"Neustart\" id=\"144\" />\n"
"<string name=\"Lock\" caption=\"Sperren\" id=\"145\" />\n"
"<string name=\"Suspend\" caption=\"Energie sparen\" id=\"146\" />\n"
"<string name=\"Hibernate\" caption=\"Ruhezustand\" id=\"147\" />\n"
"</list>\n"
"</strings>\n"
"</gui>";
			return Application::getGuiDoc( xmlSrc );
		}
		return doc;
	}


	void ShutdownFORM_form::getControls() {
		ShutdownPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(ShutdownPUSHBUTTON_id));
		LogOffPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(LogOffPUSHBUTTON_id));
		LockPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(LockPUSHBUTTON_id));
		RestartPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(RestartPUSHBUTTON_id));
		SuspendPUSHBUTTON=static_cast<winlib::PushButton*>(findChild(SuspendPUSHBUTTON_id));
		HibernatePUSHBUTTON=static_cast<winlib::PushButton*>(findChild(HibernatePUSHBUTTON_id));
		TimeLABEL=static_cast<winlib::Label*>(findChild(TimeLABEL_id));
		ClosePUSHBUTTON=static_cast<winlib::PushButton*>(findChild(ClosePUSHBUTTON_id));
		DateTimePICKER=static_cast<winlib::DateTimePicker*>(findChild(DateTimePICKER_id));
		mainFRAME=static_cast<winlib::FrameChild*>(findChild(mainFRAME_id));
		ShutdownICON=static_cast<winlib::Label*>(findChild(ShutdownICON_id));
		ActionLABEL=static_cast<winlib::Label*>(findChild(ActionLABEL_id));
		InfoLabel=static_cast<winlib::Label*>(findChild(InfoLabel_id));
	}	// ShutdownFORM
	const int STRINGLIST_ids[] = {
		LogOFF_id,
		Shutdown_id,
		Restart_id,
		Lock_id,
		Suspend_id,
		Hibernate_id,
	};
}	// namespace winlibGUI
