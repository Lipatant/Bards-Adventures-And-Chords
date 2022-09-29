/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/update/view.c
** File description:
** Updates the view contains in a window_layer
*/

#include "engine.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include <stdlib.h>

void set_view_size(int const window_layer)
{
    if (ENGINE.windows[window_layer].view == NULL)
        return;
    ENGINE.windows[window_layer].view_size = sfView_getSize(ENGINE.windows[window_layer].view);
}

sfView *engine_window_update_view(int const window_layer)
{
    if (!engine_window_layer_is_valid(window_layer))
        return NULL;
    if (ENGINE.windows[window_layer].view != NULL)
        sfView_destroy(ENGINE.windows[window_layer].view);
    ENGINE.windows[window_layer].view = sfView_copy(sfRenderWindow_getView(ENGINE.windows[window_layer].render_window));
    set_view_size(window_layer);
    return ENGINE.windows[window_layer].view;
}
