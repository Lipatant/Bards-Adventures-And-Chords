/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/free.c
** File description:
** Frees the selected scene
*/

#include "engine/scene/types.h"
#include "engine/loaded_map.h"

void engine_scene_level_editor_free(scene_t *scene)
{
    if (scene == NULL)
        return;
    if (scene->data.level_editor.loaded_map == NULL)
        return;
    engine_loaded_map_free(scene->data.level_editor.loaded_map);
}
