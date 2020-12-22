/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void menu_button_hover(variables_t *vars, sfVector2i mouse_pos)
{
    for (int i = 1; i < 3; i++) {
        if ((vars->menu_buttons[i].pos.x) < mouse_pos.x && mouse_pos.x <
            (vars->menu_buttons[i].pos.x + vars->menu_buttons[i].size.x) &&
            (vars->menu_buttons[i].pos.y) < mouse_pos.y && mouse_pos.y <
            (vars->menu_buttons[i].pos.y + vars->menu_buttons[i].size.y)) {
            if (vars->menu_buttons[i].over == 0) {
                vars->menu_buttons[i].over = 1;
                sfRectangleShape_setOutlineColor(
                    vars->menu_buttons[i].rectangle, sfWhite);
                sfMusic_play(vars->select_sound);
            }
        } else if (vars->menu_buttons[i].over == 1){
            vars->menu_buttons[i].over = 0;
            sfRectangleShape_setOutlineColor(vars->menu_buttons[i].rectangle,
                (sfColor) {255, 255, 255, 0});
        }
    }
}

void menu_manage_clic(int i, variables_t *vars)
{
    switch (i) {
        case 1: vars->GameState = 2;
        sfRectangleShape_setOutlineColor(vars->menu_buttons[i].rectangle,
                                        (sfColor) {255, 255, 255, 0});
        break;
        case 2: sfRenderWindow_close(vars->window);
        break;
    }
}

void menu_button_clic(sfVector2i mouse_pos, variables_t *vars)
{
    for (int i = 1; i < 3; i++) {
        if ((vars->menu_buttons[i].pos.x) < mouse_pos.x && mouse_pos.x <
            (vars->menu_buttons[i].pos.x + vars->menu_buttons[i].size.x) &&
            (vars->menu_buttons[i].pos.y) < mouse_pos.y && mouse_pos.y <
            (vars->menu_buttons[i].pos.y + vars->menu_buttons[i].size.y)) {
            menu_manage_clic(i, vars);
        }
    }
}