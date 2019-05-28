#pragma once

#include <iostream>
#include <memory>
#include <wx/wx.h>
#include <SFML/Graphics.hpp>
#include "BasePanelFrame.h"
#include "Canvas.h"

class PanelFrame : public BasePanelFrame {
public:
	PanelFrame(wxWindow* parent);
	void onResize(wxSizeEvent& event);
	void frameOnClose(wxCloseEvent& event);

private:
	std::unique_ptr<Canvas>  _canvas;
	wxWindow *_parent;
};

