#pragma once

#include <wx/wx.h>
#include <vector>
#include <utility>
#include "wxSfmlCanvas.h"


class Canvas : public wxSfmlCanvas {
public:
	Canvas(wxWindow* parent, wxWindowID id, wxPoint position, wxSize size, const std::vector<std::vector<char>> &worldMap, long style = 0);
	void onResize(wxSizeEvent& event);
	virtual void onUpdate();	
	void loadWorldMap(const std::vector<std::vector<char>> &worldMap);
	void setStartEnd();

private:
	sf::Clock _clock;
	std::vector<std::vector<char>> _worldMap;

	double _posX, _posY;  //x and y start position
	double _endX, _endY;
	double _dirX = -1., _dirY = 0.; //initial direction vector
	double _planeX = 0., _planeY = 0.66; //the 2d raycaster version of camera plane
	double _time = 0.; //time of current frame
};

