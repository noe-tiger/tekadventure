##
## Makefile for makefile in /home/samuel/Rush/scroller
## 
## Made by samuel
## Login   <samuel.rousseaux@epitech.eu>
## 
## Started on  Fri Mar 31 20:41:02 2017 samuel
## Last update Sun May 28 23:15:16 2017 Victor CHAU
##

SRCS	=	src/main.c			\
		src/cinematic.c			\
		src/credits.c			\
		src/intro.c			\
		src/voice.c			\
		src/ends.c			\
		src/cursor.c			\
		src/action.c			\
		src/inventory.c			\
		src/inventory_actions.c		\
		src/sprites.c			\
		src/movement.c			\
		src/movement_op.c		\
		src/movement_pos.c		\
		src/init_sprites_player.c	\
		src/extract_contents.c		\
		src/first_animation.c		\
		src/free_files.c		\
		src/get_file_content.c		\
		src/manage_my_tab.c		\
		src/menu.c			\
		src/my_dupline.c		\
		src/my_getnbr.c			\
		src/my_put_in_list.c		\
		src/my_strcat.c			\
		src/my_str_isbinary.c		\
		src/my_strlen.c			\
		src/my_strncmp.c		\
		src/parser_my_file.c		\
		src/press_button.c		\
		src/render_window.c		\
		src/verif_extension.c		\
		src/change_room.c		\
		src/print_maps.c		\
		src/last_choice.c		\
		src/put.c			\
		src/my_strcmp.c			\
		src/render.c			\
		src/generate.c			\
		src/sprite_gen_pnj.c		\
		src/sprite_gen_obj.c		\
		src/get_func.c			\
		src/print_obj.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	tekadventure

CFLAGS	=	-Wextra -Wall -I./inc

LDFLAGS	=	-lc_graph_prog_full -lm

CC	=	gcc

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean all clean
