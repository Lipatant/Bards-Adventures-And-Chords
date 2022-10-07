/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene/level_editor.h
** File description:
** Contains what's used for scenes
*/

#pragma once
    #include "engine/scene/types.h"
    #include <stdbool.h>

/// \param scene Pointer to the selected scene
void engine_scene_level_editor_create(scene_t *scene);
/// \param scene Pointer to the selected scene
void engine_scene_level_editor_free(scene_t *scene);
/// \param scene Pointer to the selected scene
void engine_scene_level_editor_tick(scene_t *scene);
/// \param scene Pointer to the selected scene
/// \param tile Tile id to fill with
void engine_scene_level_editor_tools_fill_rectangle(scene_t *scene, unsigned short const tile);
/// \param scene Pointer to the selected scene
/// \param tile Tile id to fill with
void engine_scene_level_editor_tools_fill_replace(scene_t *scene, unsigned short const tile);
// Returns false if a problem is encountered.
// Otherwise returns true.
/// \param scene Pointer to the selected scene
/// \param tile Path to the selected file
bool engine_scene_level_editor_tools_load_file(scene_t *scene, char const *path);
// Returns the new scene position.
/// \param scene Pointer to the selected scene
tile_t engine_scene_level_editor_tools_next_block(scene_t *scene);
// Returns the new scene position.
/// \param scene Pointer to the selected scene
tile_t engine_scene_level_editor_tools_previous_block(scene_t *scene);
