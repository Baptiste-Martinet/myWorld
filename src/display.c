/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void resources_clean(variables_t *vars, info_map_t *inf_map)
{
    sfRenderWindow_destroy(vars->window);
    sfImage_destroy(inf_map->color_wheel);
    sfRectangleShape_destroy(vars->loading_bar.rectangle);
    sfRectangleShape_destroy(vars->loading_bar_background.rectangle);
    sfCircleShape_destroy (vars->circle_select);
    sfText_destroy(vars->loading_text);
    sfMusic_destroy(vars->select_sound);
    sfMusic_destroy(vars->music_background);
    for (int i = 0; i < 12; i++) {
        sfRectangleShape_destroy(vars->buttons[i].rectangle);
        if (vars->buttons[i].message != NULL)
            sfText_destroy(vars->buttons[i].message);
        if (i < 8) {
            sfRectangleShape_destroy(vars->buttons_hover[i].rectangle);
            sfText_destroy(vars->buttons_hover[i].message);
        }
    }
    for (int i = 0; i < 3; i++)
        sfRectangleShape_destroy(vars->menu_buttons[i].rectangle);
    free(vars);
    free(inf_map);
}

void draw_buttons_help(variables_t *vars)
{
    for (int i = 2; i < 10; i++) {
        if (vars->buttons[i].over == 1) {
            sfRectangleShape_setPosition(vars->buttons_hover[i - 2].rectangle,
                    (sfVector2f) {vars->mouse_pos.x, vars->mouse_pos.y});
            sfText_setPosition(vars->buttons_hover[i - 2].message,
                    (sfVector2f) {vars->mouse_pos.x + 5, vars->mouse_pos.y});
            sfRenderWindow_drawRectangleShape(vars->window,
                    vars->buttons_hover[i - 2].rectangle, NULL);
            sfRenderWindow_drawText(vars->window,
                    vars->buttons_hover[i - 2].message, NULL);
        }
    }
}

void draw_buttons(variables_t *vars)
{
    if (sfCircleShape_getPosition(vars->circle_select).x > 0)
        sfRenderWindow_drawCircleShape(vars->window,
                vars->circle_select, NULL);
    for (int i = 0; i < 12; i++) {
        sfRenderWindow_drawRectangleShape(vars->window,
                vars->buttons[i].rectangle, NULL);
        if (vars->buttons[i].message != NULL)
            sfRenderWindow_drawText(vars->window, vars->buttons[i].message,
                    NULL);
    }
    draw_buttons_help(vars);

}

void draw_menu(variables_t *vars)
{
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(vars->window,
                vars->menu_buttons[i].rectangle, NULL);
        if (vars->menu_buttons[i].message != NULL)
            sfRenderWindow_drawText(vars->window,
                    vars->menu_buttons[i].message, NULL);
    }
}