#include <wx/textfile.h>
#include "MenuFrame.h"
#include "Settings.h"

MenuFrame::MenuFrame(wxWindow* parent)
:
BaseMenuFrame(parent),
_mapCreated(false)
{}

void MenuFrame::_playButtonOnButtonClick( wxCommandEvent& event ) {
	if (_mapCreated) {
		auto gamePanel = new PanelFrame(this);
		gamePanel->Show(true);
		this->Show(false);
	}
}

void MenuFrame::_loadBoardButtonOnButtonClick( wxCommandEvent& event ) {
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

	// clear vector when loads new map
	if (!Settings::worldMap.empty()) {
		Settings::worldMap.clear();
	}

	// load first line
	std::string str = txtFile.GetFirstLine().ToStdString();
	Settings::worldMap.push_back(std::vector<char>(str.begin(), str.end()));
	if (this->validateTextMaze(str) == false) {
		return;
	}

	// read all lines one by one until the end of the file
	while (!txtFile.Eof()) {
		str = txtFile.GetNextLine().ToStdString();
		if (!str.empty()) {
			Settings::worldMap.push_back(std::vector<char>(str.begin(), str.end()));
			if (!this->validateTextMaze(str)) {
				return;
			}
		}
	}
	_mapCreated = true;
}

void MenuFrame::_createBoardButtonOnButtonClick( wxCommandEvent& event ) {
// TODO: Implement _createBoardButtonOnButtonClick
}

void MenuFrame::_exitButtonOnButtonClick( wxCommandEvent& event ) {
	this->Destroy();
}

bool MenuFrame::validateTextMaze(const std::string &str) {
	if (str.front() == ' ' || str.back() == ' ') {
		_mapCreated = false;
		return false;
		//TODO: add some push notification or info
	}
	return true;
}

