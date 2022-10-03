/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/types.h
** File description:
** Contains what's used for scenes
*/

#pragma once
    #include "engine/loaded_map.h"
    #include "engine/types.h"

typedef struct loaded_map_s loaded_map_t;
typedef struct position_tile_s position_tile_t;

typedef struct scene_level_editor_s {
    loaded_map_t *loaded_map;
    position_tile_t selector;
    int window_layer;
} scene_level_editor_t;

typedef enum {
    SCENE_TYPE_LEVEL_EDITOR,
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
    } data;
} scene_t;
