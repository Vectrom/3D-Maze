#include "MenuFrame.h"
#include "PanelFrame.h"

MenuFrame::MenuFrame( wxWindow* parent )
:
BaseMenuFrame( parent )
{

}

void MenuFrame::_playButtonOnButtonClick( wxCommandEvent& event )
{
	auto menu = new PanelFrame(this);
	menu->Show(true);
	this->Show(false);
}

void MenuFrame::_loadBoardButtonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement _loadBoardButtonOnButtonClick
}

void MenuFrame::_createBoardButtonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement _createBoardButtonOnButtonClick
}

void MenuFrame::_exitButtonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement _exitButtonOnButtonClick
}