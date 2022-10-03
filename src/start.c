/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** main.c
** File description:
** Main function
*/

#include "my.h"
#include "returned.h"

#include "engine.h"
#include "engine/window.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

engine_t ENGINE;

static int poll_single_event(window_layers_t *window, sfEvent *event)
{
    if (event == NULL)
        return 0;
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window->render_window);
    if (event->type == sfEvtGainedFocus)
        window->has_focus = true;
    if (event->type == sfEvtLostFocus)
        window->has_focus = false;
    return 1;
}

int engine_window_poll_events(int const window_layer)
{
    sfEvent event;
    window_layers_t *window = &(ENGINE.windows[WINDOW_LAYER_MAIN_GAME]);
    int returned = 0;

    if (sfKeyboard_isKeyPressed(sfKeyEscape) && window->has_focus)
        sfRenderWindow_close(window->render_window);
    while (sfRenderWindow_pollEvent(window->render_window, &event))
        returned += poll_single_event(window, &event);
    return returned;
}

int start(int const ac, char * const *av, char * const *env)
{
    scene_t *scene_level_editor = NULL;

    engine_window_create(WINDOW_LAYER_DEFAULT_WINDOW);
    ENGINE.default_window = &ENGINE.windows[WINDOW_LAYER_DEFAULT_WINDOW];
    if (ENGINE.windows[WINDOW_LAYER_MAIN_GAME].render_window == NULL)
        return RETURNED_EXIT;
    ENGINE.delta = 0;
    ENGINE.delta_clock = sfClock_create();
    ENGINE.seconds_clock = sfClock_create();
    ENGINE.seconds_time = 0;
    scene_level_editor = engine_scene_create(SCENE_TYPE_LEVEL_EDITOR);
    while (sfRenderWindow_isOpen(ENGINE.default_window->render_window)) {
        engine_window_poll_events(WINDOW_LAYER_DEFAULT_WINDOW);
        if (ENGINE.delta_clock != NULL)
            ENGINE.delta = sfTime_asMicroseconds(sfClock_restart(ENGINE.delta_clock));
        if (ENGINE.seconds_clock != NULL) {
            float current_time = sfTime_asSeconds(sfClock_restart(ENGINE.seconds_clock));
            double fps = (float)(1.0) / (current_time - ENGINE.seconds_time);
            my_putdouble(fps, 2);
            my_putstr("\n");
        }
        float speed = (float)(10) * ((float)ENGINE.delta / SECONDS_TO_MILLISECONDS);
        sfRenderWindow_clear(ENGINE.default_window->render_window, sfBlack);
        engine_scene_call(scene_level_editor, SCENE_CALL_TICK);
        sfRenderWindow_display(ENGINE.default_window->render_window);
    }
    if (ENGINE.delta_clock != NULL)
        sfClock_destroy(ENGINE.delta_clock);
    if (ENGINE.seconds_clock != NULL)
        sfClock_destroy(ENGINE.seconds_clock);
    engine_window_destroy_all();
    engine_scene_free(scene_level_editor);
    return RETURNED_EXIT;
}
