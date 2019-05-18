#include <wx/wx.h>
#include <SFML/Graphics.hpp>
#include "MenuFrame.h"
#include "Settings.h"

class App : public wxApp {
public:
	virtual bool OnInit() {
		auto menu = new MenuFrame(nullptr);
		menu->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(App);