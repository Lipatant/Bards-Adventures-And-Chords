/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/window.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include <SFML/Graphics/Types.h>
    #include <SFML/Window/Window.h>
    #include <SFML/Graphics/Color.h>

    #define DEFAULT_WINDOW_COLOR sfBlack
    #define DEFAULT_WINDOW_FPS 60
    #define DEFAULT_WINDOW_SCREEN_X 1920
    #define DEFAULT_WINDOW_SCREEN_Y 1080
    #define DEFAULT_WINDOW_PARAMS sfClose | sfResize

enum window_layers_indices {
    WINDOW_LAYER_MAIN_GAME,
    WINDOW_LAYER_TOTAL,
    WINDOW_LAYER_NONE = -1,
};

// Contains a WINDOW_LAYER_TOTAL amount of sfRenderWindows (1)
typedef struct window_layers_s {
    sfRenderWindow *render_window[WINDOW_LAYER_TOTAL];
} window_layers_t;

static const char DEFAULT_WINDOW_NAME[] = "Bards";

// Returns the generated RenderWindow
// Returns NULL if a problem is encountered
// You can use WINDOW_LAYER_NONE to NOT store it directly
sfRenderWindow *engine_window_create(int const window_layer);
void engine_window_destroy(int const window_layer);
void engine_window_destroy_all(void);