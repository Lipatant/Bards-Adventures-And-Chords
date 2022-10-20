/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/ui/box.cpp
** File description:
** Various things used for uIBoxes
*/

#include "engine/ui/box.hpp"
#include "engine/units.hpp"

namespace BARD_ENGINE_NAMESPACE
{
    bool BARD_ENGINE_NAMESPACE::UIBox_c::display(BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayerPointed = NULL)
    {
        sf::Vector2f relativePositionTile = {0, 0};
        sf::IntRect textureRect = {0, 0, TILE, TILE};

        if (windowLayerPointed == NULL)
            windowLayerPointed = _windowLayerPointed;
        if (windowLayerPointed == NULL || _sizeTile.x < 1 || _sizeTile.y < 1)
            return true;
        getSpriteActual().getSprite().setColor(_color);
        for (unsigned int x = 0; x < _sizeTile.x; x++)
        {
            relativePositionTile.x = _positionTile.x + x;
            textureRect.left = (x == 0 ? 0 : (x == _sizeTile.x - 1 ? 2 : 1)) * TILE;
            for (unsigned int y = 0; y < _sizeTile.y; y++)
            {
                relativePositionTile.y = _positionTile.y + y;
                textureRect.top = ((y == 0 ? 0 : (y == _sizeTile.y - 1 ? 2 : 1)) + 3) * TILE;
                getSpriteActual().getSprite().setTextureRect(textureRect);
                getSpriteActual().setPositionTile(relativePositionTile);
                getSpriteActual().display(windowLayerPointed);
            }
        }
        return false;
    };
};
