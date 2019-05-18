#include "PanelFrame.h"

PanelFrame::PanelFrame(wxWindow* parent) :
BaseFrame(parent), _canvas(new Canvas(_drawingPanel, wxID_ANY, wxPoint(0, 0), wxSize(_drawingPanel->GetSize()))) {
	Bind(wxEVT_SIZE, &PanelFrame::onResize, this);
}

void PanelFrame::onResize(wxSizeEvent & event) {
	_canvas->onResize(event);
	event.Skip();
}

wxBEGIN_EVENT_TABLE(wxSfmlCanvas, wxControl)
EVT_IDLE(wxSfmlCanvas::onIdle)
EVT_PAINT(wxSfmlCanvas::onPaint)
EVT_ERASE_BACKGROUND(wxSfmlCanvas::onEraseBackground)
wxEND_EVENT_TABLE()