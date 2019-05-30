#include "BoardFrame.h"
#include <wx/dcbuffer.h>
#include <wx/msgdlg.h> 
#include <wx/filedlg.h>
#include <wx/textfile.h>
#include "Settings.h"

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

void BoardFrame::prepareBoard() {
	updateVariables();
	_board.clear();
	for (int x = 0; x < _amountOfBoxes.x; x++) {
		std::vector<BoardBox> row;
		for (int y = 0; y < _amountOfBoxes.y; y++) {
			row.push_back(BoardBox(_floorImg, wxPoint(x * _boxSize.x, y * _boxSize.y)));
		}
		_board.push_back(row);
	}
	draw();
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

void BoardFrame::onLeftDown(wxMouseEvent& event) {
	wxPoint clickPosition = event.GetLogicalPosition(wxClientDC(_boardPanel));
	//_board[static_cast<int>((clickPosition.x - _translation.x) / _boxSize.x)][static_cast<int>((clickPosition.y - _translation.y)/ _boxSize.y)]._img = _currentImg;
	
	for (int x = 0; x < _amountOfBoxes.x; x++) {
		for (int y = 0; y < _amountOfBoxes.y; y++) {
			if (_board[x][y]._position.x + _translation.x < clickPosition.x && _board[x][y]._position.y + _translation.y < clickPosition.y &&
				_board[x][y]._position.x + _boxSize.x + _translation.x > clickPosition.x && _board[x][y]._position.y + _boxSize.y + _translation.y > clickPosition.y) {
				_board[x][y]._img = _currentImg;
				draw();
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
	wxString filePath;
	wxFileDialog fileDialog(this, _("Open txt file"), "", "", "txt files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	// show file dialog and get the path to the file that was selected.
	if (fileDialog.ShowModal() != wxID_OK)
		return;
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
		wxMessageBox("Invalid maze scheme! Please choose file with correct scheme!", "Maze scheme fail", wxCENTRE | wxICON_ERROR | wxOK, this);
		return;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// loading map
	for (std::string str = txtFile.GetFirstLine().ToStdString(); !txtFile.Eof(); str = txtFile.GetNextLine().ToStdString()) {
		if (!str.empty()) {
			std::vector<BoardBox> row;
			for (char &ele : str) {
				switch (ele) {
				case 'X':
					row.push_back(BoardBox(_redImg));
					break;
				case 'Y':
					row.push_back(BoardBox(_greenImg));
					break;
				case 'Z':
					row.push_back(BoardBox(_blueImg));
					break;
				case 'S':
					row.push_back(BoardBox(_startImg));
					break;
				case 'E':
					row.push_back(BoardBox(_endImg));
					break;
				default:
					row.push_back(BoardBox(_floorImg));
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
