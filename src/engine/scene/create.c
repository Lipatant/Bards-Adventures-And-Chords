/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/create.c
** File description:
** Creates a new scene depending on the value
*/

#include "engine/scene.h"
#include <stdlib.h>

scene_t *engine_scene_create(scene_type_t const scene_type)
{
    scene_t *scene = NULL;

    if (scene_type < 0 || scene_type >= SCENE_TYPE_TOTAL)
        return NULL;
    scene = malloc(sizeof(scene_t));
    if (scene == NULL)
        return NULL;
    scene->type = scene_type;
    engine_scene_call(scene, SCENE_CALL_CREATE);
    return scene;
}
