///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BaseFrame.h"

///////////////////////////////////////////////////////////////////////////

baseFrame::baseFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* panelBoxSizer;
	panelBoxSizer = new wxBoxSizer( wxVERTICAL );

	drawingPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelBoxSizer->Add( drawingPanel, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( panelBoxSizer );
	this->Layout();

	this->Centre( wxBOTH );
}

baseFrame::~baseFrame()
{
}