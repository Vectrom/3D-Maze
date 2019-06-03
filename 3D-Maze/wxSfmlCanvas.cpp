#include "wxSfmlCanvas.h"


wxSfmlCanvas::wxSfmlCanvas(wxWindow *parent, wxWindowID windowId, const wxPoint &position, const wxSize &size, long style)
	: wxControl(parent, windowId, position, size, style) {
	createRenderWindow();
}

void wxSfmlCanvas::onIdle(wxIdleEvent& event) {
	// Send a paint message when control is idle, to ensure max framerate
	Refresh();
}

void wxSfmlCanvas::onPaint(wxPaintEvent & event) {
	wxPaintDC dc(this);     // Prepare control to be repainted
	onUpdate();             // Tick update
	display();              // Draw
}

void wxSfmlCanvas::createRenderWindow() {
	sf::RenderWindow::create(GetHandle());
}
