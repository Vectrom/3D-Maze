#include <wx/dcbuffer.h>
#include "MinimapPanel.h"
#include "Settings.h"

MinimapPanel::MinimapPanel(wxWindow* parent) :
	BaseMinimapPanel(parent) {
	_floorImg.LoadFile(wxT("Textures/Floor.png"), wxBITMAP_TYPE_ANY);

	int sizeY = Settings::worldMap.size();
	int sizeX = Settings::worldMap[0].size();
	_boxSize = wxSize(GetSize().x / sizeX, GetSize().y / sizeY);
	_translation = wxPoint((GetSize().x - _boxSize.x * sizeX) / 2, (GetSize().y - _boxSize.y * sizeY) / 2);

	for (int x = 0; x < sizeX; x++) {
		std::vector<FieldBox> row;
		for (int y = 0; y < sizeY; y++)
			row.push_back(FieldBox(_floorImg, wxPoint(x * _boxSize.x, y * _boxSize.y)));

		_fields.push_back(row);
	}
	Layout();
	draw();
}

void MinimapPanel::draw() {
	int sizeY = Settings::worldMap.size();
	int sizeX = Settings::worldMap[0].size();

	wxClientDC DC(_minimapPanel);
	wxBufferedDC buffDC(&DC);
	buffDC.Clear();

	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			buffDC.DrawBitmap(_fields[x][y]._img.Scale(_boxSize.x, _boxSize.y), _fields[x][y]._position + _translation);
		}
	}
}