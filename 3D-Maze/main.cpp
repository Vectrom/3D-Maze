#include <iostream>
#include <wx/wx.h>
#include <memory>
#include <SFML/Graphics.hpp>

#ifdef __WXGTK__
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#endif

using namespace std;

static const int kDefaultWindowWidth = 1280;
static const int kDefaultWindowHeight = 720;
static const int kCanvasMargin = 50;

struct wxSfmlCanvas : public wxControl, public sf::RenderWindow {
	wxSfmlCanvas(
		wxWindow *parent = nullptr,
		wxWindowID windowId = -1,
		const wxPoint &position = wxDefaultPosition,
		const wxSize &size = wxDefaultSize,
		long style = 0) :
		wxControl(parent, windowId, position, size, style) {
		createRenderWindow();
	}

	virtual void onUpdate() {};

	void onIdle(wxIdleEvent& event) {
		// Send a paint message when control is idle, to ensure max framerate
		Refresh();
	}

	void onPaint(wxPaintEvent& event) {
		wxPaintDC dc(this);     // Prepare control to be repainted
		onUpdate();             // Tick update
		display();              // Draw
	}

	// Explicitly overriding prevents wxWidgets from drawing, which could result in flicker
	void onEraseBackground(wxEraseEvent& event) {}

	void createRenderWindow() {
#ifdef __WXGTK__
		gtk_widget_realize(m_wxwindow);
		gtk_widget_set_double_buffered(m_wxwindow, false);

		GdkWindow *gdkWindow = gtk_widget_get_window((GtkWidget*)GetHandle());
		XFlush(GDK_WINDOW_XDISPLAY(gdkWindow));

		sf::RenderWindow::create(GDK_WINDOW_XWINDOW(gdkWindow));
#else
		sf::RenderWindow::create(GetHandle());
#endif
	}

	void setwxWindowSize(const wxSize& size) {
		this->SetSize(size);
	}

	void setRenderWindowSize(const sf::Vector2u& size) {
		this->setSize(size);
	}

	virtual ~wxSfmlCanvas() {};

	wxDECLARE_EVENT_TABLE();
};

struct Canvas : public wxSfmlCanvas {
	Canvas(
		wxWindow* parent,
		wxWindowID id,
		wxPoint position,
		wxSize size,
		long style = 0) :
		wxSfmlCanvas(parent, id, position, size, style) {}

	virtual void onUpdate() {
		clear(sf::Color::Yellow);

		// TODO: Do some sprite drawing or whatever
	}

	void onResize(wxSizeEvent& event) {
		auto size = event.GetSize();

		auto newCanvasWidth = size.x - (2 * kCanvasMargin);
		auto newCanvasHeight = size.y - (2 * kCanvasMargin);

		// Resize Canvas window
		this->setwxWindowSize({ newCanvasWidth, newCanvasHeight });
		this->setRenderWindowSize({ (unsigned int)newCanvasWidth, (unsigned int)newCanvasHeight });
	}
};

struct AppFrame : public wxFrame {
	AppFrame(const wxString& title, const wxPoint& pos, const wxSize& size) :
		wxFrame(NULL, wxID_ANY, title, pos, size),
		_panel(new wxPanel(this)),
		_canvas(new Canvas(
			_panel.get(),
			wxID_ANY,
			wxPoint(kCanvasMargin, kCanvasMargin),
			wxSize(kDefaultWindowWidth - (2 * kCanvasMargin), kDefaultWindowHeight - (2 * kCanvasMargin))
		)) {
		_panel->SetBackgroundColour(*wxCYAN);

		////////////////////////////////////////////////////////////////////////////////
		// Probably due to some RTTI, IDE is getting confused by this dynamic call
		// and doesn't understand the correct Bind overload. Causes non sequitur errors
		// to display in the inspector. Suppress.
		//
		// Dynamic binding is cleanest here, since we don't want to hook up our resize
		// handler until our dependencies (Canvas namely) have finished their initialization
		////////////////////////////////////////////////////////////////////////////////
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wint-conversion"
		Bind(wxEVT_SIZE, &AppFrame::onResize, this);
#pragma clang diagnostic pop
		////////////////////////////////////////////////////////////////////////////////

	}

	void onResize(wxSizeEvent& event) {
		_canvas->onResize(event);
		event.Skip();
	}

	unique_ptr<wxPanel> _panel;
	unique_ptr<Canvas> _canvas;
};

struct App : public wxApp {
	virtual bool OnInit() {
		auto frame = new AppFrame("SFML Canvas Demo", wxPoint(100, 100),
			wxSize(kDefaultWindowWidth, kDefaultWindowHeight));
		frame->Show(true);
		return true;
	}
};

wxBEGIN_EVENT_TABLE(wxSfmlCanvas, wxControl)
EVT_IDLE(wxSfmlCanvas::onIdle)
EVT_PAINT(wxSfmlCanvas::onPaint)
EVT_ERASE_BACKGROUND(wxSfmlCanvas::onEraseBackground)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(App);