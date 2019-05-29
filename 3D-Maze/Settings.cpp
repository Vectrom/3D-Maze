#include <algorithm>
#include "Settings.h"

double Settings::FOV = 66.0;
std::vector<std::vector<char>> Settings::worldMap;

//bool Settings::validateMaze() {
//	bool isStart = false, isEnd = false;
//	std::vector<char> signs = { 'X', 'Y', 'Z' };
//
//	for (int i = 0; i < static_cast<int>(Settings::worldMap.size()); i++) {
//		for (int j = 0; j < static_cast<int>(Settings::worldMap[i].size()); j++) {
//			if (Settings::worldMap[i][j] == 'E') isStart = true;
//			if (Settings::worldMap[i][j] == 'S') isEnd = true;
//			if (std::find(signs.begin(), signs.end(), Settings::worldMap[i][j]) != signs.end() && !hasNeighborBelow(i, j)) return false;
//		}
//	}
//
//	return isStart && isEnd;
//}

void Settings::getStartEnd(sf::Vector2<double>& start, sf::Vector2<double>& end) {
	for (int i = 0; i < static_cast<int>(Settings::worldMap.size()); i++) {
		for (int j = 0; j < static_cast<int>(Settings::worldMap[i].size()); j++) {
			if (Settings::worldMap[i][j] == 'S') {
				start.x = i;
				start.y = j;
			}
			else if (Settings::worldMap[i][j] == 'E') {
				end.x = i;
				end.y = j;
			}
		}
	}
}

//bool Settings::hasNeighborBelow(int x, int y) {
//	std::vector<char> signs = { 'X', 'Y', 'Z', 'E', 'S' };
//	if (x > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y]) != signs.end()) return true;
//	if (x > 0 && y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y + 1]) != signs.end())return true;
//	if (x + 1 < Settings::worldMap.size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y]) != signs.end()) return true;
//	if (x + 1 < Settings::worldMap.size() && y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y + 1]) != signs.end()) return true;
//	if (y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y + 1]) != signs.end()) return true;
//	return false;
//}

bool Settings::validateMaze() {
	bool isStart = false, isEnd = false;
	std::vector<char> signs = { 'X', 'Y', 'Z', 'E', 'S' };
	bool searchingFirst = true;
	bool checkingMazeFrame = true;

	int x = 0, y = 0;
	while (searchingFirst) {
		if (std::find(signs.begin(), signs.end(), Settings::worldMap[x][y]) != signs.end()) {
			searchingFirst = false;
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

	while (checkingMazeFrame) {
		switch (dir) {
		case Up:
			break;
		case Down:

			break;
		case Left:
			break;
		case Right:
			break;
		default:
			break;
		}
	}

	return true;
}

void Settings::neighborDown(int & x, int & y, direction &dir) {
	std::vector<char> signs = { 'X', 'Y', 'Z', 'E', 'S' };
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
	std::vector<char> signs = { 'X', 'Y', 'Z', 'E', 'S' };
	if (x + 1 < Settings::worldMap.size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y]) != signs.end()) {
		x += 1;
		dir = Right;
		return;
	}
	if (x + 1 < Settings::worldMap.size() && y - 1 < 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y + 1]) != signs.end()) {
		x += 1;
		y -= 1;
		dir = Right;
		return;
	}
	if (y - 1 > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y + 1]) != signs.end()) {
		y -= 1;
		return;
	}
	if (x > 0 && y - 1 < 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y + 1]) != signs.end()) {
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
	std::vector<char> signs = { 'X', 'Y', 'Z', 'E', 'S' };
	if (y - 1 > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y + 1]) != signs.end()) {
		y -= 1;
		dir = Up;
		return;
	}
	if (x > 0 && y - 1 < 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y + 1]) != signs.end()) {
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
	std::vector<char> signs = { 'X', 'Y', 'Z', 'E', 'S' };
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
	if (x + 1 < Settings::worldMap.size() && y - 1 < 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y + 1]) != signs.end()) {
		x += 1;
		y -= 1;
		return;
	}
	if (y - 1 > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y + 1]) != signs.end()) {
		y -= 1;
		dir = Up;
		return;
	}
	x = -1;
}
