#include "Settings.h"

double Settings::FOV = 66.0;
std::vector<std::vector<char>> Settings::worldMap;

bool Settings::validateMaze() {
	return true;
}

void Settings::setStartEnd(sf::Vector2<double>& start, sf::Vector2<double>& end) {
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
