/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include "engine/tilemap.h"

typedef struct __attribute__((packed))map_s {
    tilemap_t tilemap;
} map_t;

// Returns the generated map
// Returns NULL if a problem is encountered
map_t *engine_map_create(void);
void engine_map_free(map_t *map);
