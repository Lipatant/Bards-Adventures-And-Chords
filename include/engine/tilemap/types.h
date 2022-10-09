/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/tilemap/types.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include <stdbool.h>

typedef enum {
    TILE_CONNECTION_PX,
    TILE_CONNECTION_MX,
    TILE_CONNECTION_PY,
    TILE_CONNECTION_MY,
    TILE_CONNECTION_TOP,
    TILE_CONNECTION_BOTTOM,
    TILE_CONNECTION_TOTAL,
} tile_connection_t;

typedef bool tile_connection_data_t[TILE_CONNECTION_TOTAL];

enum tile_connection_data_indices {
    TILE_CONNECTION_DATA_EMPTY,
    TILE_CONNECTION_DATA_FILLED,
    TILE_CONNECTION_DATA_SLAB,
    TILE_CONNECTION_DATA_TOTAL,
};

static const tile_connection_data_t TILE_CONNECTION_DATA[TILE_CONNECTION_DATA_TOTAL] = {
    {false, false, false, false, false, false},
    {true, true, true, true, true, true},
    {false, false, false, false, false, true},
};

typedef unsigned short tile_t;

typedef char tile_name_t[40];

/// \param id ( tile_t ) ID of the texture
/// \param name ( tile_name_t ) Name used to find the tile
/// \param is_invisible ( bool ) If the tile has a texture
/// \param is_transparent ( bool ) If the texture has some gaps in it
/// \param start ( char ) Where the tile starts (in pixels)
/// \param end ( char ) Where the tile ends (in pixels)
/// \param connection_datas ( unsigned char ) Used for display optimization
typedef struct tile_propreties_s {
    tile_t id;
    tile_name_t name;
    bool is_invisible;
    bool is_transparent;
    char start;
    char end;
    unsigned char connection_datas;
} tile_propreties_t;

typedef struct __attribute__((packed))tilemap_s {
    tile_t tile[TILEMAP_MAX_X][TILEMAP_MAX_Y][TILEMAP_MAX_Z];
} tilemap_t;
