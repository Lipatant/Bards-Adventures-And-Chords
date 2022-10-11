/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/main_menu/create.c
** File description:
** Creates a new scene for the main menu of the game
*/

#include "engine/button.h"
#include "engine/scene/types.h"
#include "engine/sprite.h"
#include "engine/window.h"

static button_t *generate_button(scene_t *scene, unsigned int const id)
{
    button_t *button = engine_button_create();

    if (button == NULL)
        return NULL;
    button->font_pointed = &scene->data.main_menu.font;
    button->sprite_pointed = &scene->data.main_menu.sprite;
}

void engine_scene_main_menu_create(scene_t *scene)
{
    if (scene == NULL)
        return;
    if (scene->data.main_menu.font != NULL)
        sfFont_destroy(scene->data.main_menu.font);
    if (scene->data.main_menu.sprite != NULL)
        engine_sprite_destroy(scene->data.main_menu.sprite);
    scene->data.main_menu.font = sfFont_createFromFile("graphics/fonts/Aileron-Bold.otf");
    scene->data.main_menu.sprite = NULL;
    scene->data.main_menu.window_layer = WINDOW_LAYER_DEFAULT_WINDOW;
    for (unsigned int i = 0; i < SCENE_MAIN_MENU_BUTTON_TOTAL; i++)
        scene->data.main_menu.button[i] = engine_button_create();
}
