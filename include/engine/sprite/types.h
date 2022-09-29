/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/sprite/types.h
** File description:
** Only types used by engine/sprite.h
*/

#pragma once
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2u texture_size;
} sprite_t;
