/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/input/initialize.c
** File description:
** Initalise every input
*/

#include "engine/input.h"
#include "engine/struct.h"
#include <stdbool.h>

static void set_default_inputs(void)
{
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_UP].joystick.button = JOYSTICK_BUTTON_L;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_DOWN].joystick.button = JOYSTICK_BUTTON_ZL;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_PLACE].joystick.button = JOYSTICK_BUTTON_ZR;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_ERASE].joystick.button = JOYSTICK_BUTTON_R;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_PLACE_MARKER].joystick.button = JOYSTICK_BUTTON_START;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_NEXT_CUBE].joystick.button = JOYSTICK_BUTTON_A;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_PREVIOUS_CUBE].joystick.button = JOYSTICK_BUTTON_B;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_FILL_RECTANGLE].joystick.button = JOYSTICK_BUTTON_Y;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_FILL_REPLACE].joystick.button = JOYSTICK_BUTTON_X;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_XRAYS].joystick.button = JOYSTICK_BUTTON_RCLICK;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_SAVE].joystick.button = JOYSTICK_BUTTON_SCREENSHOT;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_LOAD].joystick.button = JOYSTICK_BUTTON_SELECT;

    ENGINE.input_state.controls.inputs[INPUT_UP].keyboard.key = sfKeyZ;
    ENGINE.input_state.controls.inputs[INPUT_DOWN].keyboard.key = sfKeyS;
    ENGINE.input_state.controls.inputs[INPUT_LEFT].keyboard.key = sfKeyQ;
    ENGINE.input_state.controls.inputs[INPUT_RIGHT].keyboard.key = sfKeyD;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_UP].keyboard.key = sfKeyE;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_DOWN].keyboard.key = sfKeyA;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_PLACE].keyboard.key = sfKeySpace;
    ENGINE.input_state.controls.inputs[INPUT_EDITOR_ERASE].keyboard.key = sfKeyX;
}

void engine_input_initialize(void)
{
    for (input_id_t i = 0; i < INPUT_TOTAL; i++) {
        ENGINE.input_state.controls.inputs[i].joystick.button = JOYSTICK_BUTTON_UNKNOWN;
        ENGINE.input_state.controls.inputs[i].keyboard.key = sfKeyUnknown;
        for (keys_additional_id_t j = 0; j < KEY_ADDITIONAL_TOTAL; j++)
            ENGINE.input_state.controls.inputs[i].keyboard.keys_additional[j] = false;
        ENGINE.input_state.pressing[i] = 0;
    }
    for (unsigned int i = 0; i < sfJoystickAxisCount; i++)
        ENGINE.input_state.joystick_axis[i] = 0;
    ENGINE.input_state.joystick = 0;
    set_default_inputs();
}
