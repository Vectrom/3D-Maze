#pragma once

#include "BaseMenuFrame.h"

class MenuFrame : public BaseMenuFrame {
public:
	MenuFrame(wxWindow* parent);

protected:
	void _playButtonOnButtonClick(wxCommandEvent& event);
	void _loadBoardButtonOnButtonClick(wxCommandEvent& event);
	void _createBoardButtonOnButtonClick(wxCommandEvent& event);
	void _exitButtonOnButtonClick(wxCommandEvent& event);

};
