/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/loaded_map/free.c
** File description:
** Frees a loaded_map
*/

#include "engine/loaded_map.h"
#include "engine/sprite.h"
#include <stdlib.h>

void engine_loaded_map_free(loaded_map_t *loaded_map)
{
    if (loaded_map == NULL)
        return;
    engine_map_free(loaded_map->map);
    engine_sprite_destroy(loaded_map->sprite);
    free(loaded_map);
}
