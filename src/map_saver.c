/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void value_writer(int value, int fd, int size)
{
    char *str_value = my_itoa(value);
    int len = my_strlen(str_value);

    if (str_value == NULL)
        return;
    for (int i = 0; i > len - size; i--)
        write(fd, "0", 1);
    write(fd, str_value, len);
    free(str_value);
}

void color_writer(info_map_t *inf_map, int fd, int x, int y)
{
    write(fd, ":", 1);
    value_writer(inf_map->saved_colors[y][x].r, fd, 3);
    value_writer(inf_map->saved_colors[y][x].g, fd, 3);
    value_writer(inf_map->saved_colors[y][x].b, fd, 3);
    value_writer(inf_map->saved_colors[y][x].a, fd, 3);
    write(fd, ":", 1);
}

void save_map(info_map_t *inf_map)
{
    int fd = open(my_strcat(inf_map->filepath, "_save.legend"),
        O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0)
        return;
    for (int y = 0; y < inf_map->height; y++) {
        for (int x = 0; x < inf_map->width; x++) {
            value_writer(inf_map->map[y][x], fd, 2);
            color_writer(inf_map, fd, x, y);
        }
        write(fd, "\n", 1);
    }
    close(fd);
    write(0, "Project saved\n", 14);
}