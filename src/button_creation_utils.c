/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

button_t create_coloured_button(sfVector2f pos, sfVector2f size,
                                sfColor color, int type)
{
    button_t button;

    button.pos = pos;
    button.size = size;
    button.over = 0;
    button.rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(button.rectangle, color);
    sfRectangleShape_setPosition(button.rectangle, pos);
    sfRectangleShape_setSize(button.rectangle, size);
    if (type == 1) {
        sfRectangleShape_setOutlineColor(button.rectangle,
                                        (sfColor) {255, 255, 255, 50});
        sfRectangleShape_setOutlineThickness(button.rectangle, 4.f);
    }
    button.message = NULL;
    return (button);
}

button_t *init_buttons_hover(void)
{
    button_t *buttons = malloc(sizeof(button_t) * 8);

    buttons[0] = create_button(" Increase intensity", (sfVector2f) {200, 200},
        (sfVector2f) {250, 40}, 25.f);
    buttons[1] = create_button(" Decrease intensity", (sfVector2f) {200, 200},
        (sfVector2f) {250, 40}, 25.f);
    buttons[2] = create_button(" Zoom in\n 'Z'", (sfVector2f) {200, 200},
        (sfVector2f) {125, 55}, 25.f);
    buttons[3] = create_button(" Zoom out\n 'S'", (sfVector2f) {200, 200},
        (sfVector2f) {125, 55}, 25.f);
    buttons[4] = create_button(" Save\n 'W'", (sfVector2f) {200, 200},
        (sfVector2f) {110, 60}, 25.f);
    buttons[5] = create_button(" Randomizer\n 'R'", (sfVector2f) {200, 200},
        (sfVector2f) {200, 60}, 25.f);
    buttons[6] = create_button(" Exit\n 'Esc'", (sfVector2f) {200, 200},
        (sfVector2f) {110, 60}, 25.f);
    buttons[7] = create_button(" Reset", (sfVector2f) {200, 200},
        (sfVector2f) {125, 40}, 25.f);
    return (buttons);
}

sfText *create_text(char *message, sfVector2f pos, int font_size, sfColor color)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("fonts/Minecraft.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, font_size);
    sfText_setColor(text, color);
    sfText_setPosition(text, pos);
    sfText_setString(text, message);
    return (text);
}

sfSprite *create_sprite(char *filepath, sfVector2f pos, sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

sfCircleShape *create_circle(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (sfVector2f) {-20, -20});
    sfCircleShape_setRadius(circle, 5.f);
    sfCircleShape_setFillColor(circle, (sfColor) {255, 255, 255, 0});
    sfCircleShape_setOutlineColor(circle, (sfColor) {255, 0, 0, 255});
    sfCircleShape_setOutlineThickness(circle, 3.f);
    return (circle);
}