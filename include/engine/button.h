/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/button.h
** File description:
** Includes things used to manage buttons
*/

#pragma once
    #include "engine/button/types.h"

// Returns the generated button.
// Returns NULL if a problem is encountered.
button_t *engine_button_create(void);
/// \param button Pointer to the selected button
void engine_button_free(button_t *button);
