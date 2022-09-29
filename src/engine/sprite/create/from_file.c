/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/sprite/create/from_file.c
** File description:
** Creates a sprite from a file
*/

#include "engine/sprite.h"
#include <stdlib.h>

void set_texture_size(sfVector2u *sprite_texture_size, sfVector2u texture_size)
{
    sprite_texture_size->x = texture_size.x;
    sprite_texture_size->y = texture_size.y;
}

sprite_t *destroy_sprite(sprite_t *sprite)
{
    if (sprite->sprite != NULL)
        sfSprite_destroy(sprite->sprite);
    if (sprite->texture != NULL)
        sfTexture_destroy(sprite->texture);
    free(sprite);
    return NULL;
}

sprite_t *engine_sprite_create_from_file(char const *filepath)
{
    sprite_t *sprite = NULL;

    if (filepath == NULL)
        return NULL;
    sprite = malloc(sizeof(sprite_t));
    if (sprite == NULL)
        return NULL;
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    if (sprite->sprite == NULL || sprite->texture == NULL)
        return destroy_sprite(sprite);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    set_texture_size(&sprite->texture_size, sfTexture_getSize(sprite->texture));
    return sprite;
}
