#include <wx/textfile.h>
#include "MenuFrame.h"
#include "Settings.h"

MenuFrame::MenuFrame(wxWindow* parent) :
BaseMenuFrame(parent) {
	Settings::mapCreated = false;
}

void MenuFrame::_playButtonOnButtonClick( wxCommandEvent& event ) {
	if (Settings::mapCreated) {
		auto gamePanel = new PanelFrame(this);
		gamePanel->Show(true);
		this->Show(false);
	}
	else {
		wxMessageBox("Please choose file with correct scheme!", "No maze scheme loaded", wxCENTRE | wxICON_ERROR | wxOK, this);
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

	for (std::string str = txtFile.GetFirstLine().ToStdString(); !txtFile.Eof(); str = txtFile.GetNextLine().ToStdString()) {
		if (!str.empty()) {
			Settings::worldMap.push_back(std::vector<char>(str.begin(), str.end()));
		}
	}

	Settings::mapCreated = Settings::validateMaze();
	if (!Settings::mapCreated) {
		wxMessageBox("Invalid maze scheme! Please choose file with correct scheme!", "Maze scheme fail", wxCENTRE | wxICON_ERROR | wxOK, this);
	}
}

void MenuFrame::_createBoardButtonOnButtonClick( wxCommandEvent& event ) {
	auto boardFrame = new BoardFrame(this);
	boardFrame->Show(true);
	this->Show(false);
}

void MenuFrame::_exitButtonOnButtonClick( wxCommandEvent& event ) {
	this->Destroy();
}

void MenuFrame::_FOVSliderOnScroll(wxScrollEvent & event) {
	int position = event.GetPosition();
	Settings::FOV = position;
	_FOVText->SetLabel("FOV: " + std::to_string(position));
}

void MenuFrame::_musicCheckBoxOnCheckBox(wxCommandEvent & event) {
	Settings::music = _musicCheckBox->GetValue();
}
