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
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/bmpbuttn.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BaseBoardFrame
///////////////////////////////////////////////////////////////////////////////
class BaseBoardFrame : public wxFrame
{
	private:

	protected:
		wxTextCtrl* _xBoxesText;
		wxTextCtrl* _yBoxesText;
		wxButton* _setSizeButton;
		wxBitmapButton* _redButton;
		wxBitmapButton* _greenButton;
		wxBitmapButton* _blueButton;
		wxBitmapButton* _startButton;
		wxBitmapButton* _endButton;
		wxButton* _loadButton;
		wxButton* _saveButton;
		wxPanel* _boardPanel;

		// Virtual event handlers, overide them in your derived class
		virtual void frameOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void onMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void onResize( wxSizeEvent& event ) { event.Skip(); }
		virtual void setSizeButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void redButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void greenButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void blueButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void startButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void endButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void loadButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void saveButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseBoardFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BaseBoardFrame();

};

