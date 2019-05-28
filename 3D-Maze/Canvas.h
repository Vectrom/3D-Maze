#pragma once

#include <wx/wx.h>
#include <vector>
#include "wxSfmlCanvas.h"


class Canvas : public wxSfmlCanvas {
public:
	Canvas(wxWindow* parent, wxWindowID id, wxPoint position, wxSize size, long style = 0);
	void onResize(wxSizeEvent& event);
	virtual void onUpdate();	
	void loadWorldMap(const std::vector<std::vector<char>> &worldMap);

private:
	sf::Clock clock;
	std::vector<std::vector<char>> _worldMap;

	double posX = 22., posY = 12.;  //x and y start position
	double dirX = -1., dirY = 0.; //initial direction vector
	double planeX = 0., planeY = 0.66; //the 2d raycaster version of camera plane
	double time = 0.; //time of current frame
};

