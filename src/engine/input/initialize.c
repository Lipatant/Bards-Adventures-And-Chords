/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/input/initialize.c
** File description:
** Destroys a sprite
*/

#include "engine/input.h"
#include "engine/struct.h"
#include <stdbool.h>

void engine_input_initialize(void)
{
    for (input_id_t i = 0; i < INPUT_TOTAL; i++) {
        ENGINE.input_state.controls.inputs[i].joystick.button = 0;
        ENGINE.input_state.controls.inputs[i].keyboard.key = sfKeyUnknown;
        for (keys_additional_id_t j = 0; j < KEY_ADDITIONAL_TOTAL; j++)
            ENGINE.input_state.controls.inputs[i].keyboard.keys_additional[j] = false;
        ENGINE.input_state.joystick = -1;
        ENGINE.input_state.pressing[i] = 0;
    }
}
