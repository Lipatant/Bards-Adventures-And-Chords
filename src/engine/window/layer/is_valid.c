/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/layer/is_valid.c
** File description:
** Checks if a window_layer is valid
*/

#include "engine/window.h"
#include <stdbool.h>

bool engine_window_layer_is_valid(int const window_layer)
{
    if (window_layer == WINDOW_LAYER_NONE)
        return false;
    if (window_layer < 0 || window_layer >= WINDOW_LAYER_TOTAL)
        return false;
    return true;
}
