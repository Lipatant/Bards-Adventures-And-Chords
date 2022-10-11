/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/types.h
** File description:
** Contains what's used for scenes
*/

#pragma once
    #include "engine/loaded_map.h"
    #include "engine/tilemap/types.h"
    #include "engine/types.h"
    #include <SFML/Graphics/Font.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Network/IpAddress.h>

    #define SCENE_LEVEL_EDITOR_DEFAULT_TILE_POSITION 0

typedef struct loaded_map_s loaded_map_t;
typedef struct position_tile_s position_tile_t;

typedef struct scene_level_editor_s {
    loaded_map_t *loaded_map;
    position_tile_t selector;
    position_tile_t marker;
    unsigned int actual_tile_position;
    tile_propreties_t tile_proprety;
    unsigned int window_layer;
} scene_level_editor_t;

typedef struct scene_server_s {
    sfIpAddress ip_address;
    unsigned short port;
} scene_server_t;

typedef struct scene_main_menu_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfFont *font;
    unsigned int window_layer;
} scene_main_menu_t;

typedef enum {
    SCENE_TYPE_LEVEL_EDITOR,
    SCENE_TYPE_SERVER,
    SCENE_TYPE_MAIN_MENU,
    SCENE_TYPE_TOTAL,
} scene_type_t;

typedef unsigned char scene_call_id_t;

enum scene_calls_indices {
    SCENE_CALL_CREATE,
    SCENE_CALL_FREE,
    SCENE_CALL_TICK,
    SCENE_CALL_TOTAL,
};

typedef struct scene_s {
    scene_type_t type;
    union {
        scene_level_editor_t level_editor;
        scene_server_t server;
        scene_main_menu_t main_menu;
    } data;
} scene_t;
