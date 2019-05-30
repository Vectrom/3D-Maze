#pragma once
#include "BaseMinimapPanel.h"
#include <vector>

class MinimapPanel : public BaseMinimapPanel {
public:
	MinimapPanel(wxWindow* parent);
	void draw();

private:
	wxSize _boxSize;
	wxPoint _translation;
	wxImage _floorImg;

	struct FieldBox {
		FieldBox(wxImage img, wxPoint pos = wxPoint(0, 0)) : _img(img), _position(pos) {}
		wxImage _img;
		wxPoint _position;
	};

	std::vector<std::vector<FieldBox>> _fields;
};