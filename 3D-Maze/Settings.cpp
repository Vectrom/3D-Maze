#include <algorithm>
#include "Settings.h"

bool Settings::mapCreated = false;
double Settings::FOV = 66.0;
std::vector<std::vector<char>> Settings::worldMap;
sf::Vector2<double> Settings::start;
sf::Vector2<double> Settings::end;
sf::Color Settings::wallX[2] = { sf::Color(100, 0, 0), sf::Color(50, 0, 0) };
sf::Color Settings::wallY[2] = { sf::Color(0, 100, 0), sf::Color(0, 50, 0) };
sf::Color Settings::wallZ[2] = { sf::Color(0, 0, 100), sf::Color(0, 0, 50) };
sf::Color Settings::ceil(79, 116, 175);
sf::Color Settings::floor(39, 33, 33);
sf::Color Settings::exit(247, 202, 68);

std::vector<char> signs = { 'X', 'Y', 'Z', 'E', 'S' };

void Settings::getStartEnd(sf::Vector2<double>& start, sf::Vector2<double>& end) {
	start.x = Settings::start.x;
	start.y = Settings::start.y;
	end.x = Settings::end.x;
	end.y = Settings::end.y;
}

bool Settings::checkStartEnd() {
	bool isStart = false, isEnd = false;
	for (int i = 0; i < static_cast<int>(Settings::worldMap.size()); i++) { //moving around the rows
		for (int j = 0; j < static_cast<int>(Settings::worldMap[i].size()); j++) { //moving around the columns
			if (Settings::worldMap[i][j] == 'S') {
				Settings::start.x = i;
				Settings::start.y = j;
				isStart = true;
			}
			else if (Settings::worldMap[i][j] == 'E') {
				Settings::end.x = i;
				Settings::end.y = j;
				isEnd = true;
			}
		}
	}
	return isStart && isEnd;
}

bool Settings::validateMaze() {
	bool searchingFirst = true;
	bool checkingMazeFrame = true;

	int x = 0, y = 0;
	while (searchingFirst) {
		if (std::find(signs.begin(), signs.end(), Settings::worldMap[x][y]) != signs.end()) {
			searchingFirst = false;
			break;
		}
		if (y + 1 < Settings::worldMap[x].size()) {
			y++;
		}
		else {
			if (x + 1 < Settings::worldMap.size()) {
				x++;
				y = 0;
			}
			else {
				return false;
			}
		}
	}
	
	direction dir = Left; 
	int firstX = x, firstY = y;
	while (checkingMazeFrame) {
		if (x == -1) {
			return false;
		}
		switch (dir) {
		case Up:
			neighborUp(x, y, dir);
			break;
		case Down:
			neighborDown(x, y, dir);
			break;
		case Left:
			neighborLeft(x, y, dir);
			break;
		case Right:
			neighborRight(x, y, dir);
			break;
		}
		if (x == firstX && y == firstY) {
			return checkStartEnd();
		}
	}

	return false;
}

void Settings::neighborDown(int & x, int & y, direction &dir) {
	if (x > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y]) != signs.end()) {
		x -= 1;
		dir = Left;
		return;
	}
	if (x > 0 && y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y + 1]) != signs.end()) {
		x -= 1;
		y += 1;
		dir = Left;
		return;
	}
	if (y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y + 1]) != signs.end()) {
		y += 1;
		return;
	}
	if (x + 1 < Settings::worldMap.size() && y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y + 1]) != signs.end()) {
		x += 1;
		y += 1;
		return;
	}
	if (x + 1 < Settings::worldMap.size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y]) != signs.end()) {
		x += 1;
		dir = Right;
		return;
	}
	x = -1;
}

void Settings::neighborUp(int & x, int & y, direction &dir) {
	if (x + 1 < Settings::worldMap.size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y]) != signs.end()) {
		x += 1;
		dir = Right;
		return;
	}
	if (x + 1 < Settings::worldMap.size() && y > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y - 1]) != signs.end()) {
		x += 1;
		y -= 1;
		dir = Right;
		return;
	}
	if (y > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y - 1]) != signs.end()) {
		y -= 1;
		return;
	}
	if (x > 0 && y > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y - 1]) != signs.end()) {
		x -= 1;
		y -= 1;
		return;
	}
	if (x > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y]) != signs.end()) {
		x -= 1;
		dir = Left;
		return;
	}
	x = -1;
}

void Settings::neighborLeft(int & x, int & y, direction &dir) {
	if (y > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y - 1]) != signs.end()) {
		y -= 1;
		dir = Up;
		return;
	}
	if (x > 0 && y > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y - 1]) != signs.end()) {
		x -= 1;
		y -= 1;
		dir = Up;
		return;
	}
	if (x > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y]) != signs.end()) {
		x -= 1;
		return;
	}
	if (x > 0 && y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y + 1]) != signs.end()) {
		x -= 1;
		y += 1;
		return;
	}
	if (y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y + 1]) != signs.end()) {
		y += 1;
		dir = Down;
		return;
	}
	x = -1;
}

void Settings::neighborRight(int & x, int & y, direction &dir) {
	if (y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y + 1]) != signs.end()) {
		y += 1;
		dir = Down;
		return;
	}
	if (x + 1 < Settings::worldMap.size() && y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y + 1]) != signs.end()) {
		x += 1;
		y += 1;
		dir = Down;
		return;
	}
	if (x + 1 < Settings::worldMap.size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y]) != signs.end()) {
		x += 1;
		return;
	}
	if (x + 1 < Settings::worldMap.size() && y > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y - 1]) != signs.end()) {
		x += 1;
		y -= 1;
		return;
	}
	if (y > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y - 1]) != signs.end()) {
		y -= 1;
		dir = Up;
		return;
	}
	x = -1;
}
