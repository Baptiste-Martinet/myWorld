/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

char *get_map(char *filepath)
{
    char *buff = malloc(sizeof(char) * 8192);
    int offset = 0;
    int len;
    int fd;

    if (buff == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    while ((len = read(fd, buff + offset, 8192 - offset)) > 0)
        offset = offset + len;
    close(fd);
    if (len < 0)
        return NULL;
    buff[offset] = '\0';
    return (buff);
}

int get_map_width(char *map)
{
    int width = 0;

    if (map == NULL)
        return -1;
    while (map[width] != '\n')
        width++;
    return (width / 16);
}

int get_map_height(char *map)
{
    int height = 0;

    if (map == NULL)
        return -1;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            height++;
    }
    return (height);
}

int get_map_value(char nb1, char nb2)
{
    char *value = malloc(sizeof(char) * (2 + 1));

    value[0] = nb1;
    value[1] = nb2;
    value[2] = '\0';
    return (my_getnbr(value));
}

int **map_to_tab(char *map, int width, int height)
{
    int **new_map = malloc(sizeof(int *) * height + 1);
    int indx = 0;
    int x = 0;

    for (int y = 0; y < height; y++) {
        new_map[y] = malloc(sizeof(int) * width + 1);
        for (x = 0; map[indx] != '\n' && map[indx] != '\0'; x++) {
            new_map[y][x] = get_map_value(map[indx], map[indx + 1]);
            indx += 16;
        }
        indx++;
    }
    return (new_map);
}