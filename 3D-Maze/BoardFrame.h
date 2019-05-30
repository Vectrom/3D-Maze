#pragma once

#include "BaseBoardFrame.h"
#include <vector>

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
	void onResize(wxSizeEvent& event);
	void onLeftDown(wxMouseEvent& event);
	void onRightDown(wxMouseEvent& event);
	void onMotion(wxMouseEvent& event);
	void prepareBoard();
	void updatePosition();
	void updateVariables();
	void draw();
	bool computeIndex(wxPoint &index, const wxPoint &position);

private:
	wxWindow *_parent;
	wxImage _redImg;
	wxImage _greenImg;
	wxImage _blueImg;
	wxImage _startImg;
	wxImage _endImg;
	wxImage _floorImg;
	wxImage _currentImg;
	wxSize _panelSize;
	wxSize _boxSize;
	wxSize _amountOfBoxes;
	wxPoint _translation;

	struct BoardBox {
		BoardBox(wxImage img, wxPoint pos = wxPoint(0, 0)) : _img(img), _position(pos) {}
		wxImage _img;
		wxPoint _position;
	};

	std::vector<std::vector<BoardBox>> _board;
};
