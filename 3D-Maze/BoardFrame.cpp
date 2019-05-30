#include "BoardFrame.h"
#include <wx/dcbuffer.h>
#include <wx/msgdlg.h> 
#include <wx/filedlg.h>
#include <wx/textfile.h>
#include "Settings.h"

BoardFrame::BoardFrame( wxWindow* parent ) : 
BaseBoardFrame( parent ), _parent(parent) {
	// loading images
	_redImg.LoadFile(wxT("Textures/RedWall.png"), wxBITMAP_TYPE_ANY);
	_greenImg.LoadFile(wxT("Textures/GreenWall.png"), wxBITMAP_TYPE_ANY);
	_blueImg.LoadFile(wxT("Textures/BlueWall.png"), wxBITMAP_TYPE_ANY);
	_startImg.LoadFile(wxT("Textures/Start.png"), wxBITMAP_TYPE_ANY);
	_endImg.LoadFile(wxT("Textures/End.png"), wxBITMAP_TYPE_ANY);
	_floorImg.LoadFile(wxT("Textures/Floor.png"), wxBITMAP_TYPE_ANY);

	_amountOfBoxes = wxSize(10, 10);
	_currentSign = SIGN::FLOOR;
	_currentImg = _redImg;
	_isStart = false;
	_isEnd = false;

	prepareBoard();
}

void BoardFrame::frameOnClose(wxCloseEvent& event) {
	_parent->Show(true);
	this->Destroy();
}

