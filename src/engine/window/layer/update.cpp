/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/layer/update.cpp
** File description:
** Updates a render window
*/

#include "engine/window/layer.hpp"
#include <SFML/Window/Event.hpp>

struct Vector2d_s {
    double x;
    double y;
};

sf::Vector2f getWindowRatio(sf::Vector2u const windowSize)
{
    sf::Vector2f ratio = {1, 1};
    struct Vector2d_s windowRatio = {0, 0};

    windowRatio.x = (double)windowSize.x / (double)DEFAULT_WINDOW_RESOLUTION.x;
    windowRatio.y = (double)windowSize.y / (double)DEFAULT_WINDOW_RESOLUTION.y;
    if (windowRatio.x > windowRatio.y)
        ratio.x = windowRatio.y / windowRatio.x;
    else
        ratio.y = windowRatio.x / windowRatio.y;
    return ratio;
};

sf::View correctView(BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayer)
{
    sf::FloatRect viewRect = {0, 0, 1, 1};
    sf::Vector2f viewSize = {0, 0};
    sf::Vector2f windowRatio = getWindowRatio(windowLayer->getRenderWindow().getSize());
    sf::View view = windowLayer->getRenderWindow().getView();

    viewRect.width *= windowRatio.x;
    viewRect.height *= windowRatio.y;
    viewRect.left += (1 - viewRect.width) / 2;
    viewRect.top += (1 - viewRect.height) / 2;
    viewSize.x = DEFAULT_WINDOW_RESOLUTION.x;
    viewSize.y = DEFAULT_WINDOW_RESOLUTION.y;
    view.setSize(viewSize);
    view.setViewport(viewRect);
    return view;
};

namespace BARD_ENGINE_NAMESPACE
{
    void BARD_ENGINE_NAMESPACE::WindowLayer_c::update(void)
    {
        sf::Event Event;

        while (_renderWindow.pollEvent(Event))
            if (Event.type == sf::Event::Closed)
                _renderWindow.close();
        _renderWindow.setView(correctView(this));
    };
};
