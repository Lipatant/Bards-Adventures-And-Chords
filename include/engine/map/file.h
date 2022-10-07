/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/files.h
** File description:
** Includes everything used for the engine
*/

#pragma once
    #include "engine/map/types.h"
    #include <stdbool.h>

// Returns the generated map.
// Otherwise, returns NULL.
/// \param path Path to the desire file.
map_t *engine_map_file_load(char const *path);
// Returns false if a problem is encountered.
// Otherwise, returns true.
/// \param map Pointer to the selected map.
/// \param path Path to the desire file.
bool engine_map_file_write(map_t *map, char const *path);
