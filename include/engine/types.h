/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/types.h
** File description:
** Includes types found in others headers from engine
*/

#pragma once
    #include "engine/sprite/types.h"

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
