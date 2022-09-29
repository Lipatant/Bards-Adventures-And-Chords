/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/tilemap.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #define TILE_DEFAULT 9
    #define TILE_HEIGHT 10
    #define TILEMAP_MAX_X 200
    #define TILEMAP_MAX_Y 200
    #define TILEMAP_MAX_Z 100

    #include <SFML/System/Vector2.h>

typedef struct __attribute__((packed))tilemap_s {
    short tile[TILEMAP_MAX_X][TILEMAP_MAX_Y][TILEMAP_MAX_Z];
} tilemap_t;

static const sfVector2u TILE_TEXTURES_OFFSET = {2, 0};
static const sfVector2u TILE_TEXTURES_OFFSET_AFTER = {1, 0};
static const sfVector2u TILE_TEXTURES_OFFSET_BEFORE = {1, 0};
static const sfVector2u TILE_TEXTURES_SIZE = {18, 18};

// Returns the cleared tilemap
// Returns NULL if a problem is encountered
tilemap_t *engine_tilemap_reset(tilemap_t *tilemap);