/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

sfIntRect rect_create(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfVector2f vec_create(float x, float y)
{
    sfVector2f vect;

    vect.x = x;
    vect.y = y;
    return (vect);
}

char *my_strcat(char *str1, char *str2)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str1) +
                                        my_strlen(str2) + 1);
    int i = 0;
    int j = 0;

    if (new_str == NULL)
        return NULL;
    for (; str1[i] != '\0'; i++)
        new_str[i] = str1[i];
    for (; str2[j] != '\0'; j++)
        new_str[j + i] = str2[j];
    new_str[j + i] = '\0';
    return (new_str);
}

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return (len);
}

int my_strcomp(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
        return (0);
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}