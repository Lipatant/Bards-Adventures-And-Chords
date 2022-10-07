/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/tools/load_file.c
** File description:
** Loads a new map
*/

#include "engine/map.h"
#include "engine/scene/types.h"
#include <stdbool.h>

bool engine_scene_level_editor_tools_load_file(scene_t *scene, char const *path)
{
    map_t *map = NULL;

    if (scene == NULL || path == NULL)
        return false;
    map = engine_map_file_load(path);
    if (map == NULL)
        return false;
    engine_map_free(scene->data.level_editor.loaded_map->map);
    scene->data.level_editor.loaded_map->map = map;
    return true;
}
