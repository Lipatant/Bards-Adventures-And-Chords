/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/tilemap/get_tile_propreties.c
** File description:
** Returns a tile's propreties
*/

#include "engine/tilemap.h"

tile_propreties_t engine_tilemap_get_tile_propreties(tile_t tile_id)
{
    for (unsigned int i = 0; i < TILE_DATAS_TOTAL; i++)
        if (tile_id == TILE_DATAS[i].id)
            return TILE_DATAS[i];
    return TILE_DATAS[0];
}
