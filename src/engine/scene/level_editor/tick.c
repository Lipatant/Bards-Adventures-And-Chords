/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/tick.c
** File description:
** Updates a level editing scene
*/

#include "engine/input.h"
#include "engine/loaded_map.h"
#include "engine/scene/level_editor.h"
#include "engine/scene/types.h"
#include "my.h"

static void place_marker(scene_t *scene)
{
    scene->data.level_editor.marker.x = scene->data.level_editor.selector.x;
    scene->data.level_editor.marker.y = scene->data.level_editor.selector.y;
    scene->data.level_editor.marker.z = scene->data.level_editor.selector.z;
}

static void placement_inputs(scene_t *scene)
{
    position_tile_t selector = scene->data.level_editor.selector;

    if (scene->data.level_editor.loaded_map == NULL || scene->data.level_editor.loaded_map->map == NULL)
        return;
    if (engine_input_is_pressed(INPUT_EDITOR_PLACE))
        scene->data.level_editor.loaded_map->map->tilemap.tile[selector.x][selector.y][selector.z] = 20;
    if (engine_input_is_pressed(INPUT_EDITOR_ERASE))
        scene->data.level_editor.loaded_map->map->tilemap.tile[selector.x][selector.y][selector.z] = TILE_DEFAULT;
    if (engine_input_is_pressed(INPUT_EDITOR_FILL_RECTANGLE))
        engine_scene_level_editor_tools_fill_rectangle(scene, 18);
    if (engine_input_is_pressed(INPUT_EDITOR_FILL_REPLACE))
        engine_scene_level_editor_tools_fill_replace(scene, 70);
}

static void manage_inputs(scene_t *scene)
{
    position_tile_t movement = {0, 0, 0};

    if (engine_input_is_pressed(INPUT_DOWN))
        movement.x += 1;
    if (engine_input_is_pressed(INPUT_UP))
        movement.x -= 1;
    if (engine_input_is_pressed(INPUT_LEFT))
        movement.y += 1;
    if (engine_input_is_pressed(INPUT_RIGHT))
        movement.y -= 1;
    if (engine_input_is_pressed(INPUT_EDITOR_DOWN))
        movement.z -= 1;
    if (engine_input_is_pressed(INPUT_EDITOR_UP))
        movement.z += 1;
    scene->data.level_editor.selector.x = MAX(MIN(scene->data.level_editor.selector.x + movement.x, 0), TILEMAP_MAX_X - 1);
    scene->data.level_editor.selector.y = MAX(MIN(scene->data.level_editor.selector.y + movement.y, 0), TILEMAP_MAX_Y - 1);
    scene->data.level_editor.selector.z = MAX(MIN(scene->data.level_editor.selector.z + movement.z, 0), TILEMAP_MAX_Z - 1);
    if (engine_input_is_pressed(INPUT_EDITOR_PLACE_MARKER))
        place_marker(scene);
    placement_inputs(scene);
}

static void on_loaded_map(scene_t *scene)
{
    position_t center = {
        scene->data.level_editor.selector.x,
        scene->data.level_editor.selector.y,
        scene->data.level_editor.selector.z,
    };

    engine_loaded_map_display_level_editor(scene);
}

void engine_scene_level_editor_tick(scene_t *scene)
{
    if (scene == NULL)
        return;
    manage_inputs(scene);
    if (scene->data.level_editor.loaded_map != NULL)
        on_loaded_map(scene);
}
