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

#include <stdio.h>

static sfView *correct_view(window_layers_t *window)
{
    sfFloatRect view_rect = {0, 0, 1, 1};
//    sfVector2f view_size = {window->render_window_size.x, window->render_window_size.y};
    sfVector2f view_size = {0, 0};
    sfVector2f ratio = get_window_ratio(window);
    sfVector2f center = {0, 0};

//    view_size.x = DEFAULT_WINDOW_RESOLUTION.x * view_rect.width;
//    view_size.y = DEFAULT_WINDOW_RESOLUTION.y * view_rect.height;
//    view_rect.width *= ratio.x;
//    view_rect.height *= ratio.y;
//    view_rect.left += (1 - view_rect.width) / 2;
//    view_rect.top += (1 - view_rect.height) / 2;
//    sfView_setSize(window->view, view_size);
//    sfView_setViewport(window->view, view_rect);
    view_rect.width *= ratio.x;
    view_rect.height *= ratio.y;
    view_rect.left += (1 - view_rect.width) / 2;
    view_rect.top += (1 - view_rect.height) / 2;
    view_size.x = DEFAULT_WINDOW_RESOLUTION.x;
    view_size.y = DEFAULT_WINDOW_RESOLUTION.y;
    sfView_setSize(window->view, view_size);
    sfView_setViewport(window->view, view_rect);
    sfView_setCenter(window->view, center);
    printf("Size: %.2f, %.2f\n", sfView_getSize(window->view).x, sfView_getSize(window->view).y);
    printf("Viewport: %.2f, %.2f\n", sfView_getViewport(window->view).width, sfView_getViewport(window->view).height);
    printf("Center: %.2f, %.2f\n", sfView_getCenter(window->view).x, sfView_getCenter(window->view).y);
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
    if (window->view != NULL)
        sfView_destroy(window->view);
    window->view = sfView_copy(sfRenderWindow_getView(window->render_window));
    if (window->view == NULL)
        return NULL;
//    sfView_setSize(window->view, test_view);
    sfRenderWindow_setView(window->render_window, correct_view(window));
    set_view_size(window_layer);
    return window->view;
}
