NAME 	=	cub3d

NAME_LIN=	cubd3d_lin

CFILES	=	cub3d.c \
			src/init/cub3d_init.c \
			src/init/something_init.c \
			src/init/write_params.c \
			src/init/init_mlx.c \
			src/validation/map_valid.c \
			src/validation/params_valid.c\
			src/game/draw_map.c\
			src/game/ft_walk.c\
			src/game/player_control.c\
			src/utils/check_filename.c \
			src/utils/ft_error.c \
			src/utils/ft_realloc.c \
			src/utils/ft_isspace.c \
			src/utils/free_functions.c \
			src/utils/ft_exit.c \
			src/utils/mlx_pixel_put.c	\
			libs/get_next_line/get_next_line.c \

OBJECTS	= $(CFILES:.c=.o)

D_FILES =	$(patsubst %.c,%.d,$(CFILES))

LIB_PATH = libs/libft/

CC = gcc

CFLAGS = -Wall -Wextra -g3 -O2

MLX		=	-L libs/mlx -lmlx -framework OpenGL -framework AppKit


.PHONY	:	all clean fclean re

all		: lib $(NAME)

lin		: lib $(NAME_LIN)

lib		:
	make -C $(LIB_PATH)
	make -C $(LIB_PATH) bonus

$(NAME_LIN) : $(OBJECTS) $(LIB_PATH)libft.a
	make -C libs/mlx_linux
	$(CC) $(CFLAGS)  $(OBJECTS) $(LIB_PATH)libft.a -lmlx -I libs/mlx_linux -L libs/mlx_linux -lXext -lX11 -lm -lbsd -o $(NAME_LIN)

$(NAME)	:	$(OBJECTS) $(LIB_PATH)libft.a
	make -C libs/mlx
	$(CC) $(CFLAGS)  $(OBJECTS) $(LIB_PATH)libft.a $(MLX)  -o $(NAME)

%.o 	:	%.c	$(LIB_PATH)libft.a
	$(CC) $(CFLAGS) -I libs/mlxlinux -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean	:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS) $(D_FILES)

fclean	:	clean
	make -C $(LIB_PATH) fclean
	make clean -C libs/mlx
	make clean -C libs/mlx_linux
	rm -f $(NAME)
	rm -f $(NAME_LIN)

re		:	fclean all
