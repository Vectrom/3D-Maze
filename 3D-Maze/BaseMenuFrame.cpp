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
	menuSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* _buttonsSizer;
	_buttonsSizer = new wxBoxSizer( wxVERTICAL );

	_playButton = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 );
	_playButton->SetBackgroundColour( wxColour( 255, 0, 255 ) );
	_playButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _playButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_loadBoardButton = new wxButton( this, wxID_ANY, wxT("Load a board"), wxDefaultPosition, wxDefaultSize, 0 );
	_loadBoardButton->SetBackgroundColour( wxColour( 255, 0, 255 ) );
	_loadBoardButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _loadBoardButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_createBoardButton = new wxButton( this, wxID_ANY, wxT("Create your own board"), wxDefaultPosition, wxDefaultSize, 0 );
	_createBoardButton->SetBackgroundColour( wxColour( 255, 0, 255 ) );
	_createBoardButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _createBoardButton, 1, wxALIGN_CENTER|wxALL, 5 );

	_exitButton = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	_exitButton->SetBackgroundColour( wxColour( 255, 0, 255 ) );
	_exitButton->SetMinSize( wxSize( 150,30 ) );

	_buttonsSizer->Add( _exitButton, 1, wxALIGN_CENTER|wxALL, 5 );


	menuSizer->Add( _buttonsSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* _optionsSizer;
	_optionsSizer = new wxBoxSizer( wxVERTICAL );

	_FOVText = new wxStaticText( this, wxID_ANY, wxT("FOV: 66"), wxDefaultPosition, wxDefaultSize, 0 );
	_FOVText->Wrap( -1 );
	_FOVText->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	_FOVText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	_optionsSizer->Add( _FOVText, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	_FOVSlider = new wxSlider( this, wxID_ANY, 66, 45, 120, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	_optionsSizer->Add( _FOVSlider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	__minimapCheckBox = new wxCheckBox( this, wxID_ANY, wxT("Minimapa"), wxDefaultPosition, wxDefaultSize, 0 );
	__minimapCheckBox->SetValue(true);
	__minimapCheckBox->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	__minimapCheckBox->SetForegroundColour( wxColour( 255, 255, 255 ) );

	_optionsSizer->Add( __minimapCheckBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	menuSizer->Add( _optionsSizer, 1, wxEXPAND, 5 );


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
	__minimapCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseMenuFrame::__minimapCheckBoxOnCheckBox ), NULL, this );
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
	__minimapCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BaseMenuFrame::__minimapCheckBoxOnCheckBox ), NULL, this );

}
