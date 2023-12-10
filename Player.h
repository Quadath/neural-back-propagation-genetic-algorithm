#pragma once
#include "Object.h"
#include "Geometry.h"
#include "Net.h"
#include "Obstacle.h"
#include <SFML/Graphics.hpp>

class Player : public Object {
public:
	Player(float x, float y, int number, sf::RenderWindow* window, Obstacle* obstacle);
	void Move(Vector2 direction);
	void Tick();
	int score = 0;
	sf::Color color; 
	sf::Clock clock;
	Net net;
	int number;
private:
	sf::RenderWindow* window;
	sf::RectangleShape shape;
	Obstacle* obstacle;
	void Draw();
};