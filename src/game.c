/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void map_reset(info_map_t *inf_map, variables_t *vars)
{
    for (int y = 0; y < inf_map->height; y++) {
        for (int x = 0; x < inf_map->width; x++) {
            inf_map->map[y][x] = inf_map->saved_map[y][x];
            inf_map->saved_colors[y][x] = (sfColor) {60, 160, 43, 255};
        }
    }
    inf_map->map_pos.x = 640;
    inf_map->map_pos.y = 220;
    inf_map->zoom = 1;
    inf_map->intensite = 1;
    sfText_setString(vars->buttons[1].message, "1");
}

void draw_transition(variables_t *vars)
{
    static float last_temps = 0;
    sfVector2f size = sfRectangleShape_getSize(vars->loading_bar.rectangle);

    vars->my_time = sfClock_getElapsedTime(vars->clock);
    last_temps += vars->my_time.microseconds / 1000000.0;
    while (last_temps >= 0.02f) {
        last_temps -= 0.02f;
        sfRectangleShape_setSize (vars->loading_bar.rectangle,
            (sfVector2f) {size.x + 5, size.y});
    }
    if (size.x >= 390) {
        sfRectangleShape_setSize (vars->loading_bar.rectangle,
            (sfVector2f) {0.f, size.y});
        vars->GameState = 1;
    }
    sfClock_restart(vars->clock);
    sfRenderWindow_drawText(vars->window, vars->loading_text, NULL);
    sfRenderWindow_drawRectangleShape(vars->window,
        vars->loading_bar_background.rectangle, NULL);
    sfRenderWindow_drawRectangleShape(vars->window,
        vars->loading_bar.rectangle, NULL);
}

int game_loop(variables_t *vars, info_map_t *inf_map)
{
    sfRenderWindow_setFramerateLimit(vars->window, 500);
    int *random = malloc(sizeof(int));

    srand(*random);
    while (sfRenderWindow_isOpen(vars->window))
    {
        manage_event(vars, inf_map);
        sfRenderWindow_clear(vars->window, (sfColor) {36, 37, 38, 255});
        switch (vars->GameState) {
            case 0: draw_menu(vars);
            break;
            case 1: draw_2d_map(vars, inf_map, create_2d_map(inf_map));
            draw_buttons(vars);
            break;
            case 2: draw_transition(vars);
            break;
        }
        sfRenderWindow_display(vars->window);
    }
    resources_clean(vars, inf_map);
    return 0;
}