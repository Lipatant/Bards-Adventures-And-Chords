/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/create.c
** File description:
** Adds a new map and returns it
*/

#include "engine/loaded_map.h"
#include <stdlib.h>

loaded_map_t *engine_loaded_map_create(void)
{
    loaded_map_t *loaded_map = malloc(sizeof(loaded_map_t));

    if (loaded_map == NULL)
        return NULL;
    loaded_map->map = engine_map_create();
    loaded_map->sprite = NULL;
    return loaded_map;
}
