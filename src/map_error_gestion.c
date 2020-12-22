/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

int check_last_char(char *map)
{
    int i = 0;

    if (map == NULL)
        return (84);
    while (map[i] != '\0')
        i++;
    if (map[i - 1] != '\n')
        return (84);
    return (0);
}

int check_each_with(char *map, int width)
{
    int row_width = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        row_width++;
        if (map[i] == '\n') {
            if ((row_width -1) != width * 16)
                return (84);
            else
                row_width = 0;
        }
    }
    return (check_last_char(map));
}

int check_width(char *map, int width)
{
    if ((width * 16) % 2 != 0)
        return 84;
    return check_each_with(map, width);
}

int map_error_gestion(char *map, int width, int height)
{
    if (map == NULL || width < 2 || height < 2)
        return (84);
    if (check_width(map, width) == 84)
        return (84);
    return (0);
}