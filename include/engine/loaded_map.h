/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/loaded_map.h
** File description:
** Used to generate instances of a map, with textures...
*/

#pragma once
    #include "engine/sprite/types.h"
    #include "engine/map.h"

enum view_angles_indices {
    VIEW_ANGLE_0,
    VIEW_ANGLE_90,
    VIEW_ANGLE_180,
    VIEW_ANGLE_270,
    VIEW_ANGLE_TOTAL,
};

typedef struct loaded_map_s {
    map_t *map;
    sprite_t *sprite;
} loaded_map_t;

// Returns the generated loaded_map
// Returns NULL if a problem is encountered
loaded_map_t *engine_loaded_map_create(void);
