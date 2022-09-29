/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/loaded_map/display.c
** File description:
** Displays a loaded map on the selected window
*/

#include "engine/loaded_map.h"
#include "engine/types.h"
#include "engine/window.h"
#include <stdlib.h>

#include "my.h"

void engine_loaded_map_display(loaded_map_t *loaded_map, int const window_layer, position_t center, short const view_angle)
{
    if (loaded_map == NULL || !engine_window_layer_is_valid(window_layer))
        return;
    my_putstr("AZEZAEZA\n");
}
