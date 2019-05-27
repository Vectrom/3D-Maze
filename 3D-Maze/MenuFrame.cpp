#include "MenuFrame.h"
#include <wx/textfile.h>

MenuFrame::MenuFrame(wxWindow* parent)
:
BaseMenuFrame(parent),
_mapCreated(false)
{}

void MenuFrame::_playButtonOnButtonClick( wxCommandEvent& event ) {
	if (_mapCreated) {
		_gamePanel = new PanelFrame(this);
		_gamePanel->loadWorldMap(_worldMap);
		_gamePanel->Show(true);
		this->Show(false);
	}
}

void MenuFrame::_loadBoardButtonOnButtonClick( wxCommandEvent& event ) {
	wxString filePath;
	wxFileDialog fileDialog(this);

	// show file dialog and get the path to the file that was selected.
	if (fileDialog.ShowModal() != wxID_OK) 
		return;
	filePath.Clear();
	filePath = fileDialog.GetPath();


	// open the file
	wxTextFile txtFile;
	txtFile.Open(filePath);

	std::string str = txtFile.GetFirstLine().ToStdString();
	_worldMap.push_back(std::vector<char>(str.begin(), str.end()));

	// read all lines one by one until the end of the file
	while (!txtFile.Eof()) {
		str = txtFile.GetNextLine().ToStdString();
		std::vector<char> line(str.begin(), str.end());
		_worldMap.push_back(line);
	}
	_mapCreated = true;
}

void MenuFrame::_createBoardButtonOnButtonClick( wxCommandEvent& event ) {
// TODO: Implement _createBoardButtonOnButtonClick
}

void MenuFrame::_exitButtonOnButtonClick( wxCommandEvent& event ) {
	this->Destroy();
}

