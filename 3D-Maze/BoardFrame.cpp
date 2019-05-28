#include "BoardFrame.h"

BoardFrame::BoardFrame( wxWindow* parent ) : 
BaseBoardFrame( parent ), _parent(parent) {
}

void BoardFrame::frameOnClose(wxCloseEvent& event) {
	_parent->Show(true);
	this->Destroy();
}

void BoardFrame::setSizeButtonOnButtonClick(wxCommandEvent& event) {
// TODO: Implement _setSizeButtonOnButtonClick
}

void BoardFrame::startButtonOnButtonClick(wxCommandEvent& event) {
// TODO: Implement _startButtonOnButtonClick
}

void BoardFrame::endButtonOnButtonClick(wxCommandEvent& event) {
// TODO: Implement _endButtonOnButtonClick
}

void BoardFrame::redButtonOnButtonClick(wxCommandEvent& event) {
// TODO: Implement _redButtonOnButtonClick
}

void BoardFrame::greenButtonOnButtonClick(wxCommandEvent& event) {
// TODO: Implement _greenButtonOnButtonClick
}

void BoardFrame::blueButtonOnButtonClick(wxCommandEvent& event) {
// TODO: Implement _blueButtonOnButtonClick
}

void BoardFrame::loadButtonOnButtonClick(wxCommandEvent& event) {
// TODO: Implement _loadButtonOnButtonClick
}

void BoardFrame::saveButtonOnButtonClick(wxCommandEvent& event) {
// TODO: Implement _saveButtonOnButtonClick
}
