#include "AppFrame.h"
#include "Settings.h"

AppFrame::AppFrame(const wxString & title, const wxPoint & pos, const wxSize & size) :
	wxFrame(NULL, wxID_ANY, title, pos, size),
	_panel(new wxPanel(this)),
	_canvas(new Canvas(
		_panel.get(), 
		wxID_ANY, 
		wxPoint(kCanvasMargin, kCanvasMargin), 
		wxSize(kDefaultWindowWidth - (2 * kCanvasMargin), kDefaultWindowHeight - (2 * kCanvasMargin)))) {
	_panel->SetBackgroundColour(*wxCYAN);
	Bind(wxEVT_SIZE, &AppFrame::onResize, this);
}

void AppFrame::onResize(wxSizeEvent & event) {
	_canvas->onResize(event);
	event.Skip();
}

wxBEGIN_EVENT_TABLE(wxSfmlCanvas, wxControl)
EVT_IDLE(wxSfmlCanvas::onIdle)
EVT_PAINT(wxSfmlCanvas::onPaint)
EVT_ERASE_BACKGROUND(wxSfmlCanvas::onEraseBackground)
wxEND_EVENT_TABLE()