/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** start.cpp
** File description:
** When the game starts
*/

#include "returned.hpp"

#include <SFML/Graphics.hpp>
#include "utility/strings.hpp"
#include "engine/window/layer.hpp"
#include "utility/generation/perlin_noise.hpp"

sf::Color getColor(float const value, float const zone)
{
    float coloredZones[][3] = {{1, 0, 0}, {1, 1, 0}, {0, 1, 1}, {0, 0, 1}};
    sf::Color color = sf::Color::Black;
    sf::Int8 color_value = 0;
    int coloredZonesValue = 0;

    color_value = value * 255;
    if (value <= 0.0)
        color_value = 0;
    if (value >= 1.0)
        color_value = 255;
    coloredZonesValue = (sizeof(coloredZones) / sizeof(coloredZones[1])) * zone;
    coloredZonesValue %= (sizeof(coloredZones) / sizeof(coloredZones[1]));
    color.r = color_value * coloredZones[coloredZonesValue][0];
    color.g = color_value * coloredZones[coloredZonesValue][1];
    color.b = color_value * coloredZones[coloredZonesValue][2];
    return color;
}

int start(int const ac, char *av[], char *env[])
{
    sf::RectangleShape shape;
    engine::WindowLayer_c windowLayer;
    utility::GenerationOuput2f_c output(DEFAULT_WINDOW_RESOLUTION);
    utility::GenerationOuput2f_c output_zones(DEFAULT_WINDOW_RESOLUTION);

    shape.setSize({1, 1});
    output.perlin_noise(7, 1.5, std::time(nullptr));
    output_zones.perlin_noise(5, 1.5, (std::time(nullptr) * 2) + 1);
    while (windowLayer.getRenderWindow().isOpen())
    {
        windowLayer.update();
        windowLayer.getRenderWindow().clear();
        for (unsigned int x = 0; x < DEFAULT_WINDOW_RESOLUTION.x; x++)
        {
            for (unsigned int y = 0; y < DEFAULT_WINDOW_RESOLUTION.y; y++)
            {
                shape.setFillColor(getColor(output.getValue({x, y}), output_zones.getValue({x, y})));
                shape.setPosition({(float)x, (float)y});
                windowLayer.getRenderWindow().draw(shape);
            }
        }
        windowLayer.getRenderWindow().display();
    }
    windowLayer.destroy();
    output.destroy();
    return RETURNED_EXIT;
}
