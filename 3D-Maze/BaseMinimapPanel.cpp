///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BaseMinimapPanel.h"

///////////////////////////////////////////////////////////////////////////

BaseMinimapPanel::BaseMinimapPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->Hide();

	wxBoxSizer* _sizer;
	_sizer = new wxBoxSizer( wxVERTICAL );

	_minimapPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	_sizer->Add( _minimapPanel, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( _sizer );
	this->Layout();
}

BaseMinimapPanel::~BaseMinimapPanel()
{
}
