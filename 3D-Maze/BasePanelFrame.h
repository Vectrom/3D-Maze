///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BasePanelFrame
///////////////////////////////////////////////////////////////////////////////
class BasePanelFrame : public wxFrame
{
	private:

	protected:
		wxPanel* _drawingPanel;

		// Virtual event handlers, overide them in your derived class
		virtual void frameOnClose( wxCloseEvent& event ) { event.Skip(); }


	public:

		BasePanelFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1024,800 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BasePanelFrame();

};

