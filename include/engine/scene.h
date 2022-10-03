/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/scene.h
** File description:
** Contains what's used for scenes
*/

#pragma once
    #include "engine/scene/level_editor.h"
    #include "engine/scene/types.h"

// Returns the generated scene.
// Returns NULL if a problem is encountered.
/// \param scene_type Type of the scene, using the scene_functions_indices enum
scene_t *engine_scene_create(scene_type_t const scene_type);
/// \param scene Pointer to the selected scene
/// \param scene_function_id Type of the function to use, using the scene_type_t enum
void engine_scene_call(scene_t *scene, scene_call_id_t const scene_function_id);
/// \param scene Pointer to the selected scene
void engine_scene_free(scene_t *scene);

static void (*SCENE_FUNCTIONS[SCENE_TYPE_TOTAL][SCENE_CALL_TOTAL])(scene_t *scene) = {
    {engine_scene_level_editor_create, engine_scene_level_editor_free, engine_scene_level_editor_tick}
};
