#pragma once

#include "BaseBoardFrame.h"
#include <vector>

#define MAX_SIZE 40
#define MIN_SIZE 4

enum SIGN { FLOOR = ' ', RED = 'X', GREEN = 'Y', BLUE = 'Z', END = 'E', START = 'S' };

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
	void updateBox(const wxPoint &index, const wxImage &img, char sign);
	void prepareBoard();
	void updatePosition();
	void updateVariables();
	void draw();
	bool computeIndex(wxPoint &index, const wxPoint &position);
	void failedLoadingScheme(std::string);

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
	wxPoint _translation;
	char _currentSign;
	bool _isStart;
	bool _isEnd;
	int _rows;
	int _columns;

	struct BoardBox {
		BoardBox(wxImage img, char sign = SIGN::FLOOR, wxPoint pos = wxPoint(0, 0)) : _img(img), _sign(sign), _position(pos) {}
		wxImage _img;
		char _sign;
		wxPoint _position;
	};

	std::vector<std::vector<BoardBox>> _board;
};
