///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BaseMenuFrame.h"

///////////////////////////////////////////////////////////////////////////

BaseMenuFrame::BaseMenuFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOTEXT ) );

	wxBoxSizer* menuSizer;
	menuSizer = new wxBoxSizer( wxVERTICAL );

	_playButton = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 );
	_playButton->SetBackgroundColour( wxColour( 255, 0, 255 ) );
	_playButton->SetMinSize( wxSize( 150,30 ) );

	menuSizer->Add( _playButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_loadBoardButton = new wxButton( this, wxID_ANY, wxT("Load a board"), wxDefaultPosition, wxDefaultSize, 0 );
	_loadBoardButton->SetBackgroundColour( wxColour( 255, 0, 255 ) );
	_loadBoardButton->SetMinSize( wxSize( 150,30 ) );

	menuSizer->Add( _loadBoardButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_createBoardButton = new wxButton( this, wxID_ANY, wxT("Create your own board"), wxDefaultPosition, wxDefaultSize, 0 );
	_createBoardButton->SetBackgroundColour( wxColour( 255, 0, 255 ) );
	_createBoardButton->SetMinSize( wxSize( 150,30 ) );

	menuSizer->Add( _createBoardButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_exitButton = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	_exitButton->SetBackgroundColour( wxColour( 255, 0, 255 ) );
	_exitButton->SetMinSize( wxSize( 150,30 ) );

	menuSizer->Add( _exitButton, 1, wxALIGN_CENTER|wxALL, 5 );


	this->SetSizer( menuSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	_playButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_playButtonOnButtonClick ), NULL, this );
	_loadBoardButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_loadBoardButtonOnButtonClick ), NULL, this );
	_createBoardButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_createBoardButtonOnButtonClick ), NULL, this );
	_exitButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_exitButtonOnButtonClick ), NULL, this );
}

BaseMenuFrame::~BaseMenuFrame()
{
	// Disconnect Events
	_playButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_playButtonOnButtonClick ), NULL, this );
	_loadBoardButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_loadBoardButtonOnButtonClick ), NULL, this );
	_createBoardButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_createBoardButtonOnButtonClick ), NULL, this );
	_exitButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_exitButtonOnButtonClick ), NULL, this );

}
