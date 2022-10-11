/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/main_menu/create.c
** File description:
** Creates a new scene for the main menu of the game
*/

#include "engine/scene/types.h"
#include "engine/window.h"

void engine_scene_main_menu_create(scene_t *scene)
{
    if (scene == NULL)
        return;
    if (scene->data.main_menu.font != NULL)
        sfFont_destroy(scene->data.main_menu.font);
    if (scene->data.main_menu.sprite != NULL)
        sfSprite_destroy(scene->data.main_menu.sprite);
    if (scene->data.main_menu.texture != NULL)
        sfTexture_destroy(scene->data.main_menu.texture);
    scene->data.main_menu.font = sfFont_createFromFile("graphics/fonts/Aileron-Bold.otf");
    scene->data.main_menu.sprite = NULL;
    scene->data.main_menu.texture = NULL;
    scene->data.main_menu.window_layer = WINDOW_LAYER_DEFAULT_WINDOW;
}
