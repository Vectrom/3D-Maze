///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bmpbuttn.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BaseMenuFrame
///////////////////////////////////////////////////////////////////////////////
class BaseMenuFrame : public wxFrame
{
	private:

	protected:
		wxBitmapButton* _playButton;
		wxBitmapButton* _loadBoardButton;
		wxBitmapButton* _createBoardButton;
		wxBitmapButton* _exitButton;
		wxCheckBox* _musicCheckBox;
		wxStaticBitmap* _musicLabel;
		wxSlider* _FOVSlider;
		wxStaticText* _FOVText;
		wxStaticBitmap* _logo;
		wxStaticBitmap* _description;

		// Virtual event handlers, overide them in your derived class
		virtual void _playButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void _loadBoardButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void _createBoardButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void _exitButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void _musicCheckBoxOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void _FOVSliderOnScroll( wxScrollEvent& event ) { event.Skip(); }


	public:

		BaseMenuFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Maze 3D"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

		~BaseMenuFrame();

};

