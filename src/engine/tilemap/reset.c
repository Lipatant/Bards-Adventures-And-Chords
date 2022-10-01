/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/create.c
** File description:
** Adds a new map and returns it
*/

#include "engine/tilemap.h"
#include <stdlib.h>

static short set_tile(unsigned int const x, unsigned int const y, unsigned int const z)
{
    if (z == 0 && x == 0 && y == 0)
        return 30;
    if (z <= 2 && x == y && x == TILEMAP_MAX_Y - y - 1)
        return 36;
    else {
        if (z == 0 && x == y)
            return 88;
        if (z == 0 && x == TILEMAP_MAX_Y - y - 1)
            return 98;
    }
    if (z == 0)
        return 0;
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
    return tilemap;
}
