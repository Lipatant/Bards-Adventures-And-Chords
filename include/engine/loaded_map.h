/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/loaded_map.h
** File description:
** Used to generate instances of a map, with textures...
*/

#pragma once
    #include "engine/sprite/types.h"
    #include "engine/map.h"
    #include "engine/scene/types.h"
    #include "engine/types.h"

    #include "stdbool.h"

enum view_angles_indices {
    VIEW_ANGLE_DEFAULT,
    VIEW_ANGLE_0 = 0,
    VIEW_ANGLE_90,
    VIEW_ANGLE_180,
    VIEW_ANGLE_270,
    VIEW_ANGLE_TOTAL,
};

struct view_axe_params_s {
    int start;
    int end;
    short end_of_loop;
};

struct view_angle_params_s {
    struct view_axe_params_s x;
    struct view_axe_params_s y;
    struct view_axe_params_s z;
    float coef_x;
    float coef_y;
};

typedef struct loaded_map_s {
    map_t *map;
    sprite_t *sprite;
    struct view_angle_params_s view_angle;
    char view_angle_id;
} loaded_map_t;

static const struct view_angle_params_s VIEW_ANGLE_PARAMS[VIEW_ANGLE_TOTAL] = {
    {
        {0, TILEMAP_MAX_X, 1}, {0, TILEMAP_MAX_Y, 1}, {0, TILEMAP_MAX_Z, 1},
        1.0, 1.0
    },
    {
        {TILEMAP_MAX_X - 1, -1, -1}, {0, TILEMAP_MAX_Y, 1}, {0, TILEMAP_MAX_Z, 1},
        -1.0, 1.0
    },
    {
        {TILEMAP_MAX_X - 1, -1, -1}, {TILEMAP_MAX_Y - 1, -1, -1}, {0, TILEMAP_MAX_Z, 1},
        -1.0, -1.0
    },
    {
        {0, TILEMAP_MAX_X, 1}, {TILEMAP_MAX_Y - 1, -1, -1}, {0, TILEMAP_MAX_Z, 1},
        1.0, -1.0
    }
};

typedef struct scene_s scene_t;

// Returns the generated loaded_map
// Returns NULL if a problem is encountered
loaded_map_t *engine_loaded_map_create(void);
/// \param loaded_map Loaded map to select
/// \param window_layer Layer on which to display
/// \param center Position of the center of the screen
void engine_loaded_map_display(loaded_map_t *loaded_map, int const window_layer, position_t center);
/// \param scene Scene to select
void engine_loaded_map_display_level_editor(scene_t *scene);
void engine_loaded_map_free(loaded_map_t *loaded_map);
// Returns the id of the new view_angle
// Returns -1 if a problem is encountered
short engine_loaded_map_view_angle_rotate(loaded_map_t *loaded_map, bool const reverse_clockwise);
