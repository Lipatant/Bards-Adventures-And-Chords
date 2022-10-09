/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/create.c
** File description:
** Adds a new map and returns it
*/

#include "engine/generation/perlin_noise.h"
#include "engine/tilemap.h"
#include "my.h"
#include <stdlib.h>
#include <time.h>

static void free_float_2d(float **array, unsigned int const width)
{
    if (array == NULL)
        return;
    for (unsigned int x = 0; x < width; x++)
        free(array[x]);
    free(array);
}

static short set_tile(unsigned int const x, unsigned int const y, unsigned int const z, float const max_z)
{
    if ((int)z == ((int)max_z - 1)) {
        if (max_z - (int)max_z < 0.5) {
            if (rand() % 6 == 0)
                return 18 + rand() % 2;
            return 17;
        }
        if (rand() % 6 == 0)
            return 15 + rand() % 2;
        return 14;
    }
    return 20;
}

static void random_generation(tilemap_t *tilemap)
{
    unsigned int seed = (unsigned int)time(NULL) + (long)tilemap;
    float max_z = 0;
    float **random_values = NULL;

    srand(seed);
    random_values = engine_generation_perlin_noise_2d(TILEMAP_MAX_X, TILEMAP_MAX_Y, 3, 1.5, seed);
    if (random_values == NULL)
        return;
    for (unsigned int x = 0; x < TILEMAP_MAX_X; x++) {
        for (unsigned int y = 0; y < TILEMAP_MAX_Y; y++) {
            max_z = MIN((random_values[x][y] / 2) * TILEMAP_MAX_Z, 1);
            for (unsigned int z = 0; z < (unsigned int)max_z; z++)
                tilemap->tile[x][y][z] = set_tile(x, y, z, max_z);
        }
    }
    free_float_2d(random_values, TILEMAP_MAX_X);
}

tilemap_t *engine_tilemap_reset(tilemap_t *tilemap)
{
    if (tilemap == NULL)
        return NULL;
    for (int unsigned x = 0; x < TILEMAP_MAX_X; x++)
        for (int unsigned y = 0; y < TILEMAP_MAX_Y; y++)
            for (int unsigned z = 0; z < TILEMAP_MAX_Z; z++)
                tilemap->tile[x][y][z] = TILE_DEFAULT;
    random_generation(tilemap);
    return tilemap;
}
