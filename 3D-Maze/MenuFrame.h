#pragma once

#include "BaseMenuFrame.h"
#include "PanelFrame.h"
#include "BoardFrame.h"
#include <vector>
#include <memory>

class MenuFrame : public BaseMenuFrame {
public:
	MenuFrame(wxWindow* parent);

protected:
	void _playButtonOnButtonClick(wxCommandEvent& event);
	void _loadBoardButtonOnButtonClick(wxCommandEvent& event);
	void _createBoardButtonOnButtonClick(wxCommandEvent& event);
	void _exitButtonOnButtonClick(wxCommandEvent& event);
	void _FOVSliderOnScroll(wxScrollEvent& event);
	void _musicCheckBoxOnCheckBox(wxCommandEvent& event);
};
