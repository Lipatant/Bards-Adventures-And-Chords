/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/button/create.c
** File description:
** Creates a new button
*/

#include "engine/button/types.h"
#include <stdlib.h>

button_t *engine_button_create(void)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->font = NULL;
    button->font_pointed = NULL;
    button->sprite = NULL;
    button->sprite_pointed = NULL;
    button->string = NULL;
    return button;
}
