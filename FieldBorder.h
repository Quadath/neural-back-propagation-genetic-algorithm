#pragma once
#include "Object.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>


class FieldBorder : public Object {
public:
	FieldBorder(sf::RenderWindow* window);
	void Draw();
	sf::RectangleShape field;
	sf::RectangleShape border;
	sf::RenderWindow* window;
};