#include "PanelFrame.h"

PanelFrame::PanelFrame(wxWindow* parent, const std::vector<std::vector<char>> &worldMap) :
BasePanelFrame(parent), _parent(parent), _canvas(new Canvas(_drawingPanel, wxID_ANY, wxPoint(0, 0), wxSize(_drawingPanel->GetSize()), worldMap)) {
	Bind(wxEVT_SIZE, &PanelFrame::onResize, this);
}

void PanelFrame::onResize(wxSizeEvent & event) {
	_canvas->onResize(event);
	event.Skip();
}

void PanelFrame::FrameOnClose(wxCloseEvent& event) {
	_parent->Show(true);
	this->Destroy();
}

void PanelFrame::loadWorldMap(const std::vector<std::vector<char>>& worldMap) {
	_canvas->loadWorldMap(worldMap);
}

wxBEGIN_EVENT_TABLE(wxSfmlCanvas, wxControl)
EVT_IDLE(wxSfmlCanvas::onIdle)
EVT_PAINT(wxSfmlCanvas::onPaint)
EVT_ERASE_BACKGROUND(wxSfmlCanvas::onEraseBackground)
wxEND_EVENT_TABLE()