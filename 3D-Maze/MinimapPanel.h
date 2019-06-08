#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "BaseMinimapPanel.h"

class MinimapPanel : public BaseMinimapPanel {
public:
	MinimapPanel(wxWindow* parent, const sf::Vector2<double>& playerPosition);
	void _minimapPanelOnEraseBackground(wxEraseEvent& event);
	void draw();

private:
	wxSize _boxSize;
	wxPoint _translation;
	const sf::Vector2<double>& _playerPosition;

	struct FieldBox {
		FieldBox(wxColour colour, wxPoint position) : _colour(colour), _position(position) {}
		wxColour _colour;
		wxPoint _position;
	};

	std::vector<std::vector<FieldBox>> _fields;
};