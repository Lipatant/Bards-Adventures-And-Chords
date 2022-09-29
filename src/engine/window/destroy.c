/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/destroy.c
** File description:
** Removes a window from the engine
*/

#include "engine.h"
#include <SFML/Graphics/RenderWindow.h>

void engine_window_destroy(int const window_layer)
{
    if (window_layer == WINDOW_LAYER_NONE || window_layer < 0 || window_layer >= WINDOW_LAYER_TOTAL)
        return;
    if (ENGINE.windows[window_layer].render_window == NULL)
        return;
    sfRenderWindow_destroy(ENGINE.windows[window_layer].render_window);
    ENGINE.windows[window_layer].render_window = NULL;
}
