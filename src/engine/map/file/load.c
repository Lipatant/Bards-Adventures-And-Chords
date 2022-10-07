/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/file/load.c
** File description:
** Loads a map
*/

#include "engine/map.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

map_t *engine_map_file_load(char const *path)
{
    int fd = 0;
    map_t *map = NULL;
    ssize_t written = 0;

    if (path == NULL)
        return NULL;
    map = malloc(sizeof(map_t));
    if (map == NULL)
        return NULL;
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return NULL;
    written = read(fd, map, sizeof(map_t));
    close(fd);
    if (written < 0) {
        free(map);
        return NULL;
    }
    return map;
}
