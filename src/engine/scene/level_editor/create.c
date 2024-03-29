/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/create.c
** File description:
** Creates a new scene for level editing
*/

#include "engine/scene/types.h"
#include "engine/loaded_map.h"
#include "engine/tilemap.h"
#include "engine/window.h"

static void set_tile_proprety(scene_t *scene, unsigned int id)
{
    unsigned int str_length = 0;

    id %= TILE_DATAS_TOTAL;
    str_length = sizeof(TILE_DATAS[id].name) / sizeof(char);
    scene->data.level_editor.tile_proprety.id = TILE_DATAS[id].id;
    scene->data.level_editor.tile_proprety.is_invisible = TILE_DATAS[id].is_invisible;
    scene->data.level_editor.tile_proprety.is_transparent = TILE_DATAS[id].is_transparent;
    scene->data.level_editor.tile_proprety.start = TILE_DATAS[id].start;
    scene->data.level_editor.tile_proprety.end = TILE_DATAS[id].end;
    for (unsigned int i = 0; i < str_length; i++)
        scene->data.level_editor.tile_proprety.name[i] = TILE_DATAS[id].name[i];
    scene->data.level_editor.actual_tile_position = id;
}

void engine_scene_level_editor_create(scene_t *scene)
{
    if (scene == NULL)
        return;
    if (scene->data.level_editor.loaded_map != NULL)
        engine_loaded_map_free(scene->data.level_editor.loaded_map);
    scene->data.level_editor.loaded_map = engine_loaded_map_create();
    scene->data.level_editor.window_layer = WINDOW_LAYER_DEFAULT_WINDOW;
    scene->data.level_editor.selector.x = 0;
    scene->data.level_editor.selector.y = 0;
    scene->data.level_editor.selector.z = 0;
    scene->data.level_editor.marker.x = 0;
    scene->data.level_editor.marker.y = 0;
    scene->data.level_editor.marker.z = 0;
    set_tile_proprety(scene, SCENE_LEVEL_EDITOR_DEFAULT_TILE_POSITION);
}
