/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/ui/button.cpp
** File description:
** Various things used for uIButtons
*/

#include "engine/ui/button.hpp"
#include "engine/units.hpp"

namespace BARD_ENGINE_NAMESPACE
{
    bool BARD_ENGINE_NAMESPACE::UIButton_c::setFont(sf::String const filePath = "")
    {
        float scale = 0;
        if (filePath.isEmpty())
            return true;
        _font.loadFromFile(filePath);
        _text.setFillColor(_color);
        _text.setFont(_font);
        _text.setScale({1, 1});
        if (!_string.isEmpty())
        {
            _text.setString("Voix ambiguë d'un cœur qui au zéphyr préfère les jattes de kiwis");
            scale = (TILE / _text.getLocalBounds().height) * 0.5;
            _text.setScale({scale, scale});
        }
        _text.setString(_string);
        return false;
    };
};
