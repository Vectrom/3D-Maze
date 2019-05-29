#include <SFML/Graphics.hpp>
#include "Canvas.h"
#include "Settings.h"

Canvas::Canvas(wxWindow * parent, wxWindowID id, wxPoint position, wxSize size, long style) :
	wxSfmlCanvas(parent, id, position, size, style) {
	_clock.restart();
	setStartEnd();
	_direction = sf::Vector2<double>(-1., 0.);
	_plane = sf::Vector2<double>(0., tan(Settings::FOV/2 * M_PI/180));
}

void Canvas::onUpdate() {
	_oldTime = _time;
	_time = _clock.getElapsedTime().asSeconds();
	double frameTime = (_time - _oldTime) / 2;

	double moveSpeed = frameTime * 5.; 
	double rotSpeed = frameTime * 3.; 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		moveSpeed *= 2.;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		rotate(rotSpeed, 1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		rotate(rotSpeed, -1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		move(moveSpeed, -1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		move(moveSpeed, 1);
	}

	drawMaze();
}

void Canvas::onResize(wxSizeEvent &event) {
	auto size = event.GetSize();
	auto newCanvasWidth = size.x;
	auto newCanvasHeight = size.y;

	this->SetSize({ newCanvasWidth, newCanvasHeight });
	createRenderWindow();
}

void Canvas::setStartEnd() {
	for (int i = 0; i < static_cast<int>(Settings::worldMap.size()); i++) {
		for (int j = 0; j < static_cast<int>(Settings::worldMap[i].size()); j++) {
			if (Settings::worldMap[i][j] == 'S') {
				_playerPosition.x = i;
				_playerPosition.y = j;
			}
			else if (Settings::worldMap[i][j] == 'E') {
				_end.x = i;
				_end.y = j;
			}
		}
	}	
}

void Canvas::drawMaze() {
	clear(sf::Color::Black);

	for (int x = 0; x < this->GetSize().x; x++) {
		double cameraX = 2 * x / static_cast<double>(this->GetSize().x) - 1;
		sf::Vector2<double> rayDirection(_direction.x + _plane.x * cameraX, _direction.y + _plane.y * cameraX);
		sf::Vector2<int> mapBox(static_cast<int>(_playerPosition.x), static_cast<int>(_playerPosition.y));
		sf::Vector2<double> deltaDistance(std::abs(1 / rayDirection.x), std::abs(1 / rayDirection.y));
		sf::Vector2<double> sideDistance;
		sf::Vector2<int> step;
		double perpWallDist;
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		calculateStepAndSideDist(sideDistance, step, deltaDistance, mapBox, rayDirection);

		findCollision(sideDistance, step, deltaDistance, mapBox, hit, side);

		if (side == 0) {
			perpWallDist = (mapBox.x - _playerPosition.x + (1 - step.x) / 2) / rayDirection.x;
		}
		else {
			perpWallDist = (mapBox.y - _playerPosition.y + (1 - step.y) / 2) / rayDirection.y;
		}

		int lineHeight = static_cast<int>(this->GetSize().y / perpWallDist);

		int drawStart = -lineHeight / 2 + this->GetSize().y / 2;
		if (drawStart < 0) 
			drawStart = 0;

		int drawEnd = lineHeight / 2 + this->GetSize().y / 2;
		if (drawEnd >= this->GetSize().y) 
			drawEnd = this->GetSize().y - 1;

		sf::Color color = pickColor(mapBox, side);

		sf::Vertex line[] = {
			sf::Vertex(sf::Vector2f(x, drawStart), color),
			sf::Vertex(sf::Vector2f(x, drawEnd), color)
		};
		draw(line, 2, sf::Lines);
	}
}

void Canvas::move(double moveSpeed, int multiplier) {
	sf::Vector2i possibleNewPosition(int(_playerPosition.x + multiplier * _direction.x * moveSpeed), int(_playerPosition.y + multiplier * _direction.y * moveSpeed));
	if (Settings::worldMap[possibleNewPosition.x][int(_playerPosition.y)] == ' ' ||
		Settings::worldMap[possibleNewPosition.x][int(_playerPosition.y)] == 'S') _playerPosition.x += multiplier * _direction.x * moveSpeed;
	if (Settings::worldMap[int(_playerPosition.x)][possibleNewPosition.y] == ' ' ||
		Settings::worldMap[int(_playerPosition.x)][possibleNewPosition.y] == 'S') _playerPosition.y += multiplier * _direction.y * moveSpeed;
}

void Canvas::rotate(double rotSpeed, int multiplier) {
	double oldDirX = _direction.x;
	_direction.x = _direction.x * cos(multiplier * rotSpeed) - _direction.y * sin(multiplier * rotSpeed);
	_direction.y = oldDirX * sin(multiplier * rotSpeed) + _direction.y * cos(multiplier * rotSpeed);
	double oldPlaneX = _plane.x;
	_plane.x = _plane.x * cos(multiplier * rotSpeed) - _plane.y * sin(multiplier * rotSpeed);
	_plane.y = oldPlaneX * sin(multiplier * rotSpeed) + _plane.y * cos(multiplier * rotSpeed);
}

void Canvas::calculateStepAndSideDist(sf::Vector2<double>& sideDistance, sf::Vector2<int>& step, const sf::Vector2<double>& deltaDistance, const sf::Vector2<int>& mapBox, const sf::Vector2<double> &rayDirection) {
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
}

void Canvas::findCollision(sf::Vector2<double>& sideDistance, const sf::Vector2<int>& step, const sf::Vector2<double>& deltaDistance, sf::Vector2<int>& mapBox, int & hit, int & side) {
	while (hit == 0) {
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
		if (Settings::worldMap[mapBox.x][mapBox.y] != ' ' && Settings::worldMap[mapBox.x][mapBox.y] != 'S') hit = 1;
	}
}

sf::Color Canvas::pickColor(const sf::Vector2<int>& mapBox, int side) {
	int denominator = 1;
	if (side == 1)
		denominator = 2;
	sf::Color color;
	switch (Settings::worldMap[mapBox.x][mapBox.y]) {
	case 'X':
		color = sf::Color(255 / denominator, 0, 0);
		break;
	case 'Y':
		color = sf::Color(0, 255 / denominator, 0);
		break;
	case 'Z':
		color = sf::Color(0, 0, 255 / denominator);
		break;
	default:
		color = sf::Color::Yellow;
		break;
	}
	return color;
}
