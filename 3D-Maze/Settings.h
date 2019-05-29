#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct Settings {
	static double FOV;
	static std::vector<std::vector<char>> worldMap;

	static bool validateMaze();
	static void getStartEnd(sf::Vector2<double> &start, sf::Vector2<double> &end);
	static bool hasNeighborBelow(int x, int y);
};