/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** start.cpp
** File description:
** When the game starts
*/

#include "returned.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include "utility/strings.hpp"
#include "engine.hpp"

int start(int const ac, char *av[], char *env[])
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    engine::WindowLayer_c WindowLayer;

    while (WindowLayer.getRenderWindow().isOpen())
    {
        sf::Event event;
        while (WindowLayer.getRenderWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WindowLayer.getRenderWindow().close();
        }
        WindowLayer.getRenderWindow().clear();
        WindowLayer.getRenderWindow().draw(shape);
        WindowLayer.getRenderWindow().display();
    }
    WindowLayer.destroy();
    return RETURNED_EXIT;
}
