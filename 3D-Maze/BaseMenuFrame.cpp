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


	leftPanelSizer->Add( 0, 0, 5, wxEXPAND, 5 );

	_playButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	_playButton->SetBitmap( wxBitmap( wxT("Textures/Play.bmp"), wxBITMAP_TYPE_ANY ) );
	_playButton->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	leftPanelSizer->Add( _playButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	_loadBoardButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	_loadBoardButton->SetBitmap( wxBitmap( wxT("Textures/LoadBoard.bmp"), wxBITMAP_TYPE_ANY ) );
	leftPanelSizer->Add( _loadBoardButton, 0, wxALL, 5 );

	_createBoardButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	_createBoardButton->SetBitmap( wxBitmap( wxT("Textures/CreateBoard.bmp"), wxBITMAP_TYPE_ANY ) );
	leftPanelSizer->Add( _createBoardButton, 0, wxALL, 5 );

	_exitButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	_exitButton->SetBitmap( wxBitmap( wxT("Textures/Exit.bmp"), wxBITMAP_TYPE_ANY ) );
	leftPanelSizer->Add( _exitButton, 0, wxALL, 5 );


	leftPanelSizer->Add( 0, 0, 10, wxEXPAND, 5 );

	wxBoxSizer* musicSizer;
	musicSizer = new wxBoxSizer( wxVERTICAL );

	_musicCheckBox = new wxCheckBox( this, wxID_ANY, wxT("Music"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	_musicCheckBox->SetValue(true);
	_musicCheckBox->SetFont( wxFont( 18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Andina") ) );
	_musicCheckBox->SetForegroundColour( wxColour( 255, 255, 255 ) );

	musicSizer->Add( _musicCheckBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	leftPanelSizer->Add( musicSizer, 1, wxEXPAND, 5 );


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


	menuSizer->Add( leftPanelSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* rightPanelSizer;
	rightPanelSizer = new wxBoxSizer( wxVERTICAL );

	_logo = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Textures/logo.bmp"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	rightPanelSizer->Add( _logo, 0, wxALL, 5 );

	wxBoxSizer* textSizer;
	textSizer = new wxBoxSizer( wxVERTICAL );

	_description = new wxStaticText( this, wxID_ANY, wxT("Welcome to the 3D-Maze game.\nYour goal is to find a way out in the shortest possible time.  Load existing mazes or create your own board. Move using \"wsad\" or arrows on the keyboard. Holding \"Shift\" multiplie your speed twice.  Click \"m\" during the game if you want to see the map."), wxDefaultPosition, wxSize( 500,-1 ), 0 );
	_description->Wrap( -1 );
	_description->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Andina") ) );
	_description->SetForegroundColour( wxColour( 255, 255, 255 ) );

	textSizer->Add( _description, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	_authors = new wxStaticText( this, wxID_ANY, wxT("Authors:"), wxDefaultPosition, wxDefaultSize, 0 );
	_authors->Wrap( -1 );
	_authors->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Andina") ) );
	_authors->SetForegroundColour( wxColour( 255, 255, 255 ) );

	textSizer->Add( _authors, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	_names = new wxStaticText( this, wxID_ANY, wxT("Konrad Malski | Radoslaw Leluk | Damian Plociennik"), wxDefaultPosition, wxDefaultSize, 0 );
	_names->Wrap( -1 );
	_names->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Andina") ) );
	_names->SetForegroundColour( wxColour( 255, 255, 255 ) );

	textSizer->Add( _names, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	rightPanelSizer->Add( textSizer, 1, wxEXPAND, 5 );


	menuSizer->Add( rightPanelSizer, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


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
