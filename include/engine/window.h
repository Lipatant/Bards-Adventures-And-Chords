/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Window/Window.h>
    #include <stdbool.h>

    #define DEFAULT_WINDOW_COLOR sfBlack
    #define DEFAULT_WINDOW_FPS 120
    #define DEFAULT_WINDOW_FOCUS true
    #define DEFAULT_WINDOW_PARAMS sfClose | sfResize

enum window_layers_indices {
    WINDOW_LAYER_MAIN_GAME,
    WINDOW_LAYER_TOTAL,
    WINDOW_LAYER_NONE = -1,
};

    #define WINDOW_LAYER_DEFAULT_WINDOW WINDOW_LAYER_MAIN_GAME

// Contains a WINDOW_LAYER_TOTAL amount of sfRenderWindows (1)
typedef struct window_layers_s {
    sfRenderWindow *render_window;
    sfVector2u render_window_size;
    sfView *view;
    sfFloatRect view_rect;
    sfVector2f view_size;
    bool has_focus;
    bool had_focus;
} window_layers_t;

static const char DEFAULT_WINDOW_NAME[] = "Bards";
static const sfVector2u DEFAULT_WINDOW_RESOLUTION = {256, 224};

// Returns the generated RenderWindow
// Returns NULL if a problem is encountered
// You can use WINDOW_LAYER_NONE to NOT store it directly
sfRenderWindow *engine_window_create(int const window_layer);
void engine_window_destroy(int const window_layer);
void engine_window_destroy_all(void);
// Returns true if the layer is valid
// Otherwise, returns false
bool engine_window_layer_is_valid(int const window_layer);
// Returns the updated view
// Otherwise, returns false
sfView *engine_window_update_view(int const window_layer);
