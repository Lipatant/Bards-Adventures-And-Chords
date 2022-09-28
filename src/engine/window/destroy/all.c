/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window/destroy/all.c
** File description:
** Removes EVERY window from the engine
*/

#include "engine.h"
#include <SFML/Graphics/RenderWindow.h>

void engine_window_destroy_all(void)
{
    for (int i = 0; i < WINDOW_LAYER_TOTAL; i++)
        engine_window_destroy(i);
}
