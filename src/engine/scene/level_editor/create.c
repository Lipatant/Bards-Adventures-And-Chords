/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/create.c
** File description:
** Creates a new scene for level editing
*/

#include "engine/scene/types.h"
#include "engine/loaded_map.h"
#include "engine/window.h"

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
}
