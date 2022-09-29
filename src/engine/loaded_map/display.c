/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/loaded_map/display.c
** File description:
** Displays a loaded map on the selected window
*/

#include "engine.h"
#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool is_out_of_screen(sprite_t *sprite, window_layers_t *window)
{
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite->sprite);
    sfFloatRect viewport = sfView_getViewport(window->view);

    viewport.width *= window->view_size.x;
    viewport.height *= window->view_size.y;
//    return sfFloatRect_intersects(&sprite_rect, &viewport, NULL);
    return sfFloatRect_contains(&viewport, sprite_rect.left + sprite_rect.width / 2, sprite_rect.top + sprite_rect.height / 2);
}

static void display_tile(sprite_t *sprite, window_layers_t *window, sfVector2f position, short const tile)
{
    sfIntRect texture_rect = {
        (tile % (sprite->texture_size.x / TILE_TEXTURES_SIZE.x)) * TILE_TEXTURES_SIZE.x,
        (tile / (sprite->texture_size.x / TILE_TEXTURES_SIZE.x)) * TILE_TEXTURES_SIZE.y,
        TILE_TEXTURES_SIZE.x, TILE_TEXTURES_SIZE.y};

    if (tile == TILE_DEFAULT)
        return;
    sfSprite_setPosition(sprite->sprite, position);
    sfSprite_setTextureRect(sprite->sprite, texture_rect);
    if (!is_out_of_screen(sprite, window))
        return;
    sfRenderWindow_drawSprite(window->render_window, sprite->sprite, NULL);
}

static sfVector2f get_on_screen_position(position_t position)
{
    sfVector2f actual_position = {0, 0};

    actual_position.x = TILE_FLAT_X * -0.5 * (position.x - position.y);
    actual_position.y = TILE_FLAT_Y * -0.5 * (position.x + position.y);
    return actual_position;
}

static void display_loaded_map(loaded_map_t *loaded_map, window_layers_t *window, position_t center, short const view_angle) {
    sprite_t *sprite = loaded_map->sprite;
    tilemap_t *tilemap = &loaded_map->map->tilemap;
    sfVector2f actual_position = get_on_screen_position(center);
    sfVector2f scale = {1, 1};
    sfVector2f position = {0, 0};
    sfVector2f stored_position = {0, 0};
    sfIntRect texture_rect = {0, 0, TILE_TEXTURES_SIZE.x, TILE_TEXTURES_SIZE.y};

    sfSprite_setScale(sprite->sprite, scale);
    for (int x = 0; x < TILEMAP_MAX_X; x++) {
        for (int y = 0; y < TILEMAP_MAX_Y; y++) {
            position.x = window->view_size.x / 2 + actual_position.x * scale.x + TILE_FLAT_X * 0.5 * (x - y) * scale.x;
            position.y = window->view_size.y / 2 + actual_position.y * scale.y + TILE_FLAT_Y * 0.5 * (x + y) * scale.y + center.z * TILE_HEIGHT * scale.y;
            for (int z = 0; z < TILEMAP_MAX_Z; z++) {
                display_tile(sprite, window, position, tilemap->tile[x][y][z]);
                position.y -= TILE_HEIGHT * scale.y;
            }
        }
    }
}

void engine_loaded_map_display(loaded_map_t *loaded_map, int const window_layer, position_t center, short const view_angle)
{
    if (loaded_map == NULL || !engine_window_layer_is_valid(window_layer))
        return;
    if (loaded_map->map == NULL || loaded_map->sprite == NULL)
        return;
    if (loaded_map->sprite->sprite == NULL || loaded_map->sprite->texture == NULL)
        return;
    if (&ENGINE.windows[window_layer].render_window == NULL)
        return;
    engine_window_update_view(window_layer);
    display_loaded_map(loaded_map, &ENGINE.windows[window_layer], center, view_angle);
}
