#include "Canvas.h"
#include <SFML/Graphics.hpp>


Canvas::Canvas(wxWindow * parent, wxWindowID id, wxPoint position, wxSize size, const std::vector<std::vector<char>> &worldMap, long style) :
	wxSfmlCanvas(parent, id, position, size, style), 
	_worldMap(worldMap ) {
	_clock.restart();
	setStartEnd();

	_direction = sf::Vector2<double>(-1., 0.);
	_plane = sf::Vector2<double>(0., 0.66);
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
		double oldDirX = _direction.x;
		_direction.x = _direction.x * cos(rotSpeed) - _direction.y * sin(rotSpeed);
		_direction.y = oldDirX * sin(rotSpeed) + _direction.y * cos(rotSpeed);
		double oldPlaneX = _plane.x;
		_plane.x = _plane.x * cos(rotSpeed) - _plane.y * sin(rotSpeed);
		_plane.y = oldPlaneX * sin(rotSpeed) + _plane.y * cos(rotSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		double oldDirX = _direction.x;
		_direction.x = _direction.x * cos(-rotSpeed) - _direction.y * sin(-rotSpeed);
		_direction.y = oldDirX * sin(-rotSpeed) + _direction.y * cos(-rotSpeed);
		double oldPlaneX = _plane.x;
		_plane.x = _plane.x * cos(-rotSpeed) - _plane.y * sin(-rotSpeed);
		_plane.y = oldPlaneX * sin(-rotSpeed) + _plane.y * cos(-rotSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		sf::Vector2i possibleNewPosition(int(_playerPosition.x + _direction.x * moveSpeed), int(_playerPosition.y + _direction.y * moveSpeed));
		if (_worldMap[possibleNewPosition.x][int(_playerPosition.y)] == ' ' || 
			_worldMap[possibleNewPosition.x][int(_playerPosition.y)] == 'S') _playerPosition.x += _direction.x * moveSpeed;
		if (_worldMap[int(_playerPosition.x)][possibleNewPosition.y] == ' ' ||
			_worldMap[int(_playerPosition.x)][possibleNewPosition.y] == 'S') _playerPosition.y += _direction.y * moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		sf::Vector2i possibleNewPosition(int(_playerPosition.x - _direction.x * moveSpeed), int(_playerPosition.y - _direction.y * moveSpeed));
		if (_worldMap[possibleNewPosition.x][int(_playerPosition.y)] == ' ' ||
			_worldMap[possibleNewPosition.x][int(_playerPosition.y)] == 'S') _playerPosition.x -= _direction.x * moveSpeed;
		if (_worldMap[int(_playerPosition.x)][possibleNewPosition.y] == ' ' ||
			_worldMap[int(_playerPosition.x)][possibleNewPosition.y] == 'S') _playerPosition.y -= _direction.y * moveSpeed;
	}

	drawMaze();
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
	for (int i = 0; i < static_cast<int>(_worldMap.size()); i++) {
		for (int j = 0; j < static_cast<int>(_worldMap[i].size()); j++) {
			if (_worldMap[i][j] == 'S') {
				_playerPosition.x = i;
				_playerPosition.y = j;
			}
			else if (_worldMap[i][j] == 'E') {
				_end.x = i;
				_end.y = j;
			}
		}
	}	
}

void Canvas::drawMaze() {
	clear(sf::Color::Black);

	for (int x = 0; x < this->GetSize().x; x++) {
		//calculate ray position and direction
		double cameraX = 2 * x / double(this->GetSize().x) - 1; //x-coordinate in camera space
		sf::Vector2<double> rayDirection(_direction.x + _plane.x * cameraX, _direction.y + _plane.y * cameraX);

		//which box of the map we're in
		sf::Vector2<int> mapBox(static_cast<int>(_playerPosition.x), static_cast<int>(_playerPosition.y));

		//length of ray from current position to next x or y-side
		sf::Vector2<double> sideDistance;

		//length of ray from one x or y-side to next x or y-side
		sf::Vector2<double> deltaDistance(std::abs(1 / rayDirection.x), std::abs(1 / rayDirection.y));
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		sf::Vector2<int> step;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirection.x < 0) {
			step.x = -1;
			sideDistance.x = (_playerPosition.x - mapBox.x) * deltaDistance.x;
		}
		else {
			step.x = 1;
			sideDistance.x = (mapBox.x + 1.0 - _playerPosition.x) * deltaDistance.x;
		}
		if (rayDirection.y < 0) {
			step.y = -1;
			sideDistance.y = (_playerPosition.y - mapBox.y) * deltaDistance.y;
		}
		else {
			step.y = 1;
			sideDistance.y = (mapBox.y + 1.0 - _playerPosition.y) * deltaDistance.y;
		}
		//perform DDA
		while (hit == 0) {
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistance.x < sideDistance.y) {
				sideDistance.x += deltaDistance.x;
				mapBox.x += step.x;
				side = 0;
			}
			else {
				sideDistance.y += deltaDistance.y;
				mapBox.y += step.y;
				side = 1;
			}
			//Check if ray has hit a wall
			if (_worldMap[mapBox.x][mapBox.y] != ' ' && _worldMap[mapBox.x][mapBox.y] != 'S') hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0) perpWallDist = (mapBox.x - _playerPosition.x + (1 - step.x) / 2) / rayDirection.x;
		else           perpWallDist = (mapBox.y - _playerPosition.y + (1 - step.y) / 2) / rayDirection.y;

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
		switch (_worldMap[mapBox.x][mapBox.y]) {
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