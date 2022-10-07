/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/create.c
** File description:
** Adds a new map and returns it
*/

#include "engine/generation/perlin_noise.h"
#include "engine/tilemap.h"
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

static void free_float_2d(float **array, unsigned int const width)
{
    if (array == NULL)
        return;
    for (unsigned int x = 0; x < width; x++)
        free(array[x]);
    free(array);
}

static void random_generation(tilemap_t *tilemap)
{
    unsigned int seed = (unsigned int)time(NULL) + (long)tilemap;
    float **random_values = NULL;

    srand(seed);
    printf("seed: %i\n", (int)seed);
    random_values = engine_generation_perlin_noise_2d(TILEMAP_MAX_X, TILEMAP_MAX_Y, 5, 2.0, seed);
    if (random_values == NULL)
        return;
    for (unsigned int x = 0; x < TILEMAP_MAX_X; x++) {
        for (unsigned int y = 0; y < TILEMAP_MAX_Y; y++) {
            for (unsigned int z = 0; z < ((random_values[x][y] + 1) / 2) * TILEMAP_MAX_Z * 0.2; z++)
                tilemap->tile[x][y][z] = 10;
        }
    }
    free_float_2d(random_values, TILEMAP_MAX_X);
}

static short set_tile(unsigned int const x, unsigned int const y, unsigned int const z)
{
    if (z == 0)
        return 10;
    return TILE_DEFAULT;
}

tilemap_t *engine_tilemap_reset(tilemap_t *tilemap)
{
    if (tilemap == NULL)
        return NULL;
    for (int unsigned x = 0; x < TILEMAP_MAX_X; x++)
        for (int unsigned y = 0; y < TILEMAP_MAX_Y; y++)
            for (int unsigned z = 0; z < TILEMAP_MAX_Z; z++)
                tilemap->tile[x][y][z] = set_tile(x, y ,z);
    random_generation(tilemap);
    return tilemap;
}
