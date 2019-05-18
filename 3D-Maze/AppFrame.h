#pragma once

#include <iostream>
#include <memory>
#include <wx/wx.h>
#include <SFML/Graphics.hpp>
#include "Canvas.h"

class AppFrame : public wxFrame {
public:
	AppFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	void onResize(wxSizeEvent& event);

private:
	std::unique_ptr<wxPanel> _panel;
	std::unique_ptr<Canvas>  _canvas;
};

