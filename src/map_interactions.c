/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

//transforme le terrain selon la valeur de 'action'
//(-1 diminuera la hauteur de 1, 2 augmentera la hauteur de 2 par exemple)

void terrain_transform(sfVector2i mouse_pos, info_map_t *inf_map, int action)
{
    sfVector2f **map_2d = create_2d_map(inf_map);

    for (int y = inf_map->height - 1; y > -1; y--) {
        for (int x = 0; x < inf_map->width; x++) {
            if ((map_2d[y][x].x - 5) < mouse_pos.x && mouse_pos.x <
                (map_2d[y][x].x + 5) && (map_2d[y][x].y - 5) < mouse_pos.y &&
                mouse_pos.y < (map_2d[y][x].y + 5)) {
                inf_map->map[y][x] += action;
                if (inf_map->map[y][x] + action < -9)
                    inf_map->map[y][x] = -9;
                if (inf_map->map[y][x] + action > 99)
                    inf_map->map[y][x] = 99;
                break;
            }
        }
    }
}

void random_map_generation(info_map_t *inf_map)
{
    for (int y = 0; y < inf_map->height; y++) {
        for (int x = 0; x < inf_map->width; x++) {
            inf_map->map[y][x] = (-2 + (rand() % 4));
        }
    }
}

void set_tile_color(sfVector2i mouse_pos, info_map_t *inf_map)
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
                inf_map->saved_colors[y][x] = inf_map->current_color;
                break;
            }
        }
    }
    map_freeing(map_2d, inf_map->height);
}