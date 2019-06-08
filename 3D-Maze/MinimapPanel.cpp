#include <wx/dcbuffer.h>
#include "MinimapPanel.h"
#include "Settings.h"

MinimapPanel::MinimapPanel(wxWindow* parent, const sf::Vector2<double>& playerPosition) :
	_playerPosition(playerPosition),
	BaseMinimapPanel(parent) {
	
	int sizeY = Settings::worldMap.size();
	int sizeX = Settings::worldMap[0].size();
	_boxSize = wxSize(GetSize().x / sizeX, GetSize().y / sizeY);
	_translation = wxPoint((GetSize().x - _boxSize.x * sizeX) / 2, (GetSize().y - _boxSize.y * sizeY) / 2);

	for (int x = 0; x < sizeX; x++) {
		std::vector<FieldBox> row;
		for (int y = 0; y < sizeY; y++) {
			switch (Settings::worldMap[y][x]) {
			case 'X':
				row.push_back(FieldBox(wxColour(100, 0, 0), wxPoint(x * _boxSize.x, y * _boxSize.y)));
				break;
			case 'Y':
				row.push_back(FieldBox(wxColour(0, 100, 0), wxPoint(x * _boxSize.x, y * _boxSize.y)));
				break;
			case 'Z':
				row.push_back(FieldBox(wxColour(0, 0, 100), wxPoint(x * _boxSize.x, y * _boxSize.y)));
				break;
			/*case 'S':
				row.push_back(FieldBox(wxColour(55, 123, 43), wxPoint(x * _boxSize.x, y * _boxSize.y)));
				break;*/
			case 'E':
				row.push_back(FieldBox(wxColour(247, 202, 68), wxPoint(x * _boxSize.x, y * _boxSize.y)));
				break;
			default:
				row.push_back(FieldBox(wxColour(255, 255, 255), wxPoint(x * _boxSize.x, y * _boxSize.y)));
				break;
			}
		}
		_fields.push_back(row);
	}

}

void MinimapPanel::_minimapPanelOnEraseBackground(wxEraseEvent& event) {}

void MinimapPanel::draw() {
	int sizeY = Settings::worldMap.size();
	int sizeX = Settings::worldMap[0].size();

	wxClientDC DC(_minimapPanel);
	wxBufferedDC buffDC(&DC);
	buffDC.Clear();

	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			buffDC.SetPen(wxPen(_fields[x][y]._colour));
			buffDC.SetBrush(wxBrush(_fields[x][y]._colour));
			buffDC.DrawRectangle(_fields[x][y]._position + _translation, _boxSize);
		}
	}
	buffDC.SetPen(wxPen(wxColour(255, 20, 147)));
	buffDC.SetBrush(wxBrush(wxColour(255, 20, 147)));
	buffDC.DrawCircle(wxPoint(_playerPosition.y * _boxSize.x, _playerPosition.x * _boxSize.y) + _translation, 5);
}