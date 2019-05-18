#include <wx/wx.h>
#include <SFML/Graphics.hpp>
#include "AppFrame.h"
#include "Settings.h"

class App : public wxApp {
public:
	virtual bool OnInit() {
		auto frame = new AppFrame("SFML Canvas Demo", wxPoint(100, 100), wxSize(kDefaultWindowWidth, kDefaultWindowHeight));
		frame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(App);