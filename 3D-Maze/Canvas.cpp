#include "Canvas.h"
#include <SFML/Graphics.hpp>


Canvas::Canvas(wxWindow * parent, wxWindowID id, wxPoint position, wxSize size, const std::vector<std::vector<char>> &worldMap, long style) :
	wxSfmlCanvas(parent, id, position, size, style), 
	_worldMap(worldMap ) {
	_clock.restart();
	setStartEnd();
}

void Canvas::onUpdate() {
	_time = _clock.getElapsedTime().asSeconds();
	_clock.restart();

	//speed modifiers
	double moveSpeed = _time * 4.; //the constant value is in squares/second
	double rotSpeed = _time * 1.7; //the constant value is in radians/second

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		moveSpeed = _time * 7.;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		double oldDirX = _dirX;
		_dirX = _dirX * cos(rotSpeed) - _dirY * sin(rotSpeed);
		_dirY = oldDirX * sin(rotSpeed) + _dirY * cos(rotSpeed);
		double oldPlaneX = _planeX;
		_planeX = _planeX * cos(rotSpeed) - _planeY * sin(rotSpeed);
		_planeY = oldPlaneX * sin(rotSpeed) + _planeY * cos(rotSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		double oldDirX = _dirX;
		_dirX = _dirX * cos(-rotSpeed) - _dirY * sin(-rotSpeed);
		_dirY = oldDirX * sin(-rotSpeed) + _dirY * cos(-rotSpeed);
		double oldPlaneX = _planeX;
		_planeX = _planeX * cos(-rotSpeed) - _planeY * sin(-rotSpeed);
		_planeY = oldPlaneX * sin(-rotSpeed) + _planeY * cos(-rotSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (_worldMap[int(_posX + _dirX * moveSpeed)][int(_posY)] == ' ' || _worldMap[int(_posX + _dirX * moveSpeed)][int(_posY)] == 'S') _posX += _dirX * moveSpeed;
		if (_worldMap[int(_posX)][int(_posY + _dirY * moveSpeed)] == ' ' || _worldMap[int(_posX)][int(_posY + _dirY * moveSpeed)] == 'S') _posY += _dirY * moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (_worldMap[int(_posX - _dirX * moveSpeed)][int(_posY)] == ' ' || _worldMap[int(_posX - _dirX * moveSpeed)][int(_posY)] == 'S') _posX -= _dirX * moveSpeed;
		if (_worldMap[int(_posX)][int(_posY - _dirY * moveSpeed)] == ' ' || _worldMap[int(_posX)][int(_posY - _dirY * moveSpeed)] == 'S') _posY -= _dirY * moveSpeed;
	}

	clear(sf::Color::Black);

	for (int x = 0; x < this->GetSize().x; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / double(this->GetSize().x) - 1; //x-coordinate in camera space
		double rayDirX = _dirX + _planeX * cameraX;
		double rayDirY = _dirY + _planeY * cameraX;

		//which box of the map we're in
		int mapX = int(_posX);
		int mapY = int(_posY);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = std::abs(1 / rayDirX);
		double deltaDistY = std::abs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0) {
			stepX = -1;
			sideDistX = (_posX - mapX) * deltaDistX;
		}
		else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - _posX) * deltaDistX;
		} 
		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (_posY - mapY) * deltaDistY;
		}
		else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - _posY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0) {
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (_worldMap[mapX][mapY] != ' ' && _worldMap[mapX][mapY] != 'S') hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0) perpWallDist = (mapX - _posX + (1 - stepX) / 2) / rayDirX;
		else           perpWallDist = (mapY - _posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(this->GetSize().y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + this->GetSize().y / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + this->GetSize().y / 2;
		if (drawEnd >= this->GetSize().y) drawEnd = this->GetSize().y - 1;

		//choose wall color
		int denominator = 1;
		if (side == 1) 
			denominator = 2; 
		sf::Color color;
		switch (_worldMap[mapX][mapY]) {
			case 'X':  color = sf::Color(255 / denominator, 0, 0);    break;
			case 'Y':  color = sf::Color(0, 255 / denominator, 0);  break;
			case 'Z':  color = sf::Color(0, 0, 255 / denominator);   break;
			default: color = sf::Color::Yellow; break;
		}

		//draw the pixels of the stripe as a vertical line
		sf::Vertex line[] = {
			sf::Vertex(sf::Vector2f(x, drawStart), color),
			sf::Vertex(sf::Vector2f(x, drawEnd), color)
		};
		draw(line, 2, sf::Lines);
	}
}

void Canvas::loadWorldMap(const std::vector<std::vector<char>>& worldMap) {
	_worldMap = worldMap;
}

void Canvas::onResize(wxSizeEvent & event) {
	auto size = event.GetSize();

	auto newCanvasWidth = size.x;
	auto newCanvasHeight = size.y;

	// Resize Canvas window
	this->setwxWindowSize({ newCanvasWidth, newCanvasHeight });
	this->setRenderWindowSize({ (unsigned int)newCanvasWidth, (unsigned int)newCanvasHeight });
}

void Canvas::setStartEnd() {
	int tmp = _worldMap.size();
	for (int i = 0; i < _worldMap.size(); i++) {
		for (int j = 0; j < _worldMap[i].size(); j++) {
			if (_worldMap[i][j] == 'S') {
				_posX = i;
				_posY = j;
			}
			else if (_worldMap[i][j] == 'E') {
				_endX = i;
				_endY = j;
			}
		}
	}	
}