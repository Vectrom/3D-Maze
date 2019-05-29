#include "BoardFrame.h"
#include <wx/dcbuffer.h>

BoardFrame::BoardFrame( wxWindow* parent ) : 
BaseBoardFrame( parent ), _parent(parent) {
	_amountOfBoxes = wxSize(10, 10);
	// loading images
	_redImg.LoadFile(wxT("Textures/Red.bmp"), wxBITMAP_TYPE_ANY);
	_greenImg.LoadFile(wxT("Textures/Green.bmp"), wxBITMAP_TYPE_ANY);
	_blueImg.LoadFile(wxT("Textures/Blue.bmp"), wxBITMAP_TYPE_ANY);
	_startImg.LoadFile(wxT("Textures/Start.bmp"), wxBITMAP_TYPE_ANY);
	_endImg.LoadFile(wxT("Textures/End.bmp"), wxBITMAP_TYPE_ANY);
	_floorImg.LoadFile(wxT("Textures/Floor.png"), wxBITMAP_TYPE_ANY);

	_currentImg = _redImg;
	prepareBoard();
	Refresh();
	Update();
}

void BoardFrame::frameOnClose(wxCloseEvent& event) {
	_parent->Show(true);
	this->Destroy();
}

void BoardFrame::prepareBoard() {
	wxSize panelSize(_boardPanel->GetSize().x, _boardPanel->GetSize().y);
	wxSize boxSize(panelSize.x / _amountOfBoxes.x, panelSize.y / _amountOfBoxes.y);
	_translation = wxPoint((panelSize.x - boxSize.x * _amountOfBoxes.x) / 2, (panelSize.y - boxSize.y * _amountOfBoxes.y) / 2);
	_board.clear();
	for (int x = 0; x < _amountOfBoxes.x; x++) {
		std::vector<BoardBox> row;
		for (int y = 0; y < _amountOfBoxes.y; y++) {
			row.push_back(BoardBox(_floorImg.Scale(boxSize.x, boxSize.y), wxPoint(x * boxSize.x, y * boxSize.y)));
		}
		_board.push_back(row);
	}
}

void BoardFrame::draw() {
	wxClientDC DC(_boardPanel);
	wxBufferedDC buffDC(&DC);
	buffDC.Clear();
	for (int x = 0; x < _amountOfBoxes.x; x++) {
		for (int y = 0; y < _amountOfBoxes.y; y++) {
			buffDC.DrawBitmap(_board[x][y]._bmp, _board[x][y]._position + _translation);
		}
	}
}

void BoardFrame::update(wxUpdateUIEvent& event) {
	draw();
}

void BoardFrame::setSizeButtonOnButtonClick(wxCommandEvent& event) {
	long x, y;
	// returns true on success
	bool tmp1 = _xBoxesText->GetValue().ToLong(&x);
	bool tmp2 = _yBoxesText->GetValue().ToLong(&y);
	if (!tmp1 || !tmp2) {
		//error
		return;
	}
	_amountOfBoxes = wxSize(x, y);
	prepareBoard();
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
