/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #define SECONDS_TO_MILLISECONDS 1000000

    #include "engine/input/types.h"
    #include "engine/window.h"
    #include <SFML/System/Clock.h>

// Contains a WINDOW_LAYER_TOTAL amount of sfRenderWindows (1)
typedef struct engine_s {
    sfInt64 delta;
    sfClock *delta_clock;
    sfClock *seconds_clock;
    float seconds_time;
    window_layers_t *default_window;
    window_layers_t windows[WINDOW_LAYER_TOTAL];
    input_state_t input_state;
} engine_t;

extern engine_t ENGINE;
