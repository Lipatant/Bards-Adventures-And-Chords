/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/input.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include "engine/input/types.h"
    #include <stdbool.h>

void engine_input_initialize(void);
// Returns true if the key is pressed
// Otherwise returns false.
/// \param id Identifier of the input, according to the input_id_t enum
bool engine_input_is_held(input_id_t const id);
// Returns true if the key has just been pressed since the last update.
// Otherwise returns false.
/// \param id Identifier of the input, according to the input_id_t enum
bool engine_input_is_pressed(input_id_t const id);
void engine_input_update(void);
