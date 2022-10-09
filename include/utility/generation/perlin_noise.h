/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** utility/generation/perlin_noise.h
** File description:
** Includes sound functions
*/

#pragma once

// Returns the generated 2d noise.
// Returns NULL if a problem is encountered.
/// \param width Width (x) of the array to return
/// \param height Height (y) of the array to return
/// \param octaves numbers of levels of detail used
/// \param bias Smoothness? (at this point I have no idea)
/// \param seed seed to use of the generation
float **utility_generation_perlin_noise_2d(unsigned int const width, unsigned int const height,
    unsigned int const octaves, float const bias, unsigned int const seed);
