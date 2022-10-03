/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/tick.c
** File description:
** Updates a level editing scene
*/

#include "engine/loaded_map.h"
#include "engine/scene/types.h"

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
    if (scene->data.level_editor.loaded_map != NULL)
        on_loaded_map(scene);
}
