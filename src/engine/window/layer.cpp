/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** window/layer.cpp
** File description:
** Various things used for windowlayers
*/

#include "engine/window/layer.hpp"
#include <SFML/Window/Event.hpp>

namespace BARD_ENGINE_NAMESPACE
{
    void BARD_ENGINE_NAMESPACE::WindowLayer_c::destroy(void)
    {
        _renderWindow.close();
    };

    sf::RenderWindow &BARD_ENGINE_NAMESPACE::WindowLayer_c::getRenderWindow(void)
    {
        return _renderWindow;
    };

    void BARD_ENGINE_NAMESPACE::WindowLayer_c::update(void)
    {
        sf::Event Event;
        while (_renderWindow.pollEvent(Event))
            if (Event.type == sf::Event::Closed)
                _renderWindow.close();
    };
};
