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

struct range_of_tiles_s {
    position_tile_t start;
    position_tile_t end;
};

static bool is_out_of_screen(sprite_t *sprite, window_layers_t *window)
{
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite->sprite);
    sfFloatRect viewport = sfView_getViewport(window->view);

    viewport.width *= window->view_size.x;
    viewport.height *= window->view_size.y;
    return !sfFloatRect_intersects(&sprite_rect, &viewport, NULL);
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
//    if (is_out_of_screen(sprite, window))
//        return;
    sfRenderWindow_drawSprite(window->render_window, sprite->sprite, NULL);
}

static position_t get_on_screen_position(position_t position)
{
    position_t actual_position = {0, 0, 0};
}

static void get_ranges_of_tiles(struct range_of_tiles_s *range, window_layers_t *window, position_t center)
{
    position_tile_t actual_tile = {(int)center.x, (int)center.y, (int)center.z};
    position_tile_t tiles_seen = {0, 0, 0};

    tiles_seen.x = window->view_size.x / TILE_TEXTURES_SIZE.x / 4;
    tiles_seen.y = window->view_size.y / TILE_TEXTURES_SIZE.y / 4;

    range->start.x = actual_tile.x - tiles_seen.x / 2;
    range->end.x = actual_tile.x + tiles_seen.x / 2;
    range->start.y = actual_tile.y - tiles_seen.y / 2;
    range->end.y = actual_tile.y + tiles_seen.y / 2;
}

static void display_loaded_map(loaded_map_t *loaded_map, window_layers_t *window, position_t center, short const view_angle) {
    sprite_t *sprite = loaded_map->sprite;
    tilemap_t *tilemap = &loaded_map->map->tilemap;
    sfVector2f scale = {5, 5};
    sfVector2f position = {0, 0};
    sfIntRect texture_rect = {0, 0, TILE_TEXTURES_SIZE.x, TILE_TEXTURES_SIZE.y};
    sfVector2f stored_position = {position.x, position.y};
    struct range_of_tiles_s range = {{0, 0, 0}, {TILEMAP_MAX_X, TILEMAP_MAX_Y, TILEMAP_MAX_Z}};

    sfSprite_setScale(sprite->sprite, scale);
    get_ranges_of_tiles(&range, window, center);
    for (int x = MIN(range.start.x, 0); x < MAX(range.end.x, TILEMAP_MAX_X); x++) {
        position.y = 4 * x * scale.y;
        for (int y = MIN(range.start.y, 0); y < MAX(range.end.y, TILEMAP_MAX_Y); y++) {
            position.x = stored_position.x + (texture_rect.width - TILE_TEXTURES_OFFSET.x) * scale.x * -0.5 * (x % 2);
            position.x += (texture_rect.width - TILE_TEXTURES_OFFSET.x) * scale.x * y;
            stored_position.y = position.y;
            for (int z = MIN(range.start.z, 0); z < MAX(range.end.z, TILEMAP_MAX_Z); z++) {
                display_tile(sprite, window, position, tilemap->tile[x][y][z]);
                position.y -= TILE_HEIGHT * scale.y;
            }
//            position.x += (texture_rect.width - TILE_TEXTURES_OFFSET.x) * scale.x;
            position.y = stored_position.y;
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
