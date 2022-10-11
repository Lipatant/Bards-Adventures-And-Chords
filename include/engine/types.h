/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/types.h
** File description:
** Includes types found in others headers from engine
*/

#pragma once

typedef struct position_s {
    double x;
    double y;
    double z;
} position_t;

typedef struct position_tile_s {
    int x;
    int y;
    int z;
} position_tile_t;

    #include "engine/button/types.h"
    #include "engine/sprite/types.h"
    #include "engine/scene/types.h"
    #include "engine/tilemap/types.h"
