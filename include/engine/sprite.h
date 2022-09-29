/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/sprite.h
** File description:
** Used to generate both sprites and textures
*/

#pragma once
    #include "engine/sprite/types.h"

// Returns the generated sprite
// Returns NULL if a problem is encountered
sprite_t *engine_sprite_create_from_file(char const *filepath);
void engine_sprite_destroy(sprite_t *sprite);
