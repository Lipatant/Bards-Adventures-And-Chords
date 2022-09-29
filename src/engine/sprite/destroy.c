/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/sprite/destroy.c
** File description:
** Destroys a sprite
*/

#include "engine/sprite.h"

void engine_sprite_destroy(sprite_t *sprite)
{
    if (sprite == NULL)
        return NULL;
    if (sprite->sprite != NULL)
        sfSprite_destroy(sprite->sprite);
    if (sprite->texture != NULL)
        sfTexture_destroy(sprite->sprite);
    free(sprite);
}
