#include "Obstacle.h"
#include "Settings.h"
#include "Utils.h"

Obstacle::Obstacle(float x, sf::RenderWindow* window) : Object(x, 0), window(window), direction({ 0, 10 }), shape(50) {
	shape.setFillColor(sf::Color::Red);
};

void Obstacle::Tick() {
	Move(direction);
	Draw();
}

void Obstacle::Move(Vector2 direction) {
	x += direction.x;
	y += direction.y;
	if (y > WINDOW_HEIGHT + 50) {
		y = -50;
		x = (WINDOW_HEIGHT - 2 * FIELD_BORDER) * Random(0.05, 0.95);
	}
	shape.setPosition(x, y);
}

void Obstacle::Draw() {
	window->draw(shape);
}

