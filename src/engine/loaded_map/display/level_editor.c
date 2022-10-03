/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/loaded_map/display.c
** File description:
** Modified version of engine_loaded_map_display
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
    sfFloatRect viewport = {
        window->view_center.x + window->view_size.x * -0.5,
        window->view_center.y + window->view_size.y * -0.5,
        window->view_size.x, window->view_size.y};

    return sfFloatRect_intersects(&sprite_rect, &viewport, NULL);
}

static void display_tile(sprite_t *sprite, window_layers_t *window, sfVector2f position, short const tile)
{
    sfIntRect texture_rect = {
        (tile % (sprite->texture_size.x / TILE_TEXTURES_SIZE.x)) * TILE_TEXTURES_SIZE.x,
        (tile / (sprite->texture_size.x / TILE_TEXTURES_SIZE.x)) * TILE_TEXTURES_SIZE.y,
        TILE_TEXTURES_SIZE.x, TILE_TEXTURES_SIZE.y};

    if (tile == TILE_DEFAULT)
        return;
    position.x -= TILE_FLAT_X / 2 + TILE_TEXTURES_OFFSET_BEFORE.x;
    position.y -= TILE_TEXTURES_OFFSET_BEFORE.y;
    sfSprite_setPosition(sprite->sprite, position);
    sfSprite_setTextureRect(sprite->sprite, texture_rect);
    if (!is_out_of_screen(sprite, window))
        return;
    sfRenderWindow_drawSprite(window->render_window, sprite->sprite, NULL);
}

static void display_loaded_map(loaded_map_t *loaded_map, window_layers_t *window, position_tile_t selector)
{
    sprite_t *sprite = loaded_map->sprite;
    tilemap_t *tilemap = &loaded_map->map->tilemap;
    sfVector2f position = {0, 0};
    sfVector2f stored_position = {0, 0};
    sfIntRect texture_rect = {0, 0, TILE_TEXTURES_SIZE.x, TILE_TEXTURES_SIZE.y};

    for (int x = loaded_map->view_angle.x.start; x != loaded_map->view_angle.x.end; x += loaded_map->view_angle.x.end_of_loop) {
        for (int y = loaded_map->view_angle.y.start; y != loaded_map->view_angle.y.end; y += loaded_map->view_angle.y.end_of_loop) {
            position.x = TILE_FLAT_X * 0.5 * (x * loaded_map->view_angle.coef_x - y * loaded_map->view_angle.coef_y);
            position.y = TILE_FLAT_Y * 0.5 * (x * loaded_map->view_angle.coef_x + y * loaded_map->view_angle.coef_y);
            for (int z = 0; z != TILEMAP_MAX_Z; z++) {
                display_tile(sprite, window, position, tilemap->tile[x][y][z]);
                if (x == selector.x && y == selector.y && z == selector.z)
                    display_tile(sprite, window, position, TILE_EDITOR);
                position.y -= TILE_HEIGHT;
            }
        }
    }
}

static sfVector2f get_position_on_screen(loaded_map_t *loaded_map, position_tile_t selector)
{
    position_t position = {
        selector.x + 0.5,
        selector.y + 0.5,
        selector.z + 0.5,
    };
    sfVector2f actual_position = {0, 0};

    actual_position.x = TILE_FLAT_X * 0.5 *
        (position.x * loaded_map->view_angle.coef_x - position.y * loaded_map->view_angle.coef_y);
    actual_position.y = TILE_FLAT_Y * 0.5 *
        (position.x * loaded_map->view_angle.coef_x + position.y * loaded_map->view_angle.coef_y);
    actual_position.y -= TILE_HEIGHT * (position.z + 1);
    return actual_position;
}

void engine_loaded_map_display_level_editor(scene_t *scene)
{
    loaded_map_t *loaded_map = NULL;
    int window_layer = 0;

    if (scene == NULL || scene->type != SCENE_TYPE_LEVEL_EDITOR)
        return;
    loaded_map = scene->data.level_editor.loaded_map;
    window_layer = scene->data.level_editor.window_layer;
    if (loaded_map == NULL || !engine_window_layer_is_valid(window_layer))
        return;
    if (loaded_map->map == NULL || loaded_map->sprite == NULL)
        return;
    if (loaded_map->sprite->sprite == NULL || loaded_map->sprite->texture == NULL)
        return;
    if (&ENGINE.windows[window_layer].render_window == NULL)
        return;
    engine_window_view_set_center_vector(window_layer, get_position_on_screen(loaded_map, scene->data.level_editor.selector));
    engine_window_update_view(window_layer);
    display_loaded_map(loaded_map, &ENGINE.windows[window_layer], scene->data.level_editor.selector);
}
