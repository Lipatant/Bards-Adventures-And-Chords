/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** utility/free/float_2d.c
** File description:
** Frees a 2d array of floats
*/

#include <stdlib.h>

void utility_free_float_2d(float **array, unsigned int const length)
{
    if (array == NULL)
        return;
    for (unsigned int x = 0; x < length; x++)
        free(array[x]);
    free(array);
}
