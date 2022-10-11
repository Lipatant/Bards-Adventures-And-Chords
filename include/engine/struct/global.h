/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/struct/global.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include "engine/input/types.h"
    #include "engine/scene/types.h"
    #include "engine/window.h"
    #include <SFML/System/Clock.h>

/// \param delta ( sfInt64 )
/// \param delta_clock ( *sfClock )
/// \param seconds_clock ( *sfClock )
/// \param seconds_time ( float )
/// \param default_windows ( *window_layers_t )
/// \param windows ( window_layers_t [WINDOW_LAYER_TOTAL] )
/// \param input_state ( input_state_t )
typedef struct engine_s {
    sfInt64 delta;
    sfClock *delta_clock;
    sfClock *seconds_clock;
    float seconds_time;
    window_layers_t *default_window;
    window_layers_t windows[WINDOW_LAYER_TOTAL];
    input_state_t input_state;
    scene_t *default_scene;
} engine_t;

extern engine_t ENGINE;
