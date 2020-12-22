/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void variables_create_help(variables_t *ptr_var)
{
    ptr_var->clock = sfClock_create();
    ptr_var->buttons = init_buttons();
    ptr_var->buttons_hover = init_buttons_hover();
    ptr_var->menu_buttons = init_menu_buttons();
    ptr_var->circle_select = create_circle();
    ptr_var->loading_text = create_text("Building terrain",
        (sfVector2f) {550, 550}, 30, sfWhite);
}

//initialise la strcuture vars

variables_t *variables_create(int width, int height)
{
    variables_t *ptr_var = malloc(sizeof(variables_t));

    if (ptr_var == NULL)
        return NULL;
    variables_create_help(ptr_var);
    ptr_var->loading_bar_background = create_coloured_button((sfVector2f)
        {450, 600}, (sfVector2f){410, 50}, (sfColor) {0, 0, 0, 40}, 0);
    ptr_var->loading_bar = create_coloured_button((sfVector2f)
        {460, 610}, (sfVector2f){0, 30}, (sfColor) {0, 240, 0, 255}, 0);
    ptr_var->select_sound = sfMusic_createFromFile("sounds/select_sound.wav");
    ptr_var->music_background = sfMusic_createFromFile("sounds/soundtrk.ogg");
    ptr_var->mode.width = width;
    ptr_var->mode.height = height;
    ptr_var->window = sfRenderWindow_create(ptr_var->mode,
        "My world (Press Q to quit)", sfClose, NULL);
    sfClock_restart(ptr_var->clock);
    ptr_var->GameState = 0;
    return (ptr_var);
}

void map_init_help(info_map_t *ptr_inf_map)
{
    ptr_inf_map->zoom = 1;
    ptr_inf_map->current_color = (sfColor) {60, 160, 43, 255};
    ptr_inf_map->intensite = 1;
    ptr_inf_map->map_pos = (sfVector2f) {640, 170};
    ptr_inf_map->color_wheel = sfImage_createFromFile("textures/wheel.png");
}

//initialise la structure inf_map

info_map_t *map_init(char *filepath)
{
    info_map_t *ptr_inf_map = malloc(sizeof(info_map_t));
    char *map = get_map(filepath);
    int width = get_map_width(map);
    int height = get_map_height(map);

    if (ptr_inf_map == NULL || map == NULL ||
            map_error_gestion(map, width, height) == 84) {
        write(2, "Error: pls select a valid map", 29);
        return (NULL);
    }
    ptr_inf_map->filepath = filepath;
    ptr_inf_map->width = width;
    ptr_inf_map->height = height;
    ptr_inf_map->map = map_to_tab(map, width, height);
    ptr_inf_map->saved_map = tab_cpy(ptr_inf_map->map, width, height);
    ptr_inf_map->colors = init_colors(width, height, map);
    ptr_inf_map->saved_colors = init_colors(width, height, map);
    map_init_help(ptr_inf_map);
    return (ptr_inf_map);
}