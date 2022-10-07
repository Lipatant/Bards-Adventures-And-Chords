/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** engine/map/file/write.c
** File description:
** Writes a map in a file
*/

#include "engine/map.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

bool engine_map_file_write(map_t *map, char const *path)
{
    int fd = 0;
    ssize_t written = 0;

    if (map == NULL || path == NULL)
        return false;
    fd = open(path, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd < 0 || EEXIST == errno) {
        fd = open(path, O_WRONLY);
        if (fd < 0)
            return false;
    }
    written = write(fd, &map->tilemap, sizeof(map_t));
    close(fd);
    if (written < 0)
        return false;
    return true;
}
