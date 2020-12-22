/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void zoom_gestion(info_map_t *inf_map, int action)
{
    if (action == 1) {
        if (inf_map->zoom <= 1)
            inf_map->zoom = inf_map->zoom * 2;
        else
            inf_map->zoom += 0.5;
    }
    if (action == -1) {
        if (inf_map->zoom <= 1)
            inf_map->zoom = inf_map->zoom / 2;
        else
            inf_map->zoom -= 0.5;
    }
}

void manage_menu_event(variables_t *vars)
{
    if (vars->event.type == sfEvtClosed)
        sfRenderWindow_close(vars->window);
    if (vars->event.type == sfEvtKeyPressed && vars->event.key.code > 0) {
        if (vars->event.key.code == sfKeyEscape ||
        vars->event.key.code == sfKeyQ)
            sfRenderWindow_close(vars->window);
    }
    menu_button_hover(vars, sfMouse_getPositionRenderWindow(vars->window));
    if (vars->event.type == sfEvtMouseButtonPressed) {
        if (vars->event.mouseButton.button == sfMouseLeft)
            menu_button_clic(sfMouse_getPositionRenderWindow(vars->window),
                    vars);
    }
}

void manage_event_help(variables_t *vars, info_map_t *inf_map)
{
    if (vars->event.type == sfEvtMouseButtonPressed) {
        if (vars->event.mouseButton.button == sfMouseLeft)
            mouse_clic_manager(vars, inf_map);
        if (vars->event.mouseButton.button == sfMouseRight)
            terrain_transform(sfMouse_getPositionRenderWindow(vars->window),
                    inf_map, -2);
    }
    if (vars->event.type == sfEvtMouseWheelScrolled) {
        if (vars->event.mouseWheelScroll.delta > 0)
            zoom_gestion(inf_map, 1);
        else
            zoom_gestion(inf_map, -1);
    }
}

void manage_event_key(variables_t *vars, info_map_t *inf_map)
{
    if (vars->event.key.code == sfKeyEscape)
        vars->GameState = 0;
    if (vars->event.key.code == sfKeyQ)
        sfRenderWindow_close(vars->window);
    if (vars->event.key.code == sfKeyZ)
        zoom_gestion(inf_map, 1);
    if (vars->event.key.code == sfKeyS)
        zoom_gestion(inf_map, -1);
    if (vars->event.key.code == sfKeyR)
        random_map_generation(inf_map);
    if (vars->event.key.code == sfKeyW) {
        save_map(inf_map);
        sfRenderWindow_close(vars->window);
    }
    if (vars->event.key.code == sfKeyLeft)
        inf_map->map_pos.x += 60;
    if (vars->event.key.code == sfKeyRight)
        inf_map->map_pos.x -= 60;
    if (vars->event.key.code == sfKeyUp)
        inf_map->map_pos.y += 60;
}

void manage_event(variables_t *vars, info_map_t *inf_map)
{
    while (sfRenderWindow_pollEvent(vars->window, &vars->event)) {
        if (vars->GameState == 2)
            break;
        if (vars->GameState == 0) {
            manage_menu_event(vars);
            break;
        }
        vars->mouse_pos = sfMouse_getPositionRenderWindow(vars->window);
        mouse_hover_manager(vars, inf_map);
        if (vars->event.type == sfEvtClosed)
            sfRenderWindow_close(vars->window);
        if (vars->event.type == sfEvtKeyPressed && vars->event.key.code > 0) {
            manage_event_key(vars, inf_map);
            if (vars->event.key.code == sfKeyDown)
                inf_map->map_pos.y -= 60;
        }
        manage_event_help(vars, inf_map);
    }
}