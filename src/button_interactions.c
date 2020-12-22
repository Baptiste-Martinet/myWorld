/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void button_hover(variables_t *vars, sfVector2i mouse_pos)
{
    for (int i = 2; i < 11; i++) {
        if ((vars->buttons[i].pos.x) < mouse_pos.x && mouse_pos.x <
            (vars->buttons[i].pos.x + vars->buttons[i].size.x) &&
            (vars->buttons[i].pos.y) < mouse_pos.y && mouse_pos.y <
            (vars->buttons[i].pos.y + vars->buttons[i].size.y)) {
            if (vars->buttons[i].over == 0) {
                vars->buttons[i].over = 1;
                if (i < 10)
                    sfMusic_play(vars->select_sound);
                sfRectangleShape_setOutlineColor(vars->buttons[i].rectangle,
                    (sfColor) {255, 255, 255, 255});
            }
        } else if (vars->buttons[i].over == 1){
            vars->buttons[i].over = 0;
            sfRectangleShape_setOutlineColor(vars->buttons[i].rectangle,
                (sfColor) {255, 255, 255, 50});
        }
    }
}

void manage_clic(int i, variables_t *vars, info_map_t *inf_map,
    sfVector2i mouse_pos)
{
    sfRectangleShape_setOutlineColor(vars->buttons[i].rectangle,
        (sfColor) {255, 0, 0, 255});
    switch (i) {
        case 2: inf_map->intensite < 99 ?
        inf_map->intensite += 2 : (inf_map->intensite = inf_map->intensite);
        sfText_setString(vars->buttons[1].message,
            my_itoa(inf_map->intensite));
        break;
        case 3: inf_map->intensite > -9 ?
        (inf_map->intensite -= 2) : (inf_map->intensite = inf_map->intensite);
        sfText_setString(vars->buttons[1].message,
            my_itoa(inf_map->intensite));
        break;
        default: manage_clic_help(i, vars, inf_map, mouse_pos);
        break;
        case 4: zoom_gestion(inf_map, 1);
        break;
    }
}

void button_clic(sfVector2i mouse_pos, variables_t *vars, info_map_t *inf_map)
{
    for (int i = 2; i < 11; i++) {
        if ((vars->buttons[i].pos.x) < mouse_pos.x && mouse_pos.x <
            (vars->buttons[i].pos.x + vars->buttons[i].size.x) &&
            (vars->buttons[i].pos.y) < mouse_pos.y && mouse_pos.y <
            (vars->buttons[i].pos.y + vars->buttons[i].size.y)) {
            manage_clic(i, vars, inf_map, mouse_pos);
        }
    }
}

void mouse_hover_manager(variables_t *vars, info_map_t *inf_map)
{
    mouse_hover_map(vars->mouse_pos, inf_map);
    mouse_hover_points(vars->mouse_pos, inf_map, vars);
    button_hover(vars, vars->mouse_pos);
}

void mouse_clic_manager(variables_t *vars, info_map_t *inf_map)
{
    button_clic(vars->mouse_pos, vars, inf_map);
    set_tile_color(vars->mouse_pos, inf_map);
    terrain_transform(vars->mouse_pos, inf_map, inf_map->intensite);
}