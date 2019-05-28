///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BasePanelFrame.h"

///////////////////////////////////////////////////////////////////////////

BasePanelFrame::BasePanelFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->Hide();

	wxBoxSizer* panelBoxSizer;
	panelBoxSizer = new wxBoxSizer( wxVERTICAL );

	_drawingPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelBoxSizer->Add( _drawingPanel, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( panelBoxSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( BasePanelFrame::frameOnClose ) );
}

BasePanelFrame::~BasePanelFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( BasePanelFrame::frameOnClose ) );

}
