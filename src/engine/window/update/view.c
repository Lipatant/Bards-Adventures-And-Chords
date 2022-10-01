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

static sfVector2f get_window_ratio(window_layers_t *window)
{
    sfVector2f ratio = {1, 1};

    window->render_window_size = sfRenderWindow_getSize(window->render_window);
    if (window->render_window_size.x > window->render_window_size.y)
        ratio.x = (float)window->render_window_size.y / window->render_window_size.x;
    else
        ratio.y = (float)window->render_window_size.x / window->render_window_size.y;
    return ratio;
}

static sfView *correct_view(window_layers_t *window)
{
    sfFloatRect view_rect = {0, 0, 1, 1};
    sfVector2f view_size = {0, 0};
    sfVector2f ratio = get_window_ratio(window);

    view_rect.width *= ratio.x;
    view_rect.height *= ratio.y;
    view_rect.left += (1 - view_rect.width) / 2;
    view_rect.top += (1 - view_rect.height) / 2;
    view_size.x = DEFAULT_WINDOW_RESOLUTION.x;
    view_size.y = DEFAULT_WINDOW_RESOLUTION.y;
    sfView_setSize(window->view, view_size);
    sfView_setViewport(window->view, view_rect);
    return window->view;
}

static void set_view_size(int const window_layer)
{
    if (ENGINE.windows[window_layer].view == NULL)
        return;
    ENGINE.windows[window_layer].view_size = sfView_getSize(ENGINE.windows[window_layer].view);
    ENGINE.windows[window_layer].view_rect = sfView_getViewport(ENGINE.windows[window_layer].view);
}

sfView *engine_window_update_view(int const window_layer)
{
    window_layers_t *window = &ENGINE.windows[window_layer];

    if (!engine_window_layer_is_valid(window_layer))
        return NULL;
    if (window->view == NULL) {
        window->view = sfView_copy(sfRenderWindow_getView(window->render_window));
        if (window->view == NULL)
            return NULL;
    }
    if (window->view == NULL)
        return NULL;
    sfRenderWindow_setView(window->render_window, correct_view(window));
    set_view_size(window_layer);
    return window->view;
}
