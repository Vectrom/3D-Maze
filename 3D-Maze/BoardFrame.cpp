#include "BoardFrame.h"
#include <wx/dcbuffer.h>
#include <wx/msgdlg.h> 

BoardFrame::BoardFrame( wxWindow* parent ) : 
BaseBoardFrame( parent ), _parent(parent) {
	_amountOfBoxes = wxSize(10, 10);
	// loading images
	_redImg.LoadFile(wxT("Textures/RedWall.png"), wxBITMAP_TYPE_ANY);
	_greenImg.LoadFile(wxT("Textures/GreenWall.png"), wxBITMAP_TYPE_ANY);
	_blueImg.LoadFile(wxT("Textures/BlueWall.png"), wxBITMAP_TYPE_ANY);
	_startImg.LoadFile(wxT("Textures/Start.png"), wxBITMAP_TYPE_ANY);
	_endImg.LoadFile(wxT("Textures/End.png"), wxBITMAP_TYPE_ANY);
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
	_boxSize = wxSize(panelSize.x / _amountOfBoxes.x, panelSize.y / _amountOfBoxes.y);
	_translation = wxPoint((panelSize.x - _boxSize.x * _amountOfBoxes.x) / 2, (panelSize.y - _boxSize.y * _amountOfBoxes.y) / 2);
	_board.clear();
	for (int x = 0; x < _amountOfBoxes.x; x++) {
		std::vector<BoardBox> row;
		for (int y = 0; y < _amountOfBoxes.y; y++) {
			row.push_back(BoardBox(_floorImg, wxPoint(x * _boxSize.x, y * _boxSize.y)));
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
			buffDC.DrawBitmap(_board[x][y]._img.Scale(_boxSize.x, _boxSize.y), _board[x][y]._position + _translation);
		}
	}
}

void BoardFrame::onResize(wxSizeEvent& event) {
	Layout();
	draw();
}

void BoardFrame::update(wxUpdateUIEvent& event) {
	draw();
}

void BoardFrame::onLeftDown(wxMouseEvent& event) {
	wxPoint clickPosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	//_board[static_cast<int>((clickPosition.x - _translation.x) / _boxSize.x)][static_cast<int>((clickPosition.y - _translation.y)/ _boxSize.y)]._img = _currentImg;
	
	for (int x = 0; x < _amountOfBoxes.x; x++) {
		for (int y = 0; y < _amountOfBoxes.y; y++) {
			if (_board[x][y]._position.x + _translation.x < clickPosition.x && _board[x][y]._position.y + _translation.y < clickPosition.y &&
				_board[x][y]._position.x + _boxSize.x + _translation.x > clickPosition.x && _board[x][y]._position.y + _boxSize.y + _translation.y > clickPosition.y) {
				_board[x][y]._img = _currentImg;
				return;
			}
		}
	}
}

void BoardFrame::onMotion(wxMouseEvent& event) {
	//if (event.LeftIsDown()) {
	//	wxPoint mousePosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	//	for (int x = 0; x < _amountOfBoxes.x; x++) {
	//		for (int y = 0; y < _amountOfBoxes.y; y++) {
	//			if (_board[x][y]._position.x < mousePosition.x && _board[x][y]._position.y < mousePosition.y &&
	//				_board[x][y]._position.x + _boxSize.x > mousePosition.x && _board[x][y]._position.y + _boxSize.y > mousePosition.y) {
	//				_board[x][y]._img = _currentImg;
	//				return;
	//			}
	//		}
	//	}
	//}
}

void BoardFrame::setSizeButtonOnButtonClick(wxCommandEvent& event) {
	long x, y;

	// returns true on success
	bool tmp1 = _xBoxesText->GetValue().ToLong(&x);
	bool tmp2 = _yBoxesText->GetValue().ToLong(&y);

	if (!tmp1 || !tmp2 || x < 4 || x > 50 || y < 4 || y > 50) {
		wxMessageBox("You have entered invalid value. Correct value have to be between 4 and 50.", "Invalid input!", wxOK, this);
		return;
	}

	_amountOfBoxes = wxSize(x, y);
	prepareBoard();
}

void BoardFrame::startButtonOnButtonClick(wxCommandEvent& event) {
	_currentImg = _startImg;
}

void BoardFrame::endButtonOnButtonClick(wxCommandEvent& event) {
	_currentImg = _endImg;
}

void BoardFrame::redButtonOnButtonClick(wxCommandEvent& event) {
	_currentImg = _redImg;
}

void BoardFrame::greenButtonOnButtonClick(wxCommandEvent& event) {
	_currentImg = _greenImg;
}

void BoardFrame::blueButtonOnButtonClick(wxCommandEvent& event) {
	_currentImg = _blueImg;
}

void BoardFrame::loadButtonOnButtonClick(wxCommandEvent& event) {

}

void BoardFrame::saveButtonOnButtonClick(wxCommandEvent& event) {

}
