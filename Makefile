##
## EPITECH PROJECT, 2018
## runner
## File description:
## Makefile for my_runner
##

SRC	=   src/main.c \
        src/game.c \
        src/inits.c \
        src/init_map_color.c \
        src/isio_bootstrap.c \
        src/event_manager.c \
        src/display.c \
        src/button_creation.c \
        src/button_creation_utils.c \
        src/button_interactions.c \
        src/button_interactions_utils.c \
        src/menu_button_interactions.c \
        src/map_interactions.c \
        src/map_interactions2.c \
        src/map_saver.c \
        src/map_error_gestion.c \
        src/map_parser.c \
        src/utils.c \
        src/utils2.c \
        src/isio_boostrap_utils.c

OBJ	=	$(SRC:.c=.o)

NAME    =    my_world

CFLAGS += -O2 -Wall -Wextra -Iinclude

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all:    $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	clean all

.PHONY: clean fclean re all