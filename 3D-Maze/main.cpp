#include <wx/wx.h>
#include <SFML/Graphics.hpp>
#include "PanelFrame.h"
#include "Settings.h"

class App : public wxApp {
public:
	virtual bool OnInit() {
		auto frame = new PanelFrame(nullptr);
		frame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(App);