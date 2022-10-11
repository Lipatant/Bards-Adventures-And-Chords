/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/struct/free.c
** File description:
** Frees/destroys every value of ENGINE
*/

#include "engine/input.h"
#include "engine/scene.h"
#include "engine/struct/global.h"
#include "engine/window.h"

void engine_struct_free(void)
{
    if (ENGINE.delta_clock != NULL)
        sfClock_destroy(ENGINE.delta_clock);
    if (ENGINE.seconds_clock != NULL)
        sfClock_destroy(ENGINE.seconds_clock);
    engine_scene_free(ENGINE.default_scene);
    engine_window_destroy_all();
}
