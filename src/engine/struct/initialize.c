/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/struct/initialize.c
** File description:
** Initialize every value of ENGINE
*/

#include "engine/input.h"
#include "engine/struct/global.h"

void engine_struct_initialize(void)
{
    ENGINE.delta = 0;
    ENGINE.delta_clock = sfClock_create();
    ENGINE.seconds_clock = sfClock_create();
    ENGINE.seconds_time = 0;
    ENGINE.default_window = NULL;
    for (unsigned int i = 0; i < WINDOW_LAYER_TOTAL; i++) {
        ENGINE.windows[i].render_window = NULL;
        ENGINE.windows[i].view = NULL;
    }
    ENGINE.default_scene = NULL;
    engine_input_initialize();
}
