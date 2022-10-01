/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/view/set_center/vector.c
** File description:
** Change the actual center of the view using a vector
*/

#include "engine/window.h"

sfView *engine_window_view_set_center_vector(int const window_layer, sfVector2f center)
{
    return engine_window_view_set_center(window_layer, center.x, center.y);
}
