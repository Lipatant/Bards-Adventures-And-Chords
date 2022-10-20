/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/sprite.hpp
** File description:
** Includes sprites
*/

#pragma once
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include "engine/namespace.hpp"
#include "engine/units.hpp"
#include "engine/window/layer.hpp"

namespace BARD_ENGINE_NAMESPACE
{
    class Sprite_c
    {
    public:
        /// @brief Creates a new sprite
        /// @param filePath Path to the texture file
        /// @param windowLayerPointed Pointer to the window layer used for display
        Sprite_c(sf::String const filePath = "", BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayerPointed = NULL)
        {
            setTexture(filePath);
            _windowLayerPointed = windowLayerPointed;
        };
        bool display(BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayerPointed = NULL)
        {
            if (!_hasTexture)
                return true;
            _sprite.setPosition({_positionTile.x * TILE, _positionTile.y * TILE});
            if (windowLayerPointed != NULL)
            {
                windowLayerPointed->getRenderWindow().draw(_sprite);
                return false;
            }
            if (_windowLayerPointed == NULL)
            {
                _windowLayerPointed->getRenderWindow().draw(_sprite);
                return true;
            }
            return false;
        }
        sf::Vector2u getTextureSize(void)
        {
            if (!_hasTexture)
                return {0, 0};
            return _texture.getSize();
        };
        /// @brief Returns the pointed window layer.
        /// @return Pointer to the window layer used
        BARD_ENGINE_NAMESPACE::WindowLayer_c *getWindowLayerPointed(void) { return _windowLayerPointed; };
        /// @brief Changes the actual texture of the sprite
        /// @param filePath Path to the texture file
        void setTexture(sf::String const filePath = "")
        {
            _hasTexture = !filePath.isEmpty();
            if (_hasTexture)
                _texture.loadFromFile(filePath);
            _sprite.setTexture(_texture);
        };
        void setPositionTile(sf::Vector2f positionTile) {
            _positionTile.x = positionTile.x;
            _positionTile.y = positionTile.y;
        };
        void setWindowLayerPointed(BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayerPointed = NULL) { _windowLayerPointed = windowLayerPointed; };
        /// @brief Returns directly the sprite used.
        sf::Sprite &getSprite(void) { return _sprite; };

    private:
        bool _hasTexture;
        sf::Vector2f _positionTile = {0, 0};
        sf::Sprite _sprite;
        sf::Texture _texture;
        BARD_ENGINE_NAMESPACE::WindowLayer_c *_windowLayerPointed = NULL;
    };
}
