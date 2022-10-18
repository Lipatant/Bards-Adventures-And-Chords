/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** utility/generation/perlin_noise/2d.cpp
** File description:
** Allows the creation of procedural maps, made following javidx9's video: https://www.youtube.com/watch?v=6-0UaeJBumA
*/

#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "utility/generation/hash.hpp"
#include "utility/generation/output.hpp"
#include "utility/namespace.hpp"

namespace BARD_UTILITY_NAMESPACE
{
    bool BARD_UTILITY_NAMESPACE::GenerationOuput2f_c::
        perlin_noise(unsigned int const octaves, float const bias, unsigned int const seed)
    {
        sf::Vector2f blending = {0, 0};
        sf::Vector2f sample_final = {0, 0};
        sf::Vector2i sample1 = {0, 0};
        sf::Vector2i sample2 = {0, 0};
        BARD_UTILITY_NAMESPACE::GenerationOuput2f_c seeds(getSize());
        float noise = 0.0;
        float scale = 0.0;
        float scale_total = 0.0;
        int pitch = 0;
        unsigned int starting_hash = 0;

        if (isEmpty() || seeds.isEmpty())
        {
            seeds.destroy();
            return true;
        }
        std::srand(seed);
        starting_hash = std::rand();
        for (unsigned int x = 0; x < _width; x++)
        {
            for (unsigned int y = 0; y < _height; y++)
            {
                starting_hash = (starting_hash + rand()) % BARD_UTILITY_NAMESPACE::HASH_SIZE;
                srand(seed + HASH[(x * _width + y + starting_hash) % BARD_UTILITY_NAMESPACE::HASH_SIZE] + std::rand());
                seeds.setValue({x, y}, (float)rand() / RAND_MAX, true);
            }
        }
        for (unsigned int x = 0; x < _width; x++)
        {
            for (unsigned int y = 0; y < _height; y++)
            {
                noise = 0.0;
                scale = 1.0;
                scale_total = 0.0;
                for (unsigned int o = 0; o < octaves; o++)
                {
                    pitch = _width >> o;
                    sample1.x = (x / pitch) * pitch;
                    sample1.y = (y / pitch) * pitch;
                    sample2.x = (sample1.x + pitch) % _width;
                    sample2.y = (sample1.y + pitch) % _width;
                    blending.x = (float)(x - sample1.x) / (float)pitch;
                    blending.y = (float)(y - sample1.y) / (float)pitch;
                    sample_final.x = (1.0 - blending.x) * seeds.getValues()[sample1.x][sample1.y] + blending.x * seeds.getValues()[sample2.x][sample1.y];
                    sample_final.y = (1.0 - blending.x) * seeds.getValues()[sample1.x][sample2.y] + blending.x * seeds.getValues()[sample2.x][sample2.y];
                    scale_total += scale;
                    noise += (blending.y * (sample_final.y - sample_final.x) + sample_final.x) * scale;
                    scale /= bias;
                }
                setValue({x, y}, noise / scale_total);
            }
        }
        seeds.destroy();
        return false;
    }
}
