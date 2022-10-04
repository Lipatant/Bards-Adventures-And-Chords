/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/tilemap/types.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include <stdbool.h>

typedef unsigned short tile_t;

typedef struct tile_propreties_s {
    tile_t id;
    char name[40];
    bool is_invisible;
    bool is_transparent;
    char start;
    char end;
} tile_propreties_t;

typedef struct __attribute__((packed))tilemap_s {
    tile_t tile[TILEMAP_MAX_X][TILEMAP_MAX_Y][TILEMAP_MAX_Z];
} tilemap_t;
