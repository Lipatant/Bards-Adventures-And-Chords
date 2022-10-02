/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/types.h
** File description:
** Contains what's used for scenes
*/

#pragma once
    #include "engine/loaded_map.h"

typedef struct scene_level_editor_s {
    unsigned short type;
    loaded_map_t *loaded_map;
    int const window_layer;
} scene_level_editor_t;

typedef enum {
    SCENE_TYPE_LEVEL_EDITOR,
    SCENE_TYPE_TOTAL,
} scene_type_t;

typedef unsigned short scene_function_id_t;

enum scene_functions_indices {
    SCENE_FUNCTION_CREATE,
    SCENE_FUNCTION_FREE,
    SCENE_FUNCTION_TICK,
    SCENE_FUNCTION_TOTAL,
};

typedef struct scene_s {
    scene_type_t type;
    union {
        scene_level_editor_t level_editor;
    } data;
} scene_t;
