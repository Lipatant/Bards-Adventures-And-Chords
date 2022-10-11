/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/main_menu.h
** File description:
** Contains what's used for scenes
*/

#pragma once
    #include "engine/scene/types.h"

/// \param scene Pointer to the selected scene
void engine_scene_main_menu_create(scene_t *scene);
/// \param scene Pointer to the selected scene
void engine_scene_main_menu_free(scene_t *scene);
/// \param scene Pointer to the selected scene
void engine_scene_main_menu_tick(scene_t *scene);
