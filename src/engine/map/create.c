/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/create.c
** File description:
** Adds a new map and returns it
*/

#include "engine/map.h"
#include <stdlib.h>

map_t *engine_map_create(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL)
        return NULL;
    engine_tilemap_reset(&map->tilemap);
    return map;
}
