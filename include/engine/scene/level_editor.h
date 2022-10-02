/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor.h
** File description:
** Contains what's used for scenes
*/

#pragma once
    #include "engine/scene/types.h"

/// \param scene Pointer to the selected scene
void engine_scene_level_editor_create(scene_t *scene);
/// \param scene Pointer to the selected scene
void engine_scene_level_editor_tick(scene_t *scene);
/// \param scene Pointer to the selected scene
void engine_scene_level_editor_free(scene_t *scene);
