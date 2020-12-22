/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void mouse_hover_map(sfVector2i mouse_pos, info_map_t *inf_map)
{
    sfVector2f **map_2d = create_2d_map(inf_map);
    sfVector2f hitbox;

    for (int y = 0; y < inf_map->height - 1; y++) {
        for (int x = 0; x < inf_map->width - 1; x++) {
            hitbox.x = abs(map_2d[y + 1][x].x - map_2d[y][x + 1].x) / 2.9;
            hitbox.y = abs(map_2d[y][x].y - map_2d[y + 1][x + 1].y) / 2.9;
            if ((map_2d[y + 1][x].x + hitbox.x) < mouse_pos.x && mouse_pos.x <
                (map_2d[y][x + 1].x - hitbox.x) && (map_2d[y][x].y + hitbox.y)
                < mouse_pos.y && mouse_pos.y < (map_2d[y + 1][x + 1].y -
                    hitbox.y)) {
                inf_map->colors[y][x] = (sfColor) {26, 27, 28, 255};
                break;
            } else {
                inf_map->colors[y][x] = inf_map->saved_colors[y][x];
            }
        }
    }
    map_freeing(map_2d, inf_map->height);
}

void hover_point_help(sfVector2f *last_pos, int test, variables_t *vars)
{
    if (test == 0) {
        *last_pos = (sfVector2f) {-1, -1};
        sfCircleShape_setPosition(vars->circle_select,
            (sfVector2f) {-20, -20});
    }
}

void mouse_hover_points(sfVector2i mouse_pos, info_map_t *inf_map,
                        variables_t *vars)
{
    sfVector2f **map_2d = create_2d_map(inf_map);
    static sfVector2f last_pos = (sfVector2f) {-1, -1};
    int test = 0;

    for (int y = inf_map->height - 1; y > -1; y--) {
        for (int x = 0; x < inf_map->width; x++) {
            if ((map_2d[y][x].x - 5) < mouse_pos.x && mouse_pos.x <
                (map_2d[y][x].x + 5) && (map_2d[y][x].y - 5) < mouse_pos.y &&
                mouse_pos.y < (map_2d[y][x].y + 5)) {
                sfCircleShape_setPosition(vars->circle_select, (sfVector2f)
                    {(map_2d[y][x].x - 5), (map_2d[y][x].y - 5)});
                if (x != last_pos.x || y != last_pos.y)
                    sfMusic_play(vars->select_sound);
                test = 1;
                last_pos = (sfVector2f) {x, y};
                break;
            }
        }
    }
    hover_point_help(&last_pos, test, vars);
    map_freeing(map_2d, inf_map->height);
}