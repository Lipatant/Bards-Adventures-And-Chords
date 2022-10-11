/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/button/free.c
** File description:
** Creates a new button
*/

#include "engine/button/types.h"
#include "engine/sprite.h"
#include <stdlib.h>

void engine_button_free(button_t *button)
{
    if (button == NULL)
        return;
    if (button->font != NULL)
        sfFont_destroy(button->font);
    if (button->sprite != NULL)
        engine_sprite_destroy(button->sprite);
    if (button->string != NULL)
        free(button->string);
    free(button);
}
