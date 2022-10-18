/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/struct.hpp
** File description:
** Includes the structures used for window.hpp
*/

#pragma once
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include "engine/namespace.hpp"

#define DEFAULT_WINDOW_COLOR sf::Color::Black
#define DEFAULT_WINDOW_FPS 120
#define DEFAULT_WINDOW_FOCUS true
#define DEFAULT_WINDOW_PARAMS sf::Style::Fullscreen | sf::Style::Close
static const std::string DEFAULT_WINDOW_NAME = "Bards";
// Orinal: 256x224
static const sf::Vector2u DEFAULT_WINDOW_RESOLUTION = {400, 224};

namespace BARD_ENGINE_NAMESPACE
{
    class WindowLayer_c
    {
    public:
        WindowLayer_c(void)
        {
            sf::VideoMode VideoMode = sf::VideoMode(DEFAULT_WINDOW_RESOLUTION.x, DEFAULT_WINDOW_RESOLUTION.y);
            sf::String Title = DEFAULT_WINDOW_NAME;

            _renderWindow.create(VideoMode, Title);
        };
        /// @brief Updates the window.
        void update(void);
        /// @brief Destroys the window and it's content.
        void destroy(void);
        /// @brief Returns directly the RenderWindow.
        /// @return _RenderWindow
        sf::RenderWindow &getRenderWindow(void);
        /// @brief Returns whether or not you are on the window.
        /// @return true or false
        bool hasFocus() { return _focus; }
        /// @brief Returns whether or not you've just got the focus on the window.
        /// @return true or false
        bool gotFocus() { return (_focus && !_focusOld); }
        /// @brief Returns whether or not you've just lost the focus on the window.
        /// @return true or false
        bool lostFocus() { return (!_focus && _focusOld); }

    private:
        sf::RenderWindow _renderWindow;
        bool _focus = false;
        bool _focusOld = false;
    };
}
