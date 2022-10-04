/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/tools/fill/rectangle.c
** File description:
** Fills a rectangle
*/

#include "engine/loaded_map.h"
#include "engine/scene/types.h"

void engine_scene_level_editor_tools_fill_rectangle(scene_t *scene, unsigned short const tile)
{
    position_tile_t start = scene->data.level_editor.marker;
    position_tile_t end = scene->data.level_editor.selector;

    if (start.x > end.x) {
        start.x += end.x;
        end.x = start.x - end.x;
        start.x -= end.x;
    };
    if (start.y > end.y) {
        start.y += end.y;
        end.y = start.y - end.y;
        start.y -= end.y;
    };
    if (start.z > end.z) {
        start.z += end.z;
        end.z = start.z - end.z;
        start.z -= end.z;
    };
    for (int x = start.x; x <= end.x; x++)
        for (int y = start.y; y <= end.y; y++)
            for (int z = start.z; z <= end.z; z++)
            scene->data.level_editor.loaded_map->map->tilemap.tile[x][y][z] = tile;
}
