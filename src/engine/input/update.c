/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/input/update.c
** File description:
** Updates every input
*/

#include "engine/input.h"
#include "engine/struct.h"
#include <stdbool.h>

static bool is_pressed(input_id_t const id)
{
    if (sfKeyboard_isKeyPressed(ENGINE.input_state.controls.inputs[id].keyboard.key)) {
        for (keys_additional_id_t j = 0; j < KEY_ADDITIONAL_TOTAL; j++) {
            if (ENGINE.input_state.controls.inputs[id].keyboard.keys_additional[j] == true &&
                !sfKeyboard_isKeyPressed(KEYS_ADDITIONAL[j][0]) && !sfKeyboard_isKeyPressed(KEYS_ADDITIONAL[j][1]))
                return false;
        }
        return true;
    }
    if (!sfJoystick_isConnected(ENGINE.input_state.joystick))
        return false;
    if (sfJoystick_isButtonPressed(ENGINE.input_state.joystick, ENGINE.input_state.controls.inputs[id].joystick.button))
        return true;
    return false;
}

void engine_input_update(void)
{
    for (input_id_t i = 0; i < INPUT_TOTAL; i++) {
        if (is_pressed(i))
            ENGINE.input_state.pressing[i] += 1;
        else
            ENGINE.input_state.pressing[i] = 0;
        for (keys_additional_id_t j = 0; j < KEY_ADDITIONAL_TOTAL; j++)
            ENGINE.input_state.controls.inputs[i].keyboard.keys_additional[j] = false;
    }
    if (sfJoystick_isConnected(ENGINE.input_state.joystick))
        return;
    for (unsigned int i = 0; i < sfJoystickCount; i++) {
        if (sfJoystick_isConnected(i)) {
            ENGINE.input_state.joystick = i;
            return;
        }
    }
}
