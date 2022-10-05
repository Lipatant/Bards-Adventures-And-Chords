/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/input/is_held.c
** File description:
** Checks if a key is pressed
*/

#include "engine/input.h"
#include "engine/struct.h"
#include <stdbool.h>

bool engine_input_is_held(input_id_t const id)
{
    if (id < 0 || id >= sfJoystickButtonCount)
        return false;
    if (ENGINE.input_state.pressing[id] >= 1)
        return true;
    return false;
}
