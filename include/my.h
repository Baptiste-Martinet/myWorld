/*
** EPITECH PROJECT, 2018
** My_runner
** File description:
** [file description here]
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct the_button {
    sfRectangleShape *rectangle;
    sfText *message;
    sfVector2f pos;
    sfVector2f size;
    int over;
} button_t;

typedef struct var {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfTime my_time;
    sfVideoMode mode;
    sfCircleShape *circle_select;
    sfMusic *select_sound;
    sfMusic *music_background;
    sfVector2i mouse_pos;
    button_t *buttons;
    button_t *menu_buttons;
    button_t *buttons_hover;
    button_t loading_bar;
    button_t loading_bar_background;
    sfText *loading_text;
    int GameState;
} variables_t;

typedef struct info_map {
    char *filepath;
    int **map;
    int **saved_map;
    sfColor **colors;
    sfColor **saved_colors;
    sfColor current_color;
    int width;
    int height;
    float zoom;
    int intensite;
    sfVector2f map_pos;
    sfImage *color_wheel;
} info_map_t;

/* main */
int game_start();

/* inits */
variables_t *variables_create(int width, int height);
info_map_t *map_init(char *filepath);

/* init_map_color */
sfColor **init_colors(int width, int height, char *map);

/* game */
int game_loop(variables_t *vars, info_map_t *inf_map);
void map_reset(info_map_t *inf_map, variables_t *vars);

/* isio_bootstrap */
sfVector2f project_iso_point(sfVector3f coords, int value,
    sfVector2f map_pos);
sfVector2f **create_2d_map(info_map_t *inf_map);
sfVertexArray *create_line(sfVector2f *point1 , sfVector2f *point2);
int draw_2d_map(variables_t *vars, info_map_t *inf_map, sfVector2f **map_2d);

/* event_manager */
void manage_event(variables_t *vars, info_map_t *inf_map);

/* display */
void resources_clean(variables_t *vars, info_map_t *inf_map);
void draw_buttons(variables_t *vars);
void draw_menu(variables_t *vars);

/* button_creation */
button_t *init_buttons();
button_t *init_menu_buttons();
button_t create_button(char *message, sfVector2f pos, sfVector2f size,
    int font_size);
button_t create_coloured_button(sfVector2f pos, sfVector2f size,
    sfColor color, int type);
button_t create_button_from_texture(char *filepath, sfVector2f pos,
    sfVector2f size);

/* button creationg utils */
button_t *init_buttons_hover();
sfText *create_text(char *message, sfVector2f pos, int font_size,
    sfColor color);
sfSprite *create_sprite(char *filepath, sfVector2f pos, sfIntRect rect);
sfCircleShape *create_circle();

/* button_interactions */
void mouse_hover_manager(variables_t *vars, info_map_t *inf_map);
void mouse_clic_manager(variables_t *vars, info_map_t *inf_map);

/* button interaction utils */
void manage_clic_help(int i, variables_t *vars, info_map_t *inf_map,
                    sfVector2i mouse_pos);
void chroma_whell_manager(sfVector2i mouse_pos, button_t button,
    info_map_t *inf_map);

/* menu button interactions */
void menu_button_clic(sfVector2i mouse_pos, variables_t *vars);
void menu_button_hover(variables_t *vars, sfVector2i mouse_pos);

/* map_interactions */
void terrain_transform(sfVector2i mouse_pos, info_map_t *inf_map, int action);
void random_map_generation(info_map_t *inf_map);
void zoom_gestion(info_map_t *inf_map, int action);
void set_tile_color(sfVector2i mouse_pos, info_map_t *inf_map);

/* map interactions 2 */
void mouse_hover_map(sfVector2i mouse_pos, info_map_t *inf_map);
void mouse_hover_points(sfVector2i mouse_pos, info_map_t *inf_map,
    variables_t *vars);

/* map_saver */
void save_map(info_map_t *inf_map);

/* map_parser */
char *get_map(char *filepath);
int get_map_width(char *map);
int get_map_height(char *map);
int get_map_value(char nb1, char nb2);
int **map_to_tab(char *map, int width, int height);

/* map_error_gestion */
int map_error_gestion(char *map, int width, int height);

/* utils */
sfIntRect rect_create(int top, int left, int width, int height);
sfVector2f vec_create(float x, float y);
char *my_strcat(char *str1, char *str2);
int my_strlen(char *str);
int my_strcomp(char *name1, char *name2);

/* utils2 */
int my_getnbr(char *str);
char *my_itoa(int nb);
void map_freeing(sfVector2f **map, int size);
int **tab_cpy(int **tab, int width, int height);