/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/struct.hpp
** File description:
** Includes the structures used for window.hpp
*/

#pragma once
#include "engine/namespace.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace BARD_ENGINE_NAMESPACE
{
    class WindowLayer_c
    {
    public:
        WindowLayer_c(void)
        {
            sf::VideoMode VideoMode = sf::VideoMode(500, 500);
            sf::String Title = "Bards";

            _RenderWindow.create(VideoMode, Title);
        };
        void destroy(void)
        {
            _RenderWindow.close();
        };
        /// @brief Returns directly the RenderWindow
        /// @return _RenderWindow
        sf::RenderWindow &getRenderWindow(void)
        {
            return _RenderWindow;
        };
        /// @brief Returns whether or not you are on the window.
        /// @return true or false
        bool hasFocus() { return _Focus; }
        /// @brief Returns whether or not you've just got the focus on the window.
        /// @return true or false
        bool gotFocus() { return (_Focus && !_FocusOld); }
        /// @brief Returns whether or not you've just lost the focus on the window.
        /// @return true or false
        bool lostFocus() { return (!_Focus && _FocusOld); }

    private:
        sf::RenderWindow _RenderWindow;
        bool _Focus = false;
        bool _FocusOld = false;
    };
}
