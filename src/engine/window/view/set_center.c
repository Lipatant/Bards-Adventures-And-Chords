/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/view/set_center.c
** File description:
** Change the actual center of the view
*/

#include "engine.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include <stdlib.h>

static void set_view_rect(int const window_layer)
{
    if (ENGINE.windows[window_layer].view == NULL)
        return;
    ENGINE.windows[window_layer].view_rect = sfView_getViewport(ENGINE.windows[window_layer].view);
    ENGINE.windows[window_layer].view_center = sfView_getCenter(ENGINE.windows[window_layer].view);
}

static sfView *correct_view(window_layers_t *window, float const x, float const y)
{
    sfVector2f center = {x, y};

    sfView_setCenter(window->view, center);
    return window->view;
}

sfView *engine_window_view_set_center(int const window_layer, float const x, float const y)
{
    window_layers_t *window = &ENGINE.windows[window_layer];

    if (!engine_window_layer_is_valid(window_layer))
        return NULL;
    if (window->view == NULL) {
        window->view = sfView_copy(sfRenderWindow_getView(window->render_window));
        if (window->view == NULL)
            return NULL;
    }
    sfRenderWindow_setView(window->render_window, correct_view(window,x , y));
    set_view_rect(window_layer);
    return window->view;
}
