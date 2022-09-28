/*
** EPITECH PROJECT, 2021
** my_str_to_array.c
** File description:
** Main function
*/

#include <stddef.h>
#include <stdlib.h>

static int char_in_str(char const character, char const *sep)
{
    for (int i = 0; sep[i] != '\0'; i++) {
        if (character == sep[i])
            return 1;
    }
    return 0;
}

static int args_count(char const *arg, char const *sep)
{
    int count = 0;

    for (int i = 0; arg[i] != '\0'; i++) {
        while (char_in_str(arg[i], sep))
            i++;
        if (arg[i] != '\0')
            count++;
        while (!char_in_str(arg[i], sep) && arg[i] != '\0')
            i++;
        if (arg[i] == '\0')
            return count;
    }
    return count;
}

static int args_get_position(char const *arg, char const *sep, int index)
{
    int i = 0;
    int count = -1;

    for (i = 0; count < index; i++) {
        while (char_in_str(arg[i], sep))
            i++;
        if (arg[i] != '\0')
            count++;
        if (arg[i] == '\0' || count >= index)
            return i;
        while (!char_in_str(arg[i], sep) && arg[i] != '\0')
            i++;
    }
    return i;
}

static char *args_wrap(char const *arg, char const *sep, int index)
{
    int length = 0;
    int position = args_get_position(arg, sep, index);
    char *wrapped_arg = NULL;

    if (arg == NULL || sep == NULL)
        return 0;
    for (int i = position; !char_in_str(arg[i], sep) && arg[i] != '\0'; i++)
        length++;
    wrapped_arg = malloc(sizeof(char) * (length + 1));
    for (int i = position; !char_in_str(arg[i], sep) && arg[i] != '\0'; i++)
        wrapped_arg[i - position] = arg[i];
    wrapped_arg[length] = '\0';
    return wrapped_arg;
}

char **my_str_to_array(char const *arg, char const *sep)
{
    int count = args_count(arg, sep);
    char **array = NULL;

    if (arg == NULL || sep == NULL)
        return NULL;
    if (count < 1)
        return NULL;
    array = malloc(sizeof(char *) * (count + 1));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < count; i++)
        array[i] = args_wrap(arg, sep, i);
    array[count] = NULL;
    return array;
}
