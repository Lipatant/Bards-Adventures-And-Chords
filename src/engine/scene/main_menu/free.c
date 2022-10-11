/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/main_menu/free.c
** File description:
** Frees the selected scene
*/

#include "engine/scene/types.h"

void engine_scene_main_menu_free(scene_t *scene)
{
    if (scene == NULL)
        return;
    if (scene->data.main_menu.font != NULL)
        sfFont_destroy(scene->data.main_menu.font);
    if (scene->data.main_menu.sprite != NULL)
        sfSprite_destroy(scene->data.main_menu.sprite);
    if (scene->data.main_menu.texture != NULL)
        sfTexture_destroy(scene->data.main_menu.texture);
}
