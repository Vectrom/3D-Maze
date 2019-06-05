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
	this->SetForegroundColour( wxColour( 89, 17, 17 ) );
	this->SetBackgroundColour( wxColour( 89, 17, 17 ) );

	wxBoxSizer* menuSizer;
	menuSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* _buttonsSizer;
	_buttonsSizer = new wxBoxSizer( wxVERTICAL );

	_playButton = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	_playButton->SetForegroundColour( wxColour( 242, 232, 0 ) );
	_playButton->SetBackgroundColour( wxColour( 17, 17, 89 ) );
	_playButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _playButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_loadBoardButton = new wxButton( this, wxID_ANY, wxT("Load a board"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	_loadBoardButton->SetForegroundColour( wxColour( 242, 232, 0 ) );
	_loadBoardButton->SetBackgroundColour( wxColour( 17, 17, 89 ) );
	_loadBoardButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _loadBoardButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_createBoardButton = new wxButton( this, wxID_ANY, wxT("Create your own board"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	_createBoardButton->SetForegroundColour( wxColour( 242, 232, 0 ) );
	_createBoardButton->SetBackgroundColour( wxColour( 17, 17, 89 ) );
	_createBoardButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _createBoardButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_helpButton = new wxButton( this, wxID_ANY, wxT("Help"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	_helpButton->SetForegroundColour( wxColour( 242, 232, 0 ) );
	_helpButton->SetBackgroundColour( wxColour( 17, 17, 89 ) );
	_helpButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _helpButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_exitButton = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	_exitButton->SetForegroundColour( wxColour( 242, 232, 0 ) );
	_exitButton->SetBackgroundColour( wxColour( 17, 17, 89 ) );
	_exitButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _exitButton, 1, wxALIGN_CENTER|wxALL, 5 );


	menuSizer->Add( _buttonsSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* _rightSizer;
	_rightSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* _optionsSizer;
	_optionsSizer = new wxBoxSizer( wxVERTICAL );


	_optionsSizer->Add( 0, 0, 1, wxEXPAND, 5 );

	_FOVText = new wxStaticText( this, wxID_ANY, wxT("FOV: 66"), wxDefaultPosition, wxDefaultSize, 0 );
	_FOVText->Wrap( -1 );
	_FOVText->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	_FOVText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	_optionsSizer->Add( _FOVText, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	_FOVSlider = new wxSlider( this, wxID_ANY, 66, 45, 120, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	_optionsSizer->Add( _FOVSlider, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	_optionsSizer->Add( 0, 0, 1, wxEXPAND, 5 );


	_rightSizer->Add( _optionsSizer, 1, wxALIGN_CENTER|wxEXPAND, 5 );

	wxBoxSizer* _infoSizer;
	_infoSizer = new wxBoxSizer( wxVERTICAL );


	_rightSizer->Add( _infoSizer, 1, wxEXPAND, 5 );


	menuSizer->Add( _rightSizer, 1, wxEXPAND, 5 );


	this->SetSizer( menuSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	_playButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_playButtonOnButtonClick ), NULL, this );
	_loadBoardButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_loadBoardButtonOnButtonClick ), NULL, this );
	_createBoardButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_createBoardButtonOnButtonClick ), NULL, this );
	_exitButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseMenuFrame::_exitButtonOnButtonClick ), NULL, this );
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
