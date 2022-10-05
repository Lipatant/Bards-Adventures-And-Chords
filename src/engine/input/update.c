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
    if (ENGINE.input_state.controls.inputs[id].joystick.button == JOYSTICK_BUTTON_UNKNOWN)
        return false;
    if (sfJoystick_isButtonPressed(ENGINE.input_state.joystick, ENGINE.input_state.controls.inputs[id].joystick.button))
        return true;
    return false;
}

static void have_joystick(bool *pressing)
{
    float axis_value = 0;

    for (unsigned int i = 0; i < sfJoystickAxisCount; i++) {
        ENGINE.input_state.joystick_axis[i] = sfJoystick_getAxisPosition(ENGINE.input_state.joystick, i);
        if (i == sfJoystickX || i == sfJoystickPovX) {
            axis_value = ENGINE.input_state.joystick_axis[i];
            if (axis_value > INPUT_JOYSTICK_MIN) {
                pressing[INPUT_DOWN] = true;
                pressing[INPUT_RIGHT] = true;
            }
            if (axis_value < 0 - INPUT_JOYSTICK_MIN) {
                pressing[INPUT_LEFT] = true;
                pressing[INPUT_UP] = true;
            }
        }
        if (i == sfJoystickY || i == sfJoystickPovY) {
            axis_value = ENGINE.input_state.joystick_axis[i];
            if (axis_value > INPUT_JOYSTICK_MIN) {
                pressing[INPUT_DOWN] = true;
                pressing[INPUT_LEFT] = true;
            }
            if (axis_value < 0 - INPUT_JOYSTICK_MIN) {
                pressing[INPUT_UP] = true;
                pressing[INPUT_RIGHT] = true;
            }
        }
    }
}

static void dont_have_joystick(bool *pressing)
{
    for (unsigned int i = 0; i < sfJoystickAxisCount; i++)
        ENGINE.input_state.joystick_axis[i] = 0;
    for (unsigned int i = 0; i < sfJoystickCount; i++) {
        if (sfJoystick_isConnected(i)) {
            ENGINE.input_state.joystick = i;
            have_joystick(pressing);
            return;
        }
    }
}

void engine_input_update(void)
{
    bool pressing[INPUT_TOTAL];

    for (input_id_t i = 0; i < INPUT_TOTAL; i++)
        pressing[i] = false;
    for (input_id_t i = 0; i < INPUT_TOTAL; i++) {
        if (is_pressed(i))
            pressing[i] = true;
        for (keys_additional_id_t j = 0; j < KEY_ADDITIONAL_TOTAL; j++)
            ENGINE.input_state.controls.inputs[i].keyboard.keys_additional[j] = false;
    }
    if (sfJoystick_isConnected(ENGINE.input_state.joystick))
        have_joystick(pressing);
    else
        dont_have_joystick(pressing);
    for (input_id_t i = 0; i < INPUT_TOTAL; i++) {
        if (pressing[i])
            ENGINE.input_state.pressing[i] += 1;
        else
            ENGINE.input_state.pressing[i] = 0;
    }
}
