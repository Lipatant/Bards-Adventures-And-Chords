/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/button.hpp
** File description:
** Includes buttons
*/

#pragma once
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include "engine/namespace.hpp"
#include "engine/sprite.hpp"

namespace BARD_ENGINE_NAMESPACE
{
    class Button_c
    {
    public:
        /// @brief Creates a new button
        /// @param string Text to display on the button
        Button_c(sf::String const string = "", sf::String const fontFilePath = "",
                 BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayerPointed = NULL)
        {
            setString(string);
            setFont(fontFilePath);
            _windowLayerPointed = windowLayerPointed;
        };
        /// @brief Replaces the actual string by a new one.
        /// @param string New value for the string
        void setString(sf::String string = "")
        {
            _string = string;
            _text.setString(string);
        };
        bool setFont(sf::String const filePath = "")
        {
            float scale = 0;
            if (filePath.isEmpty())
                return true;
            _font.loadFromFile(filePath);
            _text.setFont(_font);
            _text.setScale({1, 1});
            if (!_string.isEmpty())
            {
                _text.setString("Voix ambiguë d'un cœur qui au zéphyr préfère les jattes de kiwis");
                scale = 16 / _text.getLocalBounds().height;
                _text.setScale({scale, scale});
            }
            _text.setString(_string);
            return false;
        };
        bool display(BARD_ENGINE_NAMESPACE::WindowLayer_c *windowLayerPointed = NULL)
        {
            if (windowLayerPointed == NULL)
                windowLayerPointed = _windowLayerPointed;
            if (windowLayerPointed == NULL)
                return true;
            getSpriteActual().display(windowLayerPointed);
            windowLayerPointed->getRenderWindow().draw(_text);
            return false;
        };
        /// @brief Returns directly the font.
        sf::Font &getFont(void) { return _font; };
        /// @brief Returns the pointed font.
        /// @return Pointer to the font used
        sf::Font *getFontPointed(void) { return _fontPointed; };
        /// @brief Returns directly the sprite.
        BARD_ENGINE_NAMESPACE::Sprite_c &getSprite(void) { return _sprite; };
        /// @brief Returns the pointed sprite.
        /// @return Pointer to the sprite used
        BARD_ENGINE_NAMESPACE::Sprite_c *getSpritePointed(void) { return _spritePointed; };
        /// @brief Changes the font pointed.
        /// @param fontPointed Pointer to the new font
        void setFontPointed(sf::Font *fontPointed) { _fontPointed = fontPointed; };
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

    private:
        sf::Color _color = sf::Color::White;
        sf::Font _font;
        sf::Font *_fontPointed = NULL;
        sf::String _string = "";
        sf::Text _text;
        BARD_ENGINE_NAMESPACE::Sprite_c _sprite;
        BARD_ENGINE_NAMESPACE::Sprite_c *_spritePointed = NULL;
        BARD_ENGINE_NAMESPACE::WindowLayer_c *_windowLayerPointed = NULL;
    };
}
