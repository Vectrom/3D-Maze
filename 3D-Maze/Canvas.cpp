#include "Canvas.h"

Canvas::Canvas(wxWindow * parent, wxWindowID id, wxPoint position, wxSize size, long style) :
	wxSfmlCanvas(parent, id, position, size, style) {
}

void Canvas::onUpdate() {
	clear(sf::Color::Yellow);

	// TODO: Do some sprite drawing or whatever
}

void Canvas::onResize(wxSizeEvent & event) {
	auto size = event.GetSize();

	auto newCanvasWidth = size.x;
	auto newCanvasHeight = size.y;

	// Resize Canvas window
	this->setwxWindowSize({ newCanvasWidth, newCanvasHeight });
	this->setRenderWindowSize({ (unsigned int)newCanvasWidth, (unsigned int)newCanvasHeight });
}
