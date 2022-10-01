/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/loaded_map/view_angle/rotate.c
** File description:
** Rotate the angle of the map
*/

#include "engine/loaded_map.h"
#include <stdbool.h>
#include <stdlib.h>

short engine_loaded_map_view_angle_rotate(loaded_map_t *loaded_map, bool const reverse_clockwise)
{
    short view_angle_id = 0;

    if (loaded_map == NULL)
        return -1;
    view_angle_id = loaded_map->view_angle_id;
    if (reverse_clockwise)
        view_angle_id -= 1;
    else
        view_angle_id += 1;
    if (view_angle_id < 0)
        view_angle_id = VIEW_ANGLE_TOTAL - 1;
    if (view_angle_id >= VIEW_ANGLE_TOTAL)
        view_angle_id = VIEW_ANGLE_DEFAULT;
    loaded_map->view_angle = VIEW_ANGLE_PARAMS[view_angle_id];
    loaded_map->view_angle_id = view_angle_id;
    return view_angle_id;
}
