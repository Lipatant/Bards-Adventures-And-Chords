/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/struct.hpp
** File description:
** Includes the structures used for window.hpp
*/

#pragma once
#include "engine/namespace.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace BARD_ENGINE_NAMESPACE
{
    class WindowLayer_c
    {
    public:
        WindowLayer_c();
        /// @brief Returns whether or not you are on the window.
        /// @return true or false
        bool HasFocus() { return Focus; }
        /// @brief Returns whether or not you've just got the focus on the window.
        /// @return true or false
        bool GotFocus() { return (Focus && !FocusOld); }
        /// @brief Returns whether or not you've just lost the focus on the window.
        /// @return true or false
        bool LostFocus() { return (!Focus && FocusOld); }

    private:
        bool Focus = false;
        bool FocusOld = false;
    };
}
