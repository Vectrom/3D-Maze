///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BaseBoardFrame.h"

///////////////////////////////////////////////////////////////////////////

BaseBoardFrame::BaseBoardFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,600 ), wxSize( -1,-1 ) );
	this->SetForegroundColour( wxColour( 153, 115, 0 ) );
	this->SetBackgroundColour( wxColour( 153, 77, 0 ) );

	wxBoxSizer* _mainSizer;
	_mainSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* _controlsSizer;
	_controlsSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	_xBoxesText = new wxTextCtrl( this, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer4->Add( _xBoxesText, 0, wxALL, 5 );

	_yBoxesText = new wxTextCtrl( this, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer4->Add( _yBoxesText, 0, wxALL, 5 );


	_controlsSizer->Add( bSizer4, 0, wxALIGN_CENTER, 5 );

	_setSizeButton = new wxButton( this, wxID_ANY, wxT("Set size"), wxPoint( -1,-1 ), wxDefaultSize, wxBORDER_NONE );
	_setSizeButton->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	_setSizeButton->SetBackgroundColour( wxColour( 153, 115, 0 ) );

	_controlsSizer->Add( _setSizeButton, 0, wxALIGN_CENTER|wxALL, 5 );


	_controlsSizer->Add( 120, 0, 6, wxEXPAND, 5 );

	wxBoxSizer* _colorBoxesSizer;
	_colorBoxesSizer = new wxBoxSizer( wxVERTICAL );

	_redButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	_redButton->SetBitmap( wxBitmap( wxT("Textures/Red.png"), wxBITMAP_TYPE_ANY ) );
	_redButton->SetBitmapPressed( wxBitmap( wxT("Textures/RedPressed.png"), wxBITMAP_TYPE_ANY ) );
	_redButton->SetBitmapCurrent( wxBitmap( wxT("Textures/RedCurrent.png"), wxBITMAP_TYPE_ANY ) );
	_redButton->SetMinSize( wxSize( 50,50 ) );

	_colorBoxesSizer->Add( _redButton, 0, wxALIGN_CENTER|wxALL, 5 );

	_greenButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	_greenButton->SetBitmap( wxBitmap( wxT("Textures/Green.png"), wxBITMAP_TYPE_ANY ) );
	_greenButton->SetBitmapPressed( wxBitmap( wxT("Textures/GreenPressed.png"), wxBITMAP_TYPE_ANY ) );
	_greenButton->SetBitmapCurrent( wxBitmap( wxT("Textures/GreenCurrent.png"), wxBITMAP_TYPE_ANY ) );
	_greenButton->SetMinSize( wxSize( 50,50 ) );

	_colorBoxesSizer->Add( _greenButton, 0, wxALIGN_CENTER|wxALL, 5 );

	_blueButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	_blueButton->SetBitmap( wxBitmap( wxT("Textures/Blue.png"), wxBITMAP_TYPE_ANY ) );
	_blueButton->SetBitmapPressed( wxBitmap( wxT("Textures/BluePressed.png"), wxBITMAP_TYPE_ANY ) );
	_blueButton->SetBitmapCurrent( wxBitmap( wxT("Textures/BlueCurrent.png"), wxBITMAP_TYPE_ANY ) );
	_blueButton->SetMinSize( wxSize( 50,50 ) );

	_colorBoxesSizer->Add( _blueButton, 0, wxALIGN_CENTER|wxALL, 5 );

	_startButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|0 );

	_startButton->SetBitmap( wxBitmap( wxT("Textures/Start.png"), wxBITMAP_TYPE_ANY ) );
	_startButton->SetBitmapPressed( wxBitmap( wxT("Textures/StartPressed.png"), wxBITMAP_TYPE_ANY ) );
	_startButton->SetBitmapCurrent( wxBitmap( wxT("Textures/StartCurrent.png"), wxBITMAP_TYPE_ANY ) );
	_startButton->SetMinSize( wxSize( 50,50 ) );

	_colorBoxesSizer->Add( _startButton, 0, wxALIGN_CENTER|wxALL, 5 );

	_endButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	_endButton->SetBitmap( wxBitmap( wxT("Textures/End.png"), wxBITMAP_TYPE_ANY ) );
	_endButton->SetBitmapPressed( wxBitmap( wxT("Textures/EndPressed.png"), wxBITMAP_TYPE_ANY ) );
	_endButton->SetBitmapCurrent( wxBitmap( wxT("Textures/EndCurrent.png"), wxBITMAP_TYPE_ANY ) );
	_endButton->SetMinSize( wxSize( 50,50 ) );

	_colorBoxesSizer->Add( _endButton, 0, wxALIGN_CENTER|wxALL, 5 );


	_controlsSizer->Add( _colorBoxesSizer, 1, wxALIGN_BOTTOM|wxEXPAND, 5 );


	_controlsSizer->Add( 120, 0, 6, wxEXPAND, 5 );

	wxBoxSizer* _SLSizer;
	_SLSizer = new wxBoxSizer( wxVERTICAL );

	_loadButton = new wxButton( this, wxID_ANY, wxT("Save board"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	_loadButton->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	_loadButton->SetBackgroundColour( wxColour( 153, 115, 0 ) );

	_SLSizer->Add( _loadButton, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	_saveButton = new wxButton( this, wxID_ANY, wxT("Load board"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	_saveButton->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	_saveButton->SetBackgroundColour( wxColour( 153, 115, 0 ) );

	_SLSizer->Add( _saveButton, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	_controlsSizer->Add( _SLSizer, 1, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	_mainSizer->Add( _controlsSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* _boardSizer;
	_boardSizer = new wxBoxSizer( wxVERTICAL );

	_boardPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	_boardPanel->SetBackgroundColour( wxColour( 153, 77, 0 ) );

	_boardSizer->Add( _boardPanel, 1, wxEXPAND | wxALL, 5 );


	_mainSizer->Add( _boardSizer, 1, wxALIGN_CENTER|wxEXPAND, 5 );


	this->SetSizer( _mainSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( BaseBoardFrame::frameOnClose ) );
	this->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BaseBoardFrame::onLeftDown ) );
	this->Connect( wxEVT_MOTION, wxMouseEventHandler( BaseBoardFrame::onMotion ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( BaseBoardFrame::onResize ) );
	_setSizeButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::setSizeButtonOnButtonClick ), NULL, this );
	_redButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::redButtonOnButtonClick ), NULL, this );
	_greenButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::greenButtonOnButtonClick ), NULL, this );
	_blueButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::blueButtonOnButtonClick ), NULL, this );
	_startButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::startButtonOnButtonClick ), NULL, this );
	_endButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::endButtonOnButtonClick ), NULL, this );
	_loadButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::saveButtonOnButtonClick ), NULL, this );
	_saveButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::loadButtonOnButtonClick ), NULL, this );
	_boardPanel->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BaseBoardFrame::onLeftDown ), NULL, this );
}

BaseBoardFrame::~BaseBoardFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( BaseBoardFrame::frameOnClose ) );
	this->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BaseBoardFrame::onLeftDown ) );
	this->Disconnect( wxEVT_MOTION, wxMouseEventHandler( BaseBoardFrame::onMotion ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( BaseBoardFrame::onResize ) );
	_setSizeButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::setSizeButtonOnButtonClick ), NULL, this );
	_redButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::redButtonOnButtonClick ), NULL, this );
	_greenButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::greenButtonOnButtonClick ), NULL, this );
	_blueButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::blueButtonOnButtonClick ), NULL, this );
	_startButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::startButtonOnButtonClick ), NULL, this );
	_endButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::endButtonOnButtonClick ), NULL, this );
	_loadButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::saveButtonOnButtonClick ), NULL, this );
	_saveButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseBoardFrame::loadButtonOnButtonClick ), NULL, this );
	_boardPanel->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BaseBoardFrame::onLeftDown ), NULL, this );

}
