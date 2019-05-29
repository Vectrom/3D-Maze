#include <algorithm>
#include "Settings.h"

double Settings::FOV = 66.0;
std::vector<std::vector<char>> Settings::worldMap;

bool Settings::validateMaze() {
	bool isStart = false, isEnd = false;

	for (int i = 0; i < static_cast<int>(Settings::worldMap.size()); i++) {
		for (int j = 0; j < static_cast<int>(Settings::worldMap[i].size()); j++) {
			if (Settings::worldMap[i][j] == 'E') isStart = true;
			if (Settings::worldMap[i][j] == 'S') isEnd = true;
			if (!hasNeighborBelow(i, j)) return false;
		}
	}

	return isStart && isEnd;
}

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

bool Settings::hasNeighborBelow(int x, int y) {
	std::vector<char> signs = { 'X', 'Y', 'Z', 'E', 'S' };
	if (x > 0 && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y]) != signs.end()) return true;
	if (x > 0 && y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x - 1][y + 1]) != signs.end())return true;
	if (x + 1 < Settings::worldMap.size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y]) != signs.end()) return true;
	if (x + 1 < Settings::worldMap.size() && y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x + 1][y + 1]) != signs.end()) return true;
	if (y + 1 < Settings::worldMap[x].size() && std::find(signs.begin(), signs.end(), Settings::worldMap[x][y + 1]) != signs.end()) return true;
	return false;
}
