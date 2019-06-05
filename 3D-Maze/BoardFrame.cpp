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

	_rows = 10;
	_columns = 10;
	_currentSign = SIGN::RED;
	_currentImg = _redImg;
	_isStart = false;
	_isEnd = false;
	_boardChanged = false;

	prepareBoard();
}

void BoardFrame::frameOnClose(wxCloseEvent& event) {
	if (_boardChanged) {
		wxMessageDialog exitDialog(this, "Do you want to save the progress?", "Board has been changed", wxCENTRE | wxICON_EXCLAMATION | wxYES_NO | wxCANCEL);
		int id = exitDialog.ShowModal();
		if (id == wxID_YES) {
			saveButtonOnButtonClick(wxCommandEvent());
			return;
		}
		else if (id == wxID_CANCEL)
			return;
	}
	_parent->Show(true);
	this->Destroy();
}

void BoardFrame::updateVariables() {
	_panelSize = wxSize(_boardPanel->GetSize().x, _boardPanel->GetSize().y);
	_boxSize = wxSize(_panelSize.x / _columns, _panelSize.y / _rows);
	_translation = wxPoint((_panelSize.x - _boxSize.x * _columns) / 2, (_panelSize.y - _boxSize.y * _rows) / 2);
}

void BoardFrame::draw() {
	wxClientDC DC(_boardPanel);
	wxBufferedDC buffDC(&DC);
	buffDC.Clear();
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			buffDC.DrawBitmap(_board[i][j]._img.Scale(_boxSize.x, _boxSize.y), _board[i][j]._position + _translation);
		}
	}
}

void BoardFrame::prepareBoard() {
	updateVariables();
	_isStart = false;
	_isEnd = false;
	_board.clear();
	for (int i = 0; i < _rows; i++) {
		std::vector<BoardBox> row;
		for (int j = 0; j < _columns; j++) {
			row.push_back(BoardBox(_floorImg, SIGN::FLOOR, wxPoint(j * _boxSize.x, i * _boxSize.y)));
		}
		_board.push_back(row);
	}
	draw();
}

void BoardFrame::updatePosition() {
	updateVariables();
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			_board[i][j]._position = wxPoint(j * _boxSize.x, i * _boxSize.y);
		}
	}
}

void BoardFrame::onResize(wxSizeEvent& event) {
	Layout();
	updatePosition();
	draw();
}

bool BoardFrame::computeIndex(int &i, int &j, const wxPoint &position) {
	if (position.x >= _columns * _boxSize.x + _translation.x || position.y >= _rows * _boxSize.y + _translation.y || position.x <= _translation.x || position.y <= _translation.y) return false;
	i = static_cast<int>((position.y - _translation.y) / _boxSize.y);
	j = static_cast<int>((position.x - _translation.x) / _boxSize.x);
	if (j > _columns - 1 || i > _rows - 1) return false;
	return true;
}

void BoardFrame::updateBox(int i, int j, const wxImage &img, char sign) {
	if (_board[i][j]._sign == SIGN::START) _isStart = false;
	else if (_board[i][j]._sign == SIGN::END) _isEnd = false;
	_board[i][j]._img = img;
	_board[i][j]._sign = sign;
}

void BoardFrame::onLeftDown(wxMouseEvent& event) {
	if (!_boardChanged) _boardChanged = true;
	if (_currentSign == SIGN::START && _isStart || _currentSign == SIGN::END && _isEnd) return;
	wxPoint mousePosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	int i, j;
	if (!computeIndex(i, j, mousePosition)) return;
	if (_currentSign == SIGN::START) _isStart = true;
	else if (_currentSign == SIGN::END) _isEnd = true;
	updateBox(i, j, _currentImg, _currentSign);
	draw();
}

void BoardFrame::onRightDown(wxMouseEvent& event) {
	if (!_boardChanged) _boardChanged = true;
	wxPoint mousePosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	int i, j;
	if (!computeIndex(i, j, mousePosition)) return;
	updateBox(i, j, _floorImg, SIGN::FLOOR);
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
	long rows, columns;

	// returns true on success
	bool tmp1 = _rowsText->GetValue().ToLong(&rows);
	bool tmp2 = _columnsText->GetValue().ToLong(&columns);

	if (!tmp1 || !tmp2 || rows < MIN_SIZE || rows > MAX_SIZE || columns < MIN_SIZE || columns > MAX_SIZE) {
		wxMessageBox(wxString::Format("You have entered invalid value! Correct value have to be between %d and %d!", MIN_SIZE, MAX_SIZE), "Invalid input", wxOK, this);
		return;
	}

	_rows = rows;
	_columns = columns;
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

	_rows = _board.size();
	_columns = _board[0].size();
	if (_columns < MIN_SIZE || _columns > MAX_SIZE || _rows < MIN_SIZE || _rows > MAX_SIZE) {
		failedLoadingScheme(std::string(wxString::Format("Invalid size of the maze! Board creator accepts only mazes with size between %dx%d and %dx%d!", MIN_SIZE, MIN_SIZE, MAX_SIZE, MAX_SIZE)));
		return;
	}

	// updating text
	_rowsText->SetValue(wxString::Format(wxT("%i"), _columns));
	_columnsText->SetValue(wxString::Format(wxT("%i"), _rows));

	_boardChanged = false;
	updatePosition();
	draw();
}

void BoardFrame::saveButtonOnButtonClick(wxCommandEvent& event) {
	wxFileDialog saveDialog(this, _("Choose a file"), _(""), _(""), _("text files (*.txt)|*.txt"), wxFD_SAVE);
	if (saveDialog.ShowModal() == wxID_OK) {
		std::fstream file;
		file.open(std::string(saveDialog.GetPath()), std::ios::out);
		for (int i = 0; i < _rows; i++) {
			std::string str;
			str.clear();
			for (int j = 0; j < _columns; j++) {
				str += _board[i][j]._sign;
			}
			file << str << std::endl;
		}
		file.close();
		_boardChanged = false;
	}
}

void BoardFrame::exitButtonOnButtonClick(wxCommandEvent& event) {
	frameOnClose(wxCloseEvent());
}