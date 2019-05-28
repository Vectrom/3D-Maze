#pragma once

#include <wx/wx.h>
#include <vector>
#include <utility>
#include "wxSfmlCanvas.h"

class Canvas : public wxSfmlCanvas {
public:
	Canvas(wxWindow* parent, wxWindowID id, wxPoint position, wxSize size, long style = 0);
	void onResize(wxSizeEvent& event);
	virtual void onUpdate();	
	void setStartEnd();
	void drawMaze();

private:
	sf::Clock _clock;

	sf::Vector2<double> _direction; //initial direction vector
	sf::Vector2<double> _playerPosition;
	sf::Vector2<double> _end;
	sf::Vector2<double> _plane;
	double _time = 0.; //time of current frame
};

