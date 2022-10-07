/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/types.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include "engine/tilemap.h"

typedef struct __attribute__((packed))map_s {
    tilemap_t tilemap;
} map_t;
