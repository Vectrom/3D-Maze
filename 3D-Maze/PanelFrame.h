#pragma once

#include <iostream>
#include <memory>
#include <wx/wx.h>
#include <SFML/Graphics.hpp>
#include "BasePanelFrame.h"
#include "Canvas.h"

class PanelFrame : public BasePanelFrame {
public:
	PanelFrame(wxWindow* parent, const std::vector<std::vector<char>> &worldMap);
	void onResize(wxSizeEvent& event);
	void FrameOnClose(wxCloseEvent& event);
	void loadWorldMap(const std::vector<std::vector<char>> &worldMap);

private:
	std::unique_ptr<Canvas>  _canvas;
	wxWindow *_parent;
};

