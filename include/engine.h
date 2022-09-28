/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include "engine/window.h"

// Contains a WINDOW_LAYER_TOTAL amount of sfRenderWindows (1)
typedef struct engine_s {
    window_layers_t window;
} engine_t;

extern engine_t ENGINE;
