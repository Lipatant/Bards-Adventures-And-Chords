/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/create.c
** File description:
** Creates a new scene depending on the value
*/

#include "engine/scene.h"

void engine_scene_call(scene_t *scene, scene_call_id_t const scene_call_id)
{
    if (scene == NULL)
        return;
    if (scene->type < 0 || scene->type >= SCENE_TYPE_TOTAL)
        return;
    if (scene->type < 0 || scene->type >= SCENE_CALL_TOTAL)
        return;
    SCENE_FUNCTIONS[scene->type][scene_call_id](scene);
}
