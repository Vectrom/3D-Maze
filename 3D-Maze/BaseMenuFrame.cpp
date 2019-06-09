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
	this->SetSizeHints( wxSize( 800,600 ), wxSize( 800,600 ) );
	this->SetBackgroundColour( wxColour( 48, 33, 77 ) );

	wxBoxSizer* menuSizer;
	menuSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* leftPanelSizer;
	leftPanelSizer = new wxBoxSizer( wxVERTICAL );


	leftPanelSizer->Add( 0, 0, 10, wxEXPAND, 5 );

	_playButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	_playButton->SetBitmap( wxBitmap( wxT("Textures/Play.bmp"), wxBITMAP_TYPE_ANY ) );
	_playButton->SetBitmapPressed( wxBitmap( wxT("Textures/PlayPressed.bmp"), wxBITMAP_TYPE_ANY ) );
	_playButton->SetBitmapCurrent( wxBitmap( wxT("Textures/PlayCurrent.bmp"), wxBITMAP_TYPE_ANY ) );
	_playButton->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	leftPanelSizer->Add( _playButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	_loadBoardButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	_loadBoardButton->SetBitmap( wxBitmap( wxT("Textures/LoadBoard.bmp"), wxBITMAP_TYPE_ANY ) );
	_loadBoardButton->SetBitmapPressed( wxBitmap( wxT("Textures/LoadBoardPressed.bmp"), wxBITMAP_TYPE_ANY ) );
	_loadBoardButton->SetBitmapCurrent( wxBitmap( wxT("Textures/LoadBoardCurrent.bmp"), wxBITMAP_TYPE_ANY ) );
	leftPanelSizer->Add( _loadBoardButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	_createBoardButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	_createBoardButton->SetBitmap( wxBitmap( wxT("Textures/CreateBoard.bmp"), wxBITMAP_TYPE_ANY ) );
	_createBoardButton->SetBitmapPressed( wxBitmap( wxT("Textures/CreateBoardPressed.bmp"), wxBITMAP_TYPE_ANY ) );
	_createBoardButton->SetBitmapCurrent( wxBitmap( wxT("Textures/CreateBoardCurrent.bmp"), wxBITMAP_TYPE_ANY ) );
	leftPanelSizer->Add( _createBoardButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	_exitButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	_exitButton->SetBitmap( wxBitmap( wxT("Textures/Exit.bmp"), wxBITMAP_TYPE_ANY ) );
	_exitButton->SetBitmapPressed( wxBitmap( wxT("Textures/ExitPressed.bmp"), wxBITMAP_TYPE_ANY ) );
	_exitButton->SetBitmapCurrent( wxBitmap( wxT("Textures/ExitCurrent.bmp"), wxBITMAP_TYPE_ANY ) );
	leftPanelSizer->Add( _exitButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	leftPanelSizer->Add( 0, 0, 5, wxEXPAND, 5 );

	wxBoxSizer* musicSizer;
	musicSizer = new wxBoxSizer( wxHORIZONTAL );

	_musicCheckBox = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	_musicCheckBox->SetValue(true);
	_musicCheckBox->SetFont( wxFont( 18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Andina") ) );
	_musicCheckBox->SetForegroundColour( wxColour( 255, 255, 255 ) );

	musicSizer->Add( _musicCheckBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	_musicLabel = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Textures/Music.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	musicSizer->Add( _musicLabel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	leftPanelSizer->Add( musicSizer, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	leftPanelSizer->Add( 0, 0, 3, wxEXPAND, 5 );

	wxBoxSizer* sliderSizer;
	sliderSizer = new wxBoxSizer( wxVERTICAL );

	_FOVSlider = new wxSlider( this, wxID_ANY, 66, 45, 120, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	sliderSizer->Add( _FOVSlider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	_FOVText = new wxStaticText( this, wxID_ANY, wxT("FOV: 66"), wxDefaultPosition, wxDefaultSize, 0 );
	_FOVText->Wrap( -1 );
	_FOVText->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Andina") ) );
	_FOVText->SetForegroundColour( wxColour( 255, 255, 255 ) );

	sliderSizer->Add( _FOVText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	leftPanelSizer->Add( sliderSizer, 1, wxEXPAND, 5 );


	leftPanelSizer->Add( 0, 0, 3, wxEXPAND, 5 );


	menuSizer->Add( leftPanelSizer, 3, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );


	menuSizer->Add( 0, 0, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* rightPanelSizer;
	rightPanelSizer = new wxBoxSizer( wxVERTICAL );

	_logo = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Textures/logo.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	rightPanelSizer->Add( _logo, 0, wxALL, 5 );

	_description = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Textures/Description.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	rightPanelSizer->Add( _description, 0, wxALL, 5 );


	menuSizer->Add( rightPanelSizer, 7, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	this->SetSizer( menuSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	_playButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_playButtonOnButtonClick ), NULL, this );
	_loadBoardButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_loadBoardButtonOnButtonClick ), NULL, this );
	_createBoardButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_createBoardButtonOnButtonClick ), NULL, this );
	_exitButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_exitButtonOnButtonClick ), NULL, this );
	_musicCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseMenuFrame::_musicCheckBoxOnCheckBox ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
}

BaseMenuFrame::~BaseMenuFrame()
{
	// Disconnect Events
	_playButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_playButtonOnButtonClick ), NULL, this );
	_loadBoardButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_loadBoardButtonOnButtonClick ), NULL, this );
	_createBoardButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_createBoardButtonOnButtonClick ), NULL, this );
	_exitButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_exitButtonOnButtonClick ), NULL, this );
	_musicCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseMenuFrame::_musicCheckBoxOnCheckBox ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );
	_FOVSlider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( BaseMenuFrame::_FOVSliderOnScroll ), NULL, this );

}
