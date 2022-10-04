/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/tools/fill/replace.c
** File description:
** Replace every block of a type by another
*/

#include "engine/loaded_map.h"
#include "engine/scene/types.h"
#include "my.h"

static position_tile_t tile_position(position_tile_t position, int const x, int const y, int const z)
{
    position.x = MAX(MIN(position.x + x, 0), TILEMAP_MAX_X - 1);
    position.y = MAX(MIN(position.y + y, 0), TILEMAP_MAX_Y - 1);
    position.z = MAX(MIN(position.z + z, 0), TILEMAP_MAX_Z - 1);
    return position;
}

static void replace_tile(scene_t *scene, position_tile_t position, unsigned short const source, unsigned short const tile, int limit)
{
    position_tile_t coor[6] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

    if (limit == 0 || source == TILE_DEFAULT ||
        scene->data.level_editor.loaded_map->map->tilemap.tile[position.x][position.y][position.z] == tile ||
        scene->data.level_editor.loaded_map->map->tilemap.tile[position.x][position.y][position.z] != source)
        return;
    scene->data.level_editor.loaded_map->map->tilemap.tile[position.x][position.y][position.z] = tile;
    for (int i = 0; i < 6; i++)
        replace_tile(scene, tile_position(position, coor[i].x, coor[i].y, coor[i].z), source, tile, limit - 1);
}

void engine_scene_level_editor_tools_fill_replace(scene_t *scene, unsigned short const tile)
{
    position_tile_t selector = scene->data.level_editor.selector;
    unsigned short source = scene->data.level_editor.loaded_map->map->tilemap.tile[selector.x][selector.y][selector.z];

    replace_tile(scene, scene->data.level_editor.selector, source, tile, 10000);
}
