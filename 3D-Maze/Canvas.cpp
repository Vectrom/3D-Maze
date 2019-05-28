#include "Canvas.h"
#include <SFML/Graphics.hpp>


Canvas::Canvas(wxWindow * parent, wxWindowID id, wxPoint position, wxSize size, long style) :
	wxSfmlCanvas(parent, id, position, size, style) {
	clock.restart();
}

void Canvas::onUpdate() {
	sf::Event event;

	time = clock.getElapsedTime().asSeconds();
	clock.restart();

	//speed modifiers
	double moveSpeed = time * 4.; //the constant value is in squares/second
	double rotSpeed = time * 1.7; //the constant value is in radians/second

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		moveSpeed = time * 7.;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (_worldMap[int(posX + dirX * moveSpeed)][int(posY)] == ' ') posX += dirX * moveSpeed;
		if (_worldMap[int(posX)][int(posY + dirY * moveSpeed)] == ' ') posY += dirY * moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (_worldMap[int(posX - dirX * moveSpeed)][int(posY)] == ' ') posX -= dirX * moveSpeed;
		if (_worldMap[int(posX)][int(posY - dirY * moveSpeed)] == ' ') posY -= dirY * moveSpeed;
	}

	clear(sf::Color::Black);

	for (int x = 0; x < this->GetSize().x; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / double(this->GetSize().x) - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		//which box of the map we're in
		int mapX = int(posX);
		int mapY = int(posY);

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
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		} 
		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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
			if (_worldMap[mapX][mapY] != ' ') hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else           perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(this->GetSize().y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + this->GetSize().y / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + this->GetSize().y / 2;
		if (drawEnd >= this->GetSize().y) drawEnd = this->GetSize().y - 1;

		//choose wall color
		sf::Color color;
		switch (_worldMap[mapX][mapY])
		{
			case 'X':  color = sf::Color::Red;    break;
			case 'Y':  color = sf::Color::Green;  break;
			case 'Z':  color = sf::Color::Blue;   break;
			default: color = sf::Color::Yellow; break;
		}

		//give x and y sides different brightness
		//if (side == 1) { color = color / 2; }

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
