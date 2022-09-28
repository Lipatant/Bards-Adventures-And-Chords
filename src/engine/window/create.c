/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/create.c
** File description:
** Adds a new window to the engine
*/

#include "engine.h"
#include <SFML/Graphics/RenderWindow.h>

void store_in_window_layer(int const window_layer, sfRenderWindow *window)
{
    if (window_layer == WINDOW_LAYER_NONE || window_layer < 0 || window_layer >= WINDOW_LAYER_TOTAL)
        return;
    if (ENGINE.window.render_window[window_layer] != NULL)
        sfRenderWindow_destroy(ENGINE.window.render_window[window_layer]);
    ENGINE.window.render_window[window_layer] = window;
}

sfRenderWindow *engine_window_create(int const window_layer)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = sfVideoMode_getDesktopMode();
    sfUint32 style = DEFAULT_WINDOW_PARAMS;

    window = sfRenderWindow_create(video_mode, DEFAULT_WINDOW_NAME, style, NULL);
    if (window == NULL)
        return NULL;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_setFramerateLimit(window, DEFAULT_WINDOW_FPS);
    sfRenderWindow_clear(window, DEFAULT_WINDOW_COLOR);
    sfRenderWindow_display(window);
    store_in_window_layer(window_layer, window);
    return window;
}
