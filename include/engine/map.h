/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include "engine/map/file.h"
    #include "engine/map/types.h"

// Returns the generated map
// Returns NULL if a problem is encountered
map_t *engine_map_create(void);
void engine_map_free(map_t *map);
