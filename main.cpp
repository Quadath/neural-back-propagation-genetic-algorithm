#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Settings.h"
#include "Geometry.h"
#include "FieldBorder.h"
#include "Obstacle.h"
#include "Utils.h"


int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    sf::Clock clock;
    Object object(10, 10);
    FieldBorder field(&window);
    Obstacle obstacle(500, &window);

    std::vector<Player> players;

    for (int y = WINDOW_HEIGHT / 2; y < WINDOW_HEIGHT - FIELD_BORDER; y += 10) {
        for (int i = 0; i < 3; i++) {
            players.push_back(Player((WINDOW_HEIGHT - FIELD_BORDER) / 2, y, y / 10 + i, &window, &obstacle));
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                    case sf::Keyboard::A: {
                        obstacle.x = 0;
                    } break;
                    case sf::Keyboard::D: {
                        obstacle.x = WINDOW_HEIGHT - 100;
                    } break;
                }
        }
        if (clock.getElapsedTime().asSeconds() > 1) {
            clock.restart();
            players.push_back(Player((WINDOW_HEIGHT - FIELD_BORDER) / 2, 500 + 500 * Random(0, 1), 10, &window, &obstacle));
        }

        window.clear(sf::Color::Black);
        field.Draw();
        players.erase(std::remove_if(players.begin(), players.end(), [&](const Player& player) {
            return player.clock.getElapsedTime().asSeconds() > 15;
            }), players.end());


        for (auto& player : players) {
            player.Tick();

            if (Vector2::Distance({ player.x, player.y }, { obstacle.x + 50, obstacle.y + 50 }) < 50) {
                player.clock.restart();
            }
        }
        obstacle.Tick();

        window.display();
    }
    return 0;
}