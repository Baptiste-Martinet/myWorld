/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

sfVector2f project_iso_point(sfVector3f c, int value, sfVector2f map_pos)
{
    sfVector2f d_p;

    d_p.x = cos(0.785398) * c.x - cos(0.785398) * c.y + map_pos.x;
    d_p.y = sin(0.610865) * c.y + sin(0.610865) * c.x - c.z + map_pos.y;
    d_p.y += value;
    return (d_p);
}

sfVector2f **create_2d_map_help(info_map_t *inf_map, int x, int y,
        sfVector2f **map_2d)
{
    if (y < inf_map->height)
        map_2d[y][x] = project_iso_point((sfVector3f)
        {(x - 1) * (64 * inf_map->zoom), y * (64 * inf_map->zoom),
        0 * (10.66 * inf_map->zoom)},
        96 * inf_map->zoom, inf_map->map_pos);
    else
        map_2d[y][x] = project_iso_point((sfVector3f)
        {x * (64 * inf_map->zoom), (y - 1) * (64 * inf_map->zoom),
        0 * (10.66 * inf_map->zoom)}, 96 * inf_map->zoom,
        inf_map->map_pos);
    return (map_2d);
}

sfVector2f **create_2d_map(info_map_t *inf_map)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * (inf_map->height + 1));

    for (int y = 0; y < inf_map->height + 1; y++) {
        map_2d[y] = malloc(sizeof(sfVector2f) * (inf_map->width + 1));
        for (int x = 0; x < inf_map->width + 1; x++) {
            if (x < inf_map->width && y < inf_map->height)
                map_2d[y][x] = project_iso_point((sfVector3f)
                {x * (64 * inf_map->zoom), y * (64 * inf_map->zoom),
                inf_map->map[y][x] * (10.66 * inf_map->zoom)}, 0,
                inf_map->map_pos);
            else {
                map_2d = create_2d_map_help(inf_map, x, y, map_2d);
            }
        }
    }
    return (map_2d);
}