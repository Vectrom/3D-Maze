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
	void update(wxUpdateUIEvent& event);
	void prepareBoard();
	void draw();

private:
	wxWindow *_parent;
	wxImage _redImg;
	wxImage _greenImg;
	wxImage _blueImg;
	wxImage _startImg;
	wxImage _endImg;
	wxImage _floorImg;
	wxImage _currentImg;
	wxSize _amountOfBoxes;

	struct BoardBox {
		BoardBox(wxBitmap bmp, wxPoint pos) : _bmp(bmp), _position(pos) {}
		wxBitmap _bmp;
		wxPoint _position;
	};

	std::vector<std::vector<BoardBox>> _board;
};
