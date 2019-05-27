#pragma once

#include "BaseMenuFrame.h"
#include "PanelFrame.h"
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

private:
	std::vector<std::vector<char>> _worldMap;
	bool _mapCreated;
	PanelFrame  *_gamePanel;
};