void BoardFrame::updateVariables() {
	_panelSize = wxSize(_boardPanel->GetSize().x, _boardPanel->GetSize().y);
	_boxSize = wxSize(_panelSize.x / _amountOfBoxes.x, _panelSize.y / _amountOfBoxes.y);
	_translation = wxPoint((_panelSize.x - _boxSize.x * _amountOfBoxes.x) / 2, (_panelSize.y - _boxSize.y * _amountOfBoxes.y) / 2);
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

void BoardFrame::prepareBoard() {
	updateVariables();
	_isStart = false;
	_isEnd = false;
	_board.clear();
	for (int x = 0; x < _amountOfBoxes.x; x++) {
		std::vector<BoardBox> row;
		for (int y = 0; y < _amountOfBoxes.y; y++) {
			row.push_back(BoardBox(_floorImg, SIGN::FLOOR, wxPoint(x * _boxSize.x, y * _boxSize.y)));
		}
		_board.push_back(row);
	}
	draw();
}

void BoardFrame::updatePosition() {
	updateVariables();
	for (int x = 0; x < _amountOfBoxes.x; x++) {
		for (int y = 0; y < _amountOfBoxes.y; y++) {
			_board[x][y]._position = wxPoint(x * _boxSize.x, y * _boxSize.y);
		}
	}
}

void BoardFrame::onResize(wxSizeEvent& event) {
	Layout();
	updatePosition();
	draw();
}

bool BoardFrame::computeIndex(wxPoint &index, const wxPoint &position) {
	if (position.x >= _amountOfBoxes.x * _boxSize.x + _translation.x || position.y >= _amountOfBoxes.y * _boxSize.y + _translation.y || position.x <= _translation.x || position.y <= _translation.y) return false;
	index = wxPoint(static_cast<int>((position.x - _translation.x) / _boxSize.x), static_cast<int>((position.y - _translation.y) / _boxSize.y));
	if (index.x > _amountOfBoxes.x - 1 || index.y > _amountOfBoxes.y - 1) return false;
	return true;
}

void BoardFrame::onLeftDown(wxMouseEvent& event) {
	if (_currentSign == SIGN::START && _isStart || _currentSign == SIGN::END && _isEnd) return;
	wxPoint mousePosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	wxPoint index;
	if (!computeIndex(index, mousePosition)) return;
	if (_currentSign == SIGN::START) _isStart = true;
	else if (_currentSign == SIGN::END) _isEnd = true;
	if (_board[index.x][index.y]._sign == SIGN::START) _isStart = false;
	else if (_board[index.x][index.y]._sign == SIGN::END) _isEnd = false;
	_board[index.x][index.y]._img = _currentImg;
	_board[index.x][index.y]._sign = _currentSign;
	draw();
}

void BoardFrame::onRightDown(wxMouseEvent& event) {
	wxPoint mousePosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	wxPoint index;
	if (!computeIndex(index, mousePosition)) return;
	if (_board[index.x][index.y]._sign == SIGN::START) _isStart = false;
	else if (_board[index.x][index.y]._sign == SIGN::END) _isEnd = false;
	_board[index.x][index.y]._img = _floorImg;
	_board[index.x][index.y]._sign = SIGN::FLOOR;
	draw();
}

void BoardFrame::onMotion(wxMouseEvent& event) {
	wxPoint mousePosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	wxPoint index;
	if (!computeIndex(index, mousePosition)) return;

	if (event.LeftIsDown()) {
		if (_currentSign == SIGN::START && _isStart || _currentSign == SIGN::END && _isEnd) return;
		if (_currentSign == SIGN::START) _isStart = true;
		else if (_currentSign == SIGN::END) _isEnd = true;
		if (_board[index.x][index.y]._sign == SIGN::START) _isStart = false;
		else if (_board[index.x][index.y]._sign == SIGN::END) _isEnd = false;
		_board[index.x][index.y]._img = _currentImg;
		_board[index.x][index.y]._sign = _currentSign;
		draw();
	}
	else if (event.RightIsDown()) {
		if (_board[index.x][index.y]._sign == SIGN::START) _isStart = false;
		else if (_board[index.x][index.y]._sign == SIGN::END) _isEnd = false;
		_board[index.x][index.y]._img = _floorImg;
		_board[index.x][index.y]._sign = SIGN::FLOOR;
		draw();
	}
}

void BoardFrame::setSizeButtonOnButtonClick(wxCommandEvent& event) {
	long x, y;

	// returns true on success
	bool tmp1 = _xBoxesText->GetValue().ToLong(&x);
	bool tmp2 = _yBoxesText->GetValue().ToLong(&y);

	if (!tmp1 || !tmp2 || x < 4 || x > 50 || y < 4 || y > 50) {
		wxMessageBox("You have entered invalid value! Correct value have to be between 4 and 50!", "Invalid input", wxOK, this);
		return;
	}

	_amountOfBoxes = wxSize(x, y);
	prepareBoard();
}

void BoardFrame::startButtonOnButtonClick(wxCommandEvent& event) {
	if (!_isStart) {
		_currentImg = _startImg;
		_currentSign = SIGN::START;
	}
}

void BoardFrame::endButtonOnButtonClick(wxCommandEvent& event) {
	if (!_isEnd) {
		_currentImg = _endImg;
		_currentSign = SIGN::END;
	}
}

void BoardFrame::redButtonOnButtonClick(wxCommandEvent& event) {
	_currentImg = _redImg;
	_currentSign = SIGN::RED;
}

void BoardFrame::greenButtonOnButtonClick(wxCommandEvent& event) {
	_currentImg = _greenImg;
	_currentSign = SIGN::GREEN;
}

void BoardFrame::blueButtonOnButtonClick(wxCommandEvent& event) {
	_currentImg = _blueImg;
	_currentSign = SIGN::BLUE;
}

void BoardFrame::loadButtonOnButtonClick(wxCommandEvent& event) {
	wxString filePath;
	wxFileDialog fileDialog(this, _("Open txt file"), "", "", "txt files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	// show file dialog and get the path to the file that was selected.
	if (fileDialog.ShowModal() != wxID_OK)
		return;

	// disabling play button 
	Settings::_mapCreated = false;

	filePath.Clear();
	filePath = fileDialog.GetPath();

	// open the file
	wxTextFile txtFile;
	txtFile.Open(filePath);

	_board.clear();

	// TODO: MERGE VALIDATION
	////////////////////////////////////////////////////////////// TEMPORARY ////////////////////////////////////////////////////////////////////////////////
	if (!Settings::worldMap.empty()) {
		Settings::worldMap.clear();
	}
	
	for (std::string str = txtFile.GetFirstLine().ToStdString(); !txtFile.Eof(); str = txtFile.GetNextLine().ToStdString()) {
		if (!str.empty()) {
			Settings::worldMap.push_back(std::vector<char>(str.begin(), str.end()));
		}
	}

	if (!Settings::validateMaze()) {
		wxMessageBox("Invalid maze scheme! Please choose file with correct scheme!", "Failed loading maze scheme", wxCENTRE | wxICON_ERROR | wxOK, this);
		return;
	}

	// checking map size
	wxSize mapSize(Settings::worldMap[0].size(), Settings::worldMap.size());
	if (mapSize.x < 4 || mapSize.x > 50 || mapSize.y < 4 || mapSize.y > 50) {
		wxMessageBox("Invalid maze size! Board creation accepts only mazes with sizes between 4 and 50.", "Failed loading maze scheme", wxCENTRE | wxICON_ERROR | wxOK, this);
		return;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// loading map
	for (std::string str = txtFile.GetFirstLine().ToStdString(); !txtFile.Eof(); str = txtFile.GetNextLine().ToStdString()) {
		if (!str.empty()) {
			std::vector<BoardBox> row;
			for (char &ele : str) {
				switch (ele) {
				case SIGN::RED:
					row.push_back(BoardBox(_redImg, SIGN::RED));
					break;
				case SIGN::GREEN:
					row.push_back(BoardBox(_greenImg, SIGN::GREEN));
					break;
				case SIGN::BLUE:
					row.push_back(BoardBox(_blueImg, SIGN::BLUE));
					break;
				case SIGN::START:
					row.push_back(BoardBox(_startImg, SIGN::START));
					break;
				case SIGN::END:
					row.push_back(BoardBox(_endImg, SIGN::END));
					break;
				default:
					row.push_back(BoardBox(_floorImg, SIGN::FLOOR));
					break;
				}
			}
			_board.push_back(row);
		}
	}

	_amountOfBoxes = wxSize(_board.size(), _board[0].size());

	// updating text
	_xBoxesText->SetValue(wxString::Format(wxT("%i"), _amountOfBoxes.x));
	_yBoxesText->SetValue(wxString::Format(wxT("%i"), _amountOfBoxes.y));

	updatePosition();
	draw();
}

void BoardFrame::saveButtonOnButtonClick(wxCommandEvent& event) {

}
