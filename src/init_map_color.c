/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

char *chars_to_str(char a, char b, char c)
{
    char *new_str = malloc(sizeof(char) * (3 + 1));

    new_str[0] = a;
    new_str[1] = b;
    new_str[2] = c;
    new_str[3] = '\0';
    return (new_str);
}

sfColor get_map_color(int indx, char *map)
{
    sfColor new_color;

    new_color.r = my_getnbr(chars_to_str(map[indx],
        map[indx + 1], map[indx + 2]));
    new_color.g = my_getnbr(chars_to_str(map[indx + 3],
        map[indx + 4], map[indx + 5]));
    new_color.b = my_getnbr(chars_to_str(map[indx + 6],
        map[indx + 7], map[indx + 8]));
    new_color.a = my_getnbr(chars_to_str(map[indx + 9],
        map[indx + 10], map[indx + 11]));
    return (new_color);
}

//initialise les couleurs depuis la map

sfColor **init_colors(int width, int height, char *map)
{
    sfColor **new_color = malloc(sizeof(sfColor *) * (height + 1));
    int indx = 3;

    for (int y = 0; y < height; y++, indx++) {
        new_color[y] = malloc(sizeof(sfColor) * (width + 1));
        for (int x = 0; x < width; x++, indx += 16) {
            if (x < width - 1 && y < height - 1)
                new_color[y][x] = get_map_color(indx, map);
            else
                new_color[y][x] = (sfColor) {47, 48, 51, 255};
        }
    }
    return (new_color);
}