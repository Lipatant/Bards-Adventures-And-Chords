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
    #define TILEMAP_MAX_Y 40
    #define TILEMAP_MAX_Z 20

    #include "engine/tilemap/types.h"
    #include <SFML/System/Vector2.h>
    #include <stdbool.h>

typedef struct tile_propreties_s tile_propreties_t;

static const tile_propreties_t TILE_DATAS[] = {
    {0, "AIR", true, true, 0, 0, TILE_CONNECTION_DATA_EMPTY},
    {10, "LIGHT_GRASS", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {11, "GRASS_1", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {12, "GRASS_2", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {13, "GRASS_3", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {14, "SANDSTONE_1", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {15, "SANDSTONE_2", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {16, "DIRT_1", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {17, "DIRT_2", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {18, "DIRT_dark", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {20, "GRASS_on_DIRT_1", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {21, "GRASS_on_DIRT_2", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {22, "GRASS_on_DIRT_slab", false, true, 0, 6, TILE_CONNECTION_DATA_SLAB},
    {23, "SNOW_on_DIRT_1", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {24, "SNOW_on_DIRT_2", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {25, "SNOW_on_DIRT_slab", false, true, 0, 6, TILE_CONNECTION_DATA_SLAB},
    {26, "SNOW_cube", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {27, "SNOW_layer", false, true, 0, 2, TILE_CONNECTION_DATA_SLAB},
    {28, "HAY_bale", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {29, "HAY", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {30, "ORANGE_GRASS_on_DIRT_1", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {31, "ORANGE_GRASS_on_DIRT_2", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {32, "ORANGE_GRASS_on_DIRT_slab", false, true, 0, 6, TILE_CONNECTION_DATA_SLAB},
    {33, "WATER_full", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {34, "WATER", false, true, 0, 8, TILE_CONNECTION_DATA_SLAB},
    {35, "LAVA_full", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {36, "LAVA", false, true, 0, 8, TILE_CONNECTION_DATA_SLAB},
    {37, "ACID_full", false, false, 0, 10, TILE_CONNECTION_DATA_FILLED},
    {38, "ACID", false, true, 0, 8, TILE_CONNECTION_DATA_SLAB},
};

static const unsigned long TILE_DATAS_TOTAL = (sizeof(TILE_DATAS) / sizeof(tile_propreties_t));

static const sfVector2u TILE_TEXTURES_OFFSET = {2, 0};
static const sfVector2u TILE_TEXTURES_OFFSET_AFTER = {1, 0};
static const sfVector2u TILE_TEXTURES_OFFSET_BEFORE = {1, 0};
static const sfVector2u TILE_TEXTURES_SIZE = {18, 18};

// Returns the cleared tilemap
// Returns NULL if a problem is encountered
tilemap_t *engine_tilemap_reset(tilemap_t *tilemap);
// Returns the found tile_propreties.
// Returns the first one if a problem is encountered.
/// \param tile_id Id of the tile
tile_propreties_t engine_tilemap_get_tile_propreties(tile_t tile_id);
