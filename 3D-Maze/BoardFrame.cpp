#include <wx/dcbuffer.h>
#include <wx/msgdlg.h> 
#include <wx/filedlg.h>
#include <wx/textfile.h>
#include <fstream>
#include "BoardFrame.h"
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

void BoardFrame::updateBox(const wxPoint &index, const wxImage &img, char sign) {
	if (_board[index.x][index.y]._sign == SIGN::START) _isStart = false;
	else if (_board[index.x][index.y]._sign == SIGN::END) _isEnd = false;
	_board[index.x][index.y]._img = img;
	_board[index.x][index.y]._sign = sign;
}

void BoardFrame::onLeftDown(wxMouseEvent& event) {
	if (_currentSign == SIGN::START && _isStart || _currentSign == SIGN::END && _isEnd) return;
	wxPoint mousePosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	wxPoint index;
	if (!computeIndex(index, mousePosition)) return;
	if (_currentSign == SIGN::START) _isStart = true;
	else if (_currentSign == SIGN::END) _isEnd = true;
	updateBox(index, _currentImg, _currentSign);
	draw();
}

void BoardFrame::onRightDown(wxMouseEvent& event) {
	wxPoint mousePosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	wxPoint index;
	if (!computeIndex(index, mousePosition)) return;
	updateBox(index, _floorImg, SIGN::FLOOR);
	draw();
}

void BoardFrame::onMotion(wxMouseEvent& event) {
	if (event.LeftIsDown()) {
		onLeftDown(event);
	}
	else if (event.RightIsDown()) {
		onRightDown(event);
	}
}

void BoardFrame::setSizeButtonOnButtonClick(wxCommandEvent& event) {
	long x, y;

	// returns true on success
	bool tmp1 = _xBoxesText->GetValue().ToLong(&x);
	bool tmp2 = _yBoxesText->GetValue().ToLong(&y);

	if (!tmp1 || !tmp2 || x < MIN_SIZE || x > MAX_SIZE || y < MIN_SIZE || y > MAX_SIZE) {
		wxMessageBox(wxString::Format("You have entered invalid value! Correct value have to be between %d and %d!", MIN_SIZE, MAX_SIZE), "Invalid input", wxOK, this);
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

void BoardFrame::failedLoadingScheme(std::string info) {
	wxMessageBox(info, "Failed loading maze scheme", wxCENTRE | wxICON_ERROR | wxOK, this);
	_board.clear();
}

void BoardFrame::loadButtonOnButtonClick(wxCommandEvent& event) {
	wxString filePath;
	wxFileDialog fileDialog(this, _("Open txt file"), "", "", "txt files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	// show file dialog and get the path to the file that was selected.
	if (fileDialog.ShowModal() != wxID_OK)
		return;

	// disabling play button 
	Settings::mapCreated = false;

	filePath.Clear();
	filePath = fileDialog.GetPath();

	// open the file
	wxTextFile txtFile;
	txtFile.Open(filePath);

	_board.clear();

	_isStart = _isEnd = false;

	// loading map; loads only first encountered start box, converts the rest of the start boxes to floor boxes (same for end box)
	// the maze map have to be rectangular
	std::string str;
	int size;
	for (str = txtFile.GetFirstLine().ToStdString(), size = str.length(); !txtFile.Eof(); str = txtFile.GetNextLine().ToStdString()) {
		if(str.length() != size) {
			failedLoadingScheme("Maze has invalid size! Maze map have to be rectangular!");
			return;
		}
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
				if (!_isStart) {
					row.push_back(BoardBox(_startImg, SIGN::START));
					_isStart = true;
				}
				else {
					row.push_back(BoardBox(_floorImg, SIGN::FLOOR));
				}
				break;
			case SIGN::END:
				if (!_isEnd) {
					row.push_back(BoardBox(_endImg, SIGN::END));
					_isEnd = true;
				}
				else {
					row.push_back(BoardBox(_floorImg, SIGN::FLOOR));
				}
				break;
			case SIGN::FLOOR:
				row.push_back(BoardBox(_floorImg, SIGN::FLOOR));
				break;
			default:
				failedLoadingScheme("Maze scheme contains invalid signs!");
				return;
			}
		}
		_board.push_back(row);
	}

	_amountOfBoxes = wxSize(_board.size(), _board[0].size());
	if (_amountOfBoxes.x < MIN_SIZE || _amountOfBoxes.x > MAX_SIZE || _amountOfBoxes.y < MIN_SIZE || _amountOfBoxes.y > MAX_SIZE) {
		failedLoadingScheme(std::string(wxString::Format("Invalid size of the maze! Board creator accepts only mazes with size between %dx%d and %dx%d!", MIN_SIZE, MIN_SIZE, MAX_SIZE, MAX_SIZE)));
		return;
	}

	// updating text
	_xBoxesText->SetValue(wxString::Format(wxT("%i"), _amountOfBoxes.x));
	_yBoxesText->SetValue(wxString::Format(wxT("%i"), _amountOfBoxes.y));

	updatePosition();
	draw();
}

void BoardFrame::saveButtonOnButtonClick(wxCommandEvent& event) {
	wxFileDialog saveDialog(this, _("Choose a file"), _(""), _(""), _("text files (*.txt)|*.txt"), wxFD_SAVE);
	if (saveDialog.ShowModal() == wxID_OK) {
		std::fstream file;
		file.open(std::string(saveDialog.GetPath()), std::ios::out);
		for (int x = 0; x < _amountOfBoxes.x; x++) {
			std::string str;
			str.clear();
			for (int y = 0; y < _amountOfBoxes.y; y++) {
				str += _board[x][y]._sign;
			}
			file << str << std::endl;
		}
		file.close();
	}
}
