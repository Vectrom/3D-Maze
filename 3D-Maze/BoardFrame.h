#pragma once

#include "BaseBoardFrame.h"

class BoardFrame : public BaseBoardFrame {
public:
	BoardFrame(wxWindow* parent);

protected:
	void setSizeButtonOnButtonClick(wxCommandEvent& event);
	void startButtonOnButtonClick(wxCommandEvent& event);
	void endButtonOnButtonClick(wxCommandEvent& event);
	void redButtonOnButtonClick(wxCommandEvent& event);
	void greenButtonOnButtonClick(wxCommandEvent& event);
	void blueButtonOnButtonClick(wxCommandEvent& event);
	void loadButtonOnButtonClick(wxCommandEvent& event);
	void saveButtonOnButtonClick(wxCommandEvent& event);
	void frameOnClose(wxCloseEvent& event);

private:
	wxWindow *_parent;
};
