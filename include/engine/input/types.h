/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/input/types.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include <SFML/Window/Joystick.h>
    #include <SFML/Window/Keyboard.h>
    #include "stdbool.h"

typedef enum {
    JOYSTICK_BUTTON_UNKNOWN = -1,
    JOYSTICK_BUTTON_B,
    JOYSTICK_BUTTON_A,
    JOYSTICK_BUTTON_Y,
    JOYSTICK_BUTTON_X,
    JOYSTICK_BUTTON_L,
    JOYSTICK_BUTTON_R,
    JOYSTICK_BUTTON_ZL,
    JOYSTICK_BUTTON_ZR,
    JOYSTICK_BUTTON_SELECT,
    JOYSTICK_BUTTON_START,
    JOYSTICK_BUTTON_LCLICK,
    JOYSTICK_BUTTON_RCLICK,
    JOYSTICK_BUTTON_HOME,
    JOYSTICK_BUTTON_SCREENSHOT,
    JOYSTICK_BUTTON_TOTAL_SIZE,
} joystick_buttons_t;

typedef enum {
    INPUT_UP,
    INPUT_DOWN,
    INPUT_LEFT,
    INPUT_RIGHT,
    INPUT_WEAPON,
    INPUT_INSTRUMENT,
    INPUT_SPELL_1,
    INPUT_SPELL_2,
    INPUT_SPELL_3,
    INPUT_SPELL_4,
    INPUT_ITEM_1,
    INPUT_ITEM_2,
    INPUT_EDITOR_PLACE,
    INPUT_EDITOR_ERASE,
    INPUT_EDITOR_UP,
    INPUT_EDITOR_DOWN,
    INPUT_EDITOR_PLACE_MARKER,
    INPUT_EDITOR_FILL_RECTANGLE,
    INPUT_EDITOR_FILL_REPLACE,
    INPUT_EDITOR_XRAYS,
    INPUT_TOTAL,
} input_id_t;

typedef enum {
    KEY_ADDITIONAL_ALT,
    KEY_ADDITIONAL_CTRL,
    KEY_ADDITIONAL_SHIFT,
    KEY_ADDITIONAL_TOTAL,
} keys_additional_id_t;

static const sfKeyCode KEYS_ADDITIONAL[KEY_ADDITIONAL_TOTAL][2] = {
    {sfKeyLAlt, sfKeyRAlt}, {sfKeyLControl, sfKeyRControl}, {sfKeyLAlt, sfKeyRAlt}
};

// Input on keyboard
struct input_keyboard_s {
    sfKeyCode key;
    bool keys_additional[KEY_ADDITIONAL_TOTAL];
};

// Input on joystick
struct input_joystick_s {
    joystick_buttons_t button;
};

// Generic input
typedef struct input_s {
    struct input_keyboard_s keyboard;
    struct input_joystick_s joystick;
} input_t;

// Input configuration
typedef struct __attribute__((packed))input_controls_s {
    input_t inputs[INPUT_TOTAL];
} input_controls_t;

// Struct used in ENGINE
typedef struct input_state_s {
    unsigned int joystick;
    unsigned int pressing[INPUT_TOTAL];
    input_controls_t controls;
} input_state_t;
