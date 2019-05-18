///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BaseMenuFrame
///////////////////////////////////////////////////////////////////////////////
class BaseMenuFrame : public wxFrame
{
	private:

	protected:
		wxButton* _playButton;
		wxButton* _loadBoardButton;
		wxButton* _createBoardButton;
		wxButton* _exitButton;

		// Virtual event handlers, overide them in your derived class
		virtual void _playButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void _loadBoardButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void _createBoardButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void _exitButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseMenuFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 200,600 ), long style = wxCAPTION|wxCLOSE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

		~BaseMenuFrame();

};
