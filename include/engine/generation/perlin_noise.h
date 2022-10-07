/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/input.h
** File description:
** Includes everything used for the engine
*/

#pragma once

// Returns the generated 2d noise.
// Returns NULL if a problem is encountered.
/// \param width width (x) of the array to return
/// \param height height (y) of the array to return
/// \param octaves numbers of levels of detail used
/// \param bias ??? (at this point I have no idea)
/// \param seed seed to use of the generation
float **engine_generation_perlin_noise_2d(unsigned int const width, unsigned int const height,
    unsigned int const octaves, float const bias, unsigned int const seed);
