/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** utility/generation/types.hpp
** File description:
** Includes classes for noise functions' outputs.
*/

#pragma once
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "utility/namespace.hpp"

namespace BARD_UTILITY_NAMESPACE
{
    class GenerationOuput2f_c
    {
    public:
        GenerationOuput2f_c(sf::Vector2u const size)
        {
            if (size.x == 0 || size.y == 0)
                return;
            _values = new float *[size.x];
            for (unsigned int x = 0; x < size.x; x++)
            {
                _values[x] = new float[size.y];
                for (unsigned int y = 0; y < size.y; y++)
                    _values[x][y] = 0;
            }
            _width = size.x;
            _height = size.y;
        };
        void destroy(void)
        {
            if (isEmpty())
                return;
            for (unsigned int x = 0; x < _width; x++)
                delete[] _values[x];
            delete[] _values;
            _values = NULL;
        };
        bool setValue(sf::Vector2u const position, float const value, bool const wrap = false)
        {
            if (isEmpty())
                return true;
            if (position.x >= _width && position.y >= _height && !wrap)
                return true;
            _values[position.x % _width][position.y % _height] = value;
            return false;
        }
        float getValue(sf::Vector2u const position, bool const wrap = false)
        {
            if (isEmpty())
                return 0;
            if (position.x >= _width && position.y >= _height && !wrap)
                return 0;
            return _values[position.x % _width][position.y % _height];
        }
        bool perlin_noise(unsigned int const octaves, float const bias, unsigned int const seed);
        float **&getValues(void) { return _values; };
        unsigned int getWidth(void) { return _width; };
        unsigned int getHeight(void) { return _width; };
        sf::Vector2u getSize(void) { return {_width, _height}; };
        bool isEmpty(void) { return (_width == 0 || _height == 0 || _values == NULL); };

    private:
        float **_values = NULL;
        unsigned int _width = 0;
        unsigned int _height = 0;
    };
}
