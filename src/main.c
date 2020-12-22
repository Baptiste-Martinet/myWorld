/*
** EPITECH PROJECT, 2018
** window opening
** File description:
** window operating
*/

#include "my.h"

int game_start(char *filepath)
{
    variables_t *vars;
    info_map_t *inf_map;

    vars = variables_create(1280, 900);
    inf_map = map_init(filepath);
    if (inf_map == NULL)
        return 84;
    sfMusic_setLoop(vars->music_background, sfTrue);
    sfMusic_play(vars->music_background);
    sfMusic_setVolume (vars->select_sound, 25.f);
    game_loop(vars, inf_map);
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 2) {
        write(2, "./my_world: bad arguments: 0 given but 1 is required\n" \
            "retry with -h\n", 68);
        return (84);
    }
    if (ac == 2 && my_strcomp(av[1], "-h") == 1) {
        write(1, "USAGE\n\t./my_world filepath\nDESCRIPTION\n" \
            "\tfilepath:  filepath of the txt map (will use 'init.legend'" \
            " if not specified)\n", 117);
        return 0;
    }
    if (ac == 1)
        return (game_start("map_init.legend"));
    return (game_start(av[1]));
}