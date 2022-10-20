/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/layer.cpp
** File description:
** Various things used for windowlayers
*/

#include "engine/window/layer.hpp"

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
};
