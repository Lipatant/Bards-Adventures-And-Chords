/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/button/types.h
** File description:
** Includes types and structes for buttons
*/

#pragma once
    #include "engine/sprite/types.h"
    #include <SFML/Graphics/Font.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>

/// \param string ( *char ) Text to display
/// \param font ( *sfFont )
/// \param font_pointed ( **sfFont ) Font to use if font is NULL
/// \param sprite ( *sprite_t )
/// \param sprite_pointed ( **sprite_t ) Sprite to use if sprite is NULL
typedef struct button_s {
    char *string;
    sfFont *font;
    sfFont **font_pointed;
    sprite_t *sprite;
    sprite_t **sprite_pointed;
} button_t;
