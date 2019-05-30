#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <utility>

struct Settings {
	static bool mapCreated;
	static sf::Vector2<double> start;
	static sf::Vector2<double> end;
	static double FOV;
	static std::vector<std::vector<char>> worldMap;
	static sf::Color wallX[2];
	static sf::Color wallY[2];
	static sf::Color wallZ[2];
	static sf::Color ceil;
	static sf::Color floor;
	static sf::Color exit;

	enum direction {
		Up,
		Down,
		Left,
		Right
	};

	static void getStartEnd(sf::Vector2<double> &start, sf::Vector2<double> &end);
	static bool checkStartEnd();
	static bool validateMaze();
	static void neighborDown(int &x, int &y, direction &dir);
	static void neighborUp(int &x, int &y, direction &dir);
	static void neighborLeft(int &x, int &y, direction &dir);
	static void neighborRight(int &x, int &y, direction &dir);
};