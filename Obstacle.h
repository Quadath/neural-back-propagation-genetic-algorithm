#pragma once
#include "Object.h"
#include "Geometry.h"
#include <SFML/Graphics.hpp>

class Obstacle : public Object {
public:
	Obstacle(float x, sf::RenderWindow* window);
	void Tick();
	void Draw();
	void Move(Vector2 direction);
	Vector2 direction;
	sf::CircleShape shape;
	sf::RenderWindow* window;
};