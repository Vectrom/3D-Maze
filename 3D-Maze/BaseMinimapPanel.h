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

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BaseMinimapPanel
///////////////////////////////////////////////////////////////////////////////
class BaseMinimapPanel : public wxPanel
{
	private:

	protected:
		wxPanel* _minimapPanel;

		// Virtual event handlers, overide them in your derived class
		virtual void _minimapPanelOnEraseBackground( wxEraseEvent& event ) { event.Skip(); }


	public:

		BaseMinimapPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,250 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~BaseMinimapPanel();

};

