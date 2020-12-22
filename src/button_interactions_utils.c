/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

void manage_clic_help(int i, variables_t *vars, info_map_t *inf_map,
                    sfVector2i mouse_pos)
{
    switch (i) {
        case 5: zoom_gestion(inf_map, -1);
        break;
        case 6: save_map(inf_map);
        sfRenderWindow_close(vars->window);
        break;
        case 7: random_map_generation(inf_map);
        break;
        case 8: vars->GameState = 0;
        break;
        case 9: map_reset(inf_map, vars);
        break;
        case 10: chroma_whell_manager(mouse_pos, vars->buttons[10], inf_map);
        sfRectangleShape_setFillColor(vars->buttons[11].rectangle,
            inf_map->current_color);
        break;
    }
}

void chroma_whell_manager(sfVector2i mouse_pos, button_t button,
    info_map_t *inf_map)
{
    if (inf_map->color_wheel == NULL)
        return;
    if (sqrt(pow(mouse_pos.x - (button.pos.x + button.size.x / 2), 2) +
        pow(mouse_pos.y - (button.pos.y + button.size.y / 2), 2)) < 59.f) {
        inf_map->current_color = sfImage_getPixel(inf_map->color_wheel,
            mouse_pos.x - button.pos.x , mouse_pos.y - button.pos.y);
    }
}