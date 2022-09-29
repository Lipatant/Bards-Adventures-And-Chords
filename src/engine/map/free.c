/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/free.c
** File description:
** Frees a map
*/

#include "engine/map.h"
#include <stdlib.h>

void engine_map_free(map_t *map)
{
    if (map == NULL)
        return;
    free(map);
}
