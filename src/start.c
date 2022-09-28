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

engine_t ENGINE;

static int poll_single_event(sfRenderWindow *window, sfEvent *event)
{
    if (event == NULL)
        return 0;
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    return 1;
}

int engine_window_poll_events(int const window_layer)
{
    sfEvent event;
    sfRenderWindow *window = ENGINE.window.render_window[WINDOW_LAYER_MAIN_GAME];
    int returned = 0;

    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    while (sfRenderWindow_pollEvent(window, &event))
        returned += poll_single_event(window, &event);
    return returned;
}

int start(int const ac, char * const *av, char * const *env)
{
    engine_window_create(WINDOW_LAYER_MAIN_GAME);
    if (ENGINE.window.render_window[WINDOW_LAYER_MAIN_GAME] == NULL)
        return RETURNED_EXIT;
    while (sfRenderWindow_isOpen(ENGINE.window.render_window[WINDOW_LAYER_MAIN_GAME])) {
        engine_window_poll_events(WINDOW_LAYER_MAIN_GAME);
        sfRenderWindow_clear(ENGINE.window.render_window[WINDOW_LAYER_MAIN_GAME], sfBlack);
        sfRenderWindow_display(ENGINE.window.render_window[WINDOW_LAYER_MAIN_GAME]);
    }
    engine_window_destroy_all();
    return RETURNED_EXIT;
}
