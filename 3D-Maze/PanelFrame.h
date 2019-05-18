#pragma once

#include <iostream>
#include <memory>
#include <wx/wx.h>
#include <SFML/Graphics.hpp>
#include "BaseFrame.h"
#include "Canvas.h"

class PanelFrame : public BaseFrame {
public:
	PanelFrame(wxWindow* parent);
	void onResize(wxSizeEvent& event);

private:
	std::unique_ptr<Canvas>  _canvas;
};

