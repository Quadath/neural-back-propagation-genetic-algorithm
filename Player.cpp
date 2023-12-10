#include "Player.h"
#include "Utils.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>


Player::Player(float x, float y, int number, sf::RenderWindow* window, Obstacle* obstacle) : Object(x, y), number(number), net(), window(window), obstacle(obstacle), shape(sf::RectangleShape({10, 10})), color(sf::Color(Random(0, 255), Random(0, 255), Random(0, 255), 255)) {
	shape.setFillColor(color);
};

void Player::Move(Vector2 direction) {
	x += direction.x;
	y += direction.y;
	if (x < FIELD_BORDER) x = FIELD_BORDER;
	if (x > WINDOW_HEIGHT - FIELD_BORDER - 10) x = WINDOW_HEIGHT - FIELD_BORDER - 10;
	shape.setPosition(x, y);
}

void Player::Tick() {
	net.Train(0, 1, 1, 0.05f);
	net.Train(1, 0, 0, 0.05f);
	net.Train(2, 4, 1, 0.05f);
	net.Train(4, 2, 0, 0.05f);

	shape.setPosition(x, y);
	float velocity = net.Compute(x / 100, (obstacle->x + 50) / 100) - 0.5f;
	Move({ velocity * 30, 0 });
	Draw();
}

void Player::Draw() {
	window->draw(shape);
}