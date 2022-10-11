/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/main_menu/tick.c
** File description:
** Updates a main menu scene
*/

#include "engine/scene/types.h"
#include "engine/struct/global.h"
#include "engine/window.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>

static void display_text(scene_t *scene, window_layers_t *window)
{
    sfText *text = NULL;
    sfVector2f scale = {0.4, 0.4};

    if (scene->data.main_menu.font == NULL)
        return;
    text = sfText_create();
    sfText_setFont(text, scene->data.main_menu.font);
    sfText_setString(text, "Host\n\nJoin");
    sfText_setScale(text, scale);
    sfRenderWindow_drawText(window->render_window, text, NULL);
    sfText_destroy(text);
}

void engine_scene_main_menu_tick(scene_t *scene)
{
    unsigned int window_layer = 0;

    if (scene == NULL)
        return;
    window_layer = scene->data.main_menu.window_layer;
    if (!engine_window_layer_is_valid(window_layer))
        return;
    if (&ENGINE.windows[window_layer].render_window == NULL)
        return;
    engine_window_view_set_center(window_layer, 0, 0);
    engine_window_update_view(window_layer);
    for (unsigned int i = 0; i < SCENE_MAIN_MENU_BUTTON_TOTAL; i++)
        display_text(scene, &ENGINE.windows[window_layer]);
}
