/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/free.c
** File description:
** Frees a scene
*/

#include "engine/scene.h"
#include <stdlib.h>

void engine_scene_free(scene_t *scene)
{
    if (scene == NULL)
        return;
    engine_scene_call(scene, SCENE_FUNCTION_FREE);
    free(scene);
}
