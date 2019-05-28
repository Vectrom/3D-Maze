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
	void move(double moveSpeed, int multiplier);
	void rotate(double rotSpeed, int multiplier);
	void calculateStepAndSideDist(sf::Vector2<double> &sideDistance, sf::Vector2<int> &step, const sf::Vector2<double> &deltaDistance, const sf::Vector2<int> &mapBox, const sf::Vector2<double> &rayDirection);
	void findCollision(sf::Vector2<double> &sideDistance, const sf::Vector2<int> &step, const sf::Vector2<double> &deltaDistance, sf::Vector2<int> &mapBox, int &hit, int &side);
	sf::Color pickColor(const sf::Vector2<int> &mapBox, int side);

private:
	sf::Clock _clock;
	sf::Vector2<double> _direction; 
	sf::Vector2<double> _playerPosition;
	sf::Vector2<double> _end;
	sf::Vector2<double> _plane;
	double _time = 0.; 
	double _oldTime = 0.;
};

