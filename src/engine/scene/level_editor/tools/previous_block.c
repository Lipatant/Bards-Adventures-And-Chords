/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor/tools/previous_block.c
** File description:
** Go to the previous block
*/

#include "engine/scene/types.h"

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

tile_t engine_scene_level_editor_tools_previous_block(scene_t *scene)
{
    unsigned int id = scene->data.level_editor.actual_tile_position;

    if (id < 1)
        id += TILE_DATAS_TOTAL;
    id -= 1;
    set_tile_proprety(scene, id);
}
