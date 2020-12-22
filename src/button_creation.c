/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

button_t *init_buttons_help(button_t *buttons)
{
    buttons[6] = create_button_from_texture("textures/btn_save.jpg",
            (sfVector2f) {670, 27}, (sfVector2f) {60, 60});
    buttons[7] = create_button_from_texture("textures/btn_rand.jpg",
            (sfVector2f) {470, 27}, (sfVector2f) {60, 60});
    buttons[8] = create_button_from_texture("textures/btn_exit.jpg",
            (sfVector2f) {770, 27}, (sfVector2f) {60, 60});
    buttons[9] = create_button_from_texture("textures/btn_reset.jpg",
            (sfVector2f) {570, 27}, (sfVector2f) {60, 60});
    buttons[10] = create_button_from_texture("textures/wheel.png",
            (sfVector2f) {1100, 162}, (sfVector2f) {120, 120});
    sfRectangleShape_setOutlineThickness(buttons[10].rectangle, 0.f);
    buttons[11] = create_coloured_button((sfVector2f){1130, 297},
            (sfVector2f){60, 30}, (sfColor) {60, 160, 43, 255}, 0);
    return (buttons);
}

button_t *init_buttons(void)
{
    button_t *buttons = malloc(sizeof(button_t) * 12);

    buttons[0] = create_coloured_button((sfVector2f){0, 0},
            (sfVector2f){1280, 120}, (sfColor) {0, 0, 0, 60}, 0);
    buttons[1] = create_button("1", (sfVector2f) {290, 27},
            (sfVector2f) {60, 60}, 49);
    buttons[2] = create_button_from_texture("textures/btn_up.jpg",
            (sfVector2f) {370, 27}, (sfVector2f) {60, 60});
    buttons[3] = create_button_from_texture("textures/btn_down.jpg",
            (sfVector2f) {210, 27}, (sfVector2f) {60, 60});
    buttons[4] = create_button_from_texture("textures/btn_zoom_in.jpg",
            (sfVector2f) {110, 27}, (sfVector2f) {60, 60});
    buttons[5] = create_button_from_texture("textures/btn_zoom_out.jpg",
            (sfVector2f) {30, 27}, (sfVector2f) {60, 60});
    return (init_buttons_help(buttons));
}

button_t *init_menu_buttons(void)
{
    button_t *buttons = malloc(sizeof(button_t) * 3);

    buttons[0] = create_button_from_texture("textures/menu_background5.jpg",
            (sfVector2f) {0, 0}, (sfVector2f) {1280, 900});
    buttons[1] = create_button_from_texture("textures/btn_menu_start.png",
            (sfVector2f) {501, 300}, (sfVector2f) {277, 111});
    buttons[2] = create_button_from_texture("textures/btn_menu_exit.png",
            (sfVector2f) {501, 460}, (sfVector2f) {277, 111});
    sfRectangleShape_setOutlineColor(buttons[1].rectangle,
            (sfColor) {255, 255, 255, 0});
    sfRectangleShape_setOutlineColor(buttons[2].rectangle,
            (sfColor) {255, 255, 255, 0});
    return (buttons);
}

button_t create_button_from_texture(char *filepath, sfVector2f pos,
        sfVector2f size)
{
    button_t button;
    sfTexture *bt_texture = sfTexture_createFromFile(filepath, NULL);

    button.message = NULL;
    button.pos = pos;
    button.size = size;
    button.over = 0;
    button.rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(button.rectangle,
            (sfColor) {255, 255, 255, 255});
    sfRectangleShape_setOutlineColor(button.rectangle,
            (sfColor) {255, 255, 255, 50});
    sfRectangleShape_setPosition(button.rectangle, pos);
    sfRectangleShape_setSize(button.rectangle, size);
    sfRectangleShape_setOutlineThickness(button.rectangle, 4.f);
    sfRectangleShape_setTextureRect(button.rectangle,
            (sfIntRect) {0, 0, size.x, size.y});
    sfRectangleShape_setTexture(button.rectangle, bt_texture, sfFalse);
    return (button);
}

button_t create_button(char *message, sfVector2f pos, sfVector2f size,
        int font_size)
{
    button_t button;
    sfVector2f text_pos = pos;

    button.pos = pos;
    button.size = size;
    button.over = 0;

    button.rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(button.rectangle,
            (sfColor) {45, 45, 44, 255});
    sfRectangleShape_setOutlineColor(button.rectangle,
            (sfColor) {255, 255, 255, 30});
    sfRectangleShape_setPosition(button.rectangle, pos);
    sfRectangleShape_setSize(button.rectangle, size);
    sfRectangleShape_setOutlineThickness(button.rectangle, 3.5f);
    text_pos.x += 5;
    button.message = create_text(message, text_pos, font_size, sfBlack);
    return (button);
}