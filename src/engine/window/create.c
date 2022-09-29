/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/create.c
** File description:
** Adds a new window to the engine
*/

#include "engine.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>

static void store_in_window_layer(int const window_layer, sfRenderWindow *window)
{
    if (!engine_window_layer_is_valid(window_layer))
        return;
    if (ENGINE.windows[window_layer].render_window != NULL)
        sfRenderWindow_destroy(ENGINE.windows[window_layer].render_window);
    if (ENGINE.windows[window_layer].view != NULL)
        sfView_destroy(ENGINE.windows[window_layer].view);
    ENGINE.windows[window_layer].render_window = window;
    ENGINE.windows[window_layer].has_focus = DEFAULT_WINDOW_FOCUS;
    ENGINE.windows[window_layer].had_focus = DEFAULT_WINDOW_FOCUS;
    ENGINE.windows[window_layer].view = NULL;
    ENGINE.windows[window_layer].view_size.x = 0;
    ENGINE.windows[window_layer].view_size.y = 0;
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
    sfRenderWindow_setSize(window, DEFAULT_WINDOW_RESOLUTION);
    sfRenderWindow_clear(window, DEFAULT_WINDOW_COLOR);
    sfRenderWindow_display(window);
    store_in_window_layer(window_layer, window);
    return window;
}
