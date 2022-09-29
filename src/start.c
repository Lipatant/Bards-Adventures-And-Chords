/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** main.c
** File description:
** Main function
*/

#include "my.h"
#include "returned.h"

#include "engine.h"
#include "engine/window.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

engine_t ENGINE;

static int poll_single_event(window_layers_t *window, sfEvent *event)
{
    if (event == NULL)
        return 0;
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window->render_window);
    if (event->type == sfEvtGainedFocus)
        window->has_focus = true;
    if (event->type == sfEvtLostFocus)
        window->has_focus = false;
    return 1;
}

int engine_window_poll_events(int const window_layer)
{
    sfEvent event;
    window_layers_t *window = &(ENGINE.windows[WINDOW_LAYER_MAIN_GAME]);
    int returned = 0;

    if (sfKeyboard_isKeyPressed(sfKeyEscape) && window->has_focus)
        sfRenderWindow_close(window->render_window);
    while (sfRenderWindow_pollEvent(window->render_window, &event))
        returned += poll_single_event(window, &event);
    return returned;
}

static void draw_terrain(window_layers_t *window, sfSprite *sprite, sfTexture *texture, map_t *map, sfVector2f original_position)
{
    sfVector2f scale = {1, 1};
    sfVector2f position = original_position;
    sfIntRect texture_rect = {0, 0, TILE_TEXTURES_SIZE.x, TILE_TEXTURES_SIZE.y};
    sfVector2u texture_size = {0, 0};
    float vertical_position = 0;
    int additional_random = 1;

    if (window->render_window == NULL || sprite == NULL || texture == NULL || map == NULL)
        return;
    texture_size = sfTexture_getSize(texture);
    sfSprite_setScale(sprite, scale);
    for (int x = 0; x < TILEMAP_MAX_X; x++) {
        position.x = original_position.x + (texture_rect.width - TILE_TEXTURES_OFFSET.x) * scale.x * -0.5 * (x % 2);
        for (int y = 0 - (y % 2); y < TILEMAP_MAX_Y; y++) {
            vertical_position = position.y;
            for (int z = 0; z < TILEMAP_MAX_Z; z++) {
                texture_rect.left = (map->tilemap.tile[x][y][z] % (texture_size.x / TILE_TEXTURES_SIZE.x)) * TILE_TEXTURES_SIZE.x;
                texture_rect.top = (map->tilemap.tile[x][y][z] / (texture_size.x / TILE_TEXTURES_SIZE.x)) * TILE_TEXTURES_SIZE.y;
                if (map->tilemap.tile[x][y][z] != TILE_DEFAULT) {
                    sfSprite_setPosition(sprite, position);
                    sfSprite_setTextureRect(sprite, texture_rect);
                    sfRenderWindow_drawSprite(window->render_window, sprite, NULL);
                }
                position.y -= TILE_HEIGHT * scale.y;
            }
            position.x += (texture_rect.width - TILE_TEXTURES_OFFSET.x) * scale.x;
            position.y = vertical_position;
        }
        position.y += 4 * scale.y;
    }
}

int start(int const ac, char * const *av, char * const *env)
{
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;
    map_t *map = NULL;
    sfVector2f position = {0, 0};

    engine_window_create(WINDOW_LAYER_DEFAULT_WINDOW);
    ENGINE.default_window = &ENGINE.windows[WINDOW_LAYER_DEFAULT_WINDOW];
    if (ENGINE.windows[WINDOW_LAYER_MAIN_GAME].render_window == NULL)
        return RETURNED_EXIT;
    texture = sfTexture_createFromFile("terrain.png", NULL);
    if (texture != NULL) {
        sprite = sfSprite_create();
        if (sprite != NULL)
            sfSprite_setTexture(sprite, texture, sfTrue);
    }
    ENGINE.delta = 0;
    ENGINE.delta_clock = sfClock_create();
    ENGINE.seconds_clock = sfClock_create();
    ENGINE.seconds_time = 0;
    map = engine_map_create();
    while (sfRenderWindow_isOpen(ENGINE.default_window->render_window)) {
        engine_window_poll_events(WINDOW_LAYER_DEFAULT_WINDOW);
        if (ENGINE.delta_clock != NULL)
            ENGINE.delta = sfTime_asMicroseconds(sfClock_restart(ENGINE.delta_clock));
        if (ENGINE.seconds_clock != NULL) {
            float current_time = sfTime_asSeconds(sfClock_restart(ENGINE.seconds_clock));
            double fps = (float)(1.0) / (current_time - ENGINE.seconds_time);
            my_putdouble(fps, 2);
            my_putstr("\n");
        }
        float speed = (float)(1000) * ((float)ENGINE.delta / SECONDS_TO_MILLISECONDS);
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            position.x += speed;
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            position.x -= speed;
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            position.y += speed;
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            position.y -= speed;
        sfRenderWindow_clear(ENGINE.default_window->render_window, sfBlack);
        draw_terrain(ENGINE.default_window, sprite, texture, map, position);
        sfRenderWindow_display(ENGINE.default_window->render_window);
    }
    if (texture != NULL)
        sfTexture_destroy(texture);
    if (sprite != NULL)
        sfSprite_destroy(sprite);
    if (ENGINE.delta_clock != NULL)
        sfClock_destroy(ENGINE.delta_clock);
    if (ENGINE.seconds_clock != NULL)
        sfClock_destroy(ENGINE.seconds_clock);
    engine_window_destroy_all();
    engine_map_free(map);
    return RETURNED_EXIT;
}
