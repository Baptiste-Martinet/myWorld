/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

int my_getnbr(char *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    if (str[0] == '-') {
        neg = -1;
        i = 1;
    }
    for (; str[i] != '\0'; i++)
        nb = (nb * 10) + (str[i] - 48);
    return (nb * neg);
}

char *my_itoa2(int nb)
{
    char *buff = malloc(sizeof(char) * 30);
    int j = 0;
    int temp = 10;

    if (buff == NULL)
        return NULL;
    for (; nb / temp > 0; j++)
        temp *= 10;
    temp = j;
    buff[j + 1] = '\0';
    for (; 0 <= j; j--) {
        buff[j] =  (nb - (nb / 10 * 10) + '0');
        nb /= 10;
    }
    return buff;
}

char *my_itoa(int nb)
{
    if (nb < 0)
        return (my_strcat("-", my_itoa2(abs(nb))));
    else
        return my_itoa2(nb);
}

void map_freeing(sfVector2f **map, int size)
{
    for (int i = 0; i < size; i++)
        free(map[i]);
    free(map);
}

int **tab_cpy(int **tab, int width, int height)
{
    int **new_tab;
    new_tab = malloc(sizeof(int *) * height);

    for (int y = 0; y < height; y++) {
        new_tab[y] = malloc(sizeof(int) * width);
        for (int x = 0; x < width; x++) {
            new_tab[y][x] = tab[y][x];
        }
    }
    return (new_tab);
}
