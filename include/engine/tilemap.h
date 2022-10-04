/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/tilemap.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #define TILE_DEFAULT 0
    #define TILE_EDITOR 1
    #define TILE_EDITOR_FILL 2
    #define TILE_HEIGHT 10
    #define TILE_FLAT_X 16
    #define TILE_FLAT_Y 8
    #define TILEMAP_MAX_X 40
    #define TILEMAP_MAX_Y 100
    #define TILEMAP_MAX_Z 20

    #include "engine/tilemap/types.h"
    #include <SFML/System/Vector2.h>
    #include <stdbool.h>

typedef struct tile_propreties_s tile_propreties_t;

static const tile_propreties_t TILE_DATAS[] = {
    {0, "AIR", true, true, 0, 0},
    {10, "LIGHT GRASS", false, false, 0, 10},
    {11, "GRASS 1", false, false, 0, 10},
    {12, "GRASS 2", false, false, 0, 10},
    {13, "GRASS 3", false, false, 0, 10},
    {14, "SANDSTONE 1", false, false, 0, 10},
    {15, "SANDSTONE 2", false, false, 0, 10},
    {16, "DIRT 1", false, false, 0, 10},
    {17, "DIRT 2", false, false, 0, 10},
    {18, "DIRT dark", false, false, 0, 10},
    {20, "GRASS on DIRT 1", false, false, 0, 10},
    {21, "GRASS on DIRT 2", false, false, 0, 10},
    {22, "GRASS on DIRT slab", false, true, 0, 6},
    {23, "SNOW on DIRT 1", false, false, 0, 10},
    {24, "SNOW on DIRT 2", false, false, 0, 10},
    {25, "SNOW on DIRT slab", false, true, 0, 6},
    {26, "SNOW cube", false, false, 0, 10},
    {27, "SNOW layer", false, true, 0, 2},
    {28, "HAY bale", false, false, 0, 10},
    {29, "HAY", false, false, 0, 10},
    {20, "ORANGE GRASS on DIRT 1", false, false, 0, 10},
    {21, "ORANGE GRASS on DIRT 2", false, false, 0, 10},
    {22, "ORANGE GRASS on DIRT slab", false, true, 0, 6},
    {23, "WATER full", false, false, 0, 10},
    {24, "WATER", false, true, 0, 8},
    {25, "LAVA full", false, false, 0, 10},
    {26, "LAVA", false, true, 0, 8},
    {27, "ACID full", false, false, 0, 10},
    {28, "ACID", false, true, 0, 8},
};

static const tile_t TILE_DATAS_TOTAL = sizeof(TILE_DATAS) / sizeof(tile_propreties_t);

static const sfVector2u TILE_TEXTURES_OFFSET = {2, 0};
static const sfVector2u TILE_TEXTURES_OFFSET_AFTER = {1, 0};
static const sfVector2u TILE_TEXTURES_OFFSET_BEFORE = {1, 0};
static const sfVector2u TILE_TEXTURES_SIZE = {18, 18};

// Returns the cleared tilemap
// Returns NULL if a problem is encountered
tilemap_t *engine_tilemap_reset(tilemap_t *tilemap);
