/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/ui/box.hpp
** File description:
** Includes buttons
*/

#pragma once
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include "engine/namespace.hpp"
#include "engine/sprite.hpp"
#include "engine/units.hpp"
#include "engine/window/layer.hpp"

namespace BARD_ENGINE_NAMESPACE
{
    class UIBox_c
    {
    public:
        UIBox_c(BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayerPointed = NULL)
        {
            getSpriteActual().setTexture("graphics/gui.png");
            _windowLayerPointed = windowLayerPointed;
        };
        /// @brief Displays on a windowLayer an uibox
        /// @param windowLayerPointed Pointer to the window layer used for display
        /// @return True if a problem is encountered. Otherwise, returns false
        bool display(BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayerPointed);
        /// @brief Returns directly the sprite.
        BARD_ENGINE_NAMESPACE::Sprite_c &getSprite(void) { return _sprite; };
        /// @brief Returns the pointed sprite.
        /// @return Pointer to the sprite used
        BARD_ENGINE_NAMESPACE::Sprite_c *getSpritePointed(void) { return _spritePointed; };
        /// @brief Changes the sprite pointed.
        /// @param spritePointed Pointer to the new sprite
        void setSpritePointed(BARD_ENGINE_NAMESPACE::Sprite_c *spritePointed) { _spritePointed = spritePointed; };
        BARD_ENGINE_NAMESPACE::Sprite_c &getSpriteActual(void)
        {
            if (_spritePointed != NULL)
                return *getSpritePointed();
            return getSprite();
        };
        /// @brief Returns the pointed window layer.
        /// @return Pointer to the window layer used
        BARD_ENGINE_NAMESPACE::WindowLayer_c *getWindowLayerPointed(void) { return _windowLayerPointed; };
        void setPositionTile(sf::Vector2f positionTile)
        {
            _positionTile.x = positionTile.x;
            _positionTile.y = positionTile.y;
        };
        void setSizeTile(sf::Vector2f sizeTile)
        {
            _sizeTile.x = sizeTile.x;
            _sizeTile.y = sizeTile.y;
        };

    private:
        sf::Color _color = sf::Color::Red;
        sf::Vector2f _positionTile = {0, 0};
        sf::Vector2u _sizeTile = {0, 0};
        BARD_ENGINE_NAMESPACE::Sprite_c _sprite;
        BARD_ENGINE_NAMESPACE::Sprite_c *_spritePointed = NULL;
        BARD_ENGINE_NAMESPACE::WindowLayer_c *_windowLayerPointed = NULL;
    };
}
