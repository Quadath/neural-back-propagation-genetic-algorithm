#include "FieldBorder.h"

FieldBorder::FieldBorder(sf::RenderWindow* window) : Object(0, 0), window(window) {
	field = sf::RectangleShape({ WINDOW_HEIGHT - 2 * FIELD_BORDER, WINDOW_HEIGHT - 2 * FIELD_BORDER });
	field.setFillColor(sf::Color::Black);
	field.setPosition(FIELD_BORDER, FIELD_BORDER);
	border = sf::RectangleShape({ WINDOW_HEIGHT, WINDOW_HEIGHT });
	border.setFillColor(sf::Color::White);
};

void FieldBorder::Draw() {
	window->draw(border);
	window->draw(field);
}