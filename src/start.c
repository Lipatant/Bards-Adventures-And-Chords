/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** start.c
** File description:
** Main function
*/

#include "my.h"
#include "returned.h"

#include "engine.h"
#include "engine/window.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>

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

static sfInt64 engine_struct_update_time(void)
{
    sfInt64 value = 0;
    float current_time = 0;
    double fps = 0;

    if (ENGINE.delta_clock != NULL) {
        value = sfTime_asMicroseconds(sfClock_restart(ENGINE.delta_clock));
        ENGINE.delta = value;
    }
    if (ENGINE.seconds_clock != NULL) {
        current_time = sfTime_asSeconds(sfClock_restart(ENGINE.seconds_clock));
        fps = (float)(1.0) / (current_time - ENGINE.seconds_time);
    }
    return value;
}

int start(int const ac, char * const *av, char * const *env)
{
    engine_struct_initialize();
    engine_window_create(WINDOW_LAYER_DEFAULT_WINDOW);
    ENGINE.default_window = &ENGINE.windows[WINDOW_LAYER_DEFAULT_WINDOW];
    if (ENGINE.windows[WINDOW_LAYER_MAIN_GAME].render_window == NULL) {
        engine_struct_free();
        return RETURNED_ERROR;
    }
    ENGINE.default_scene = engine_scene_create(SCENE_TYPE_MAIN_MENU);
    while (sfRenderWindow_isOpen(ENGINE.default_window->render_window)) {
        engine_window_poll_events(WINDOW_LAYER_DEFAULT_WINDOW);
        engine_struct_update_time();
        engine_input_update();
//        float speed = (float)(10) * ((float)ENGINE.delta / SECONDS_TO_MILLISECONDS);
        sfRenderWindow_clear(ENGINE.default_window->render_window, sfBlack);
        engine_scene_call(ENGINE.default_scene, SCENE_CALL_TICK);
        sfRenderWindow_display(ENGINE.default_window->render_window);
    }
    engine_struct_free();
    return RETURNED_EXIT;
}
