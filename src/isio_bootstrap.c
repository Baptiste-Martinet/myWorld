/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

sfVertexArray *create_line(sfVector2f *point1 , sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();

    sfVertex vertex1 = {. position = *point1 , .color = {0, 0, 0, 150} };
    sfVertex vertex2 = {. position = *point2 , .color = {0, 0, 0, 150} };
    sfVertexArray_append(vertex_array , vertex1);
    sfVertexArray_append(vertex_array , vertex2);
    sfVertexArray_setPrimitiveType(vertex_array , sfLinesStrip);
    return (vertex_array);
}

sfVertexArray *create_block(sfVector2f *point1, sfVector2f *point2,
        sfVector2f *point3, sfColor my_color)
{
    sfVertexArray *triangle = sfVertexArray_create();

    sfVertex vertex1 = {. position = *point1 , .color = my_color,
                        .texCoords = {0.f, 0.f}};
    sfVertex vertex2 = {. position = *point2 , .color = my_color,
                        .texCoords = {500.f, 0.f}};
    sfVertex vertex3 = {. position = *point3 , .color = my_color,
                        .texCoords = {0.f, 500.f}};
    sfVertexArray_append(triangle , vertex1);
    sfVertexArray_append(triangle , vertex2);
    sfVertexArray_append(triangle , vertex3);
    sfVertexArray_setPrimitiveType(triangle , sfTriangleStrip);
    return (triangle);
}

void do_vertex_array(variables_t *vars, sfVector2i v,
        sfVector2f **map_2d, info_map_t *inf_map)
{
    sfVertexArray *vertex_array2;
    int x = v.x;
    int y = v.y;

    vertex_array2 = create_block(&map_2d[y][x], &map_2d[y][x + 1],
            &map_2d[y + 1][x], inf_map->colors[y][x]);
    sfRenderWindow_drawVertexArray(vars->window, vertex_array2,
            NULL);
    sfVertexArray_destroy(vertex_array2);
    vertex_array2 = create_block(&map_2d[y + 1][x + 1],
            &map_2d[y][x + 1], &map_2d[y + 1][x],
            inf_map->colors[y][x]);
    sfRenderWindow_drawVertexArray(vars->window, vertex_array2,
            NULL);
    sfVertexArray_destroy(vertex_array2);
}

void do_vertex_array_help(variables_t *vars, sfVector2i v,
        sfVector2f **map_2d)
{
    sfVertexArray *vertex_array;
    int x = v.x;
    int y = v.y;

    vertex_array = create_line(&map_2d[y][x], &map_2d[y][x + 1]);
    sfRenderWindow_drawVertexArray(vars->window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
    vertex_array = create_line(&map_2d[y][x], &map_2d[y + 1][x]);
    sfRenderWindow_drawVertexArray(vars->window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}

int draw_2d_map(variables_t *vars, info_map_t *inf_map, sfVector2f **map_2d)
{

    for (int y = 0; y < inf_map->height; y++) {
        for (int x = 0; x < inf_map->width; x++) {
            if (x < inf_map->width && y < inf_map->height)
                do_vertex_array(vars, (sfVector2i) {x, y}, map_2d, inf_map);
            if ((x < inf_map->width - 1) && (y < inf_map->height - 1))
                do_vertex_array_help(vars, (sfVector2i) {x, y}, map_2d);
        }
    }
    map_freeing(map_2d, inf_map->height);
    return (0);
}