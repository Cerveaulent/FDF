# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/28 17:33:52 by ccantin      #+#   ##    ##    #+#        #
#    Updated: 2019/10/01 17:42:00 by ccantin     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean libft mlx

NAME = fdf

###############		OS DEFINITION		###############

OS_NAME := $(shell uname)

###############		FLAGS && COMPILER	###############

CC = clang

CC_FLAGS = -Werror -Wall -Wextra

############### 		LIBFT			###############

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

###############			MLX				###############

ifeq ($(OS_NAME),Linux)
	MLX_PATH = mlx_x11
	OS_FLAGS = -lXext -lX11 -lm
else
	MLX_PATH = mlx_macos
	OS_FLAGS = -framework OpenGL -framework AppKit
endif

MLX = $(MLX_PATH)/libmlx.a

###############			INCLUDES		###############

INC_PATH =	includes

INC_NAME =	fdf.h \
			error_handler.h \
			lpoints_handler.h \
			array_handler.h \
			key_map.h \
			mouse_map.h

INCLUDES = -I$(MLX_PATH) -I$(LIBFT_PATH) -I$(INC_PATH)

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

###############			SRCS			###############

SRCS_PATH = srcs

SRCS_NAME = main.c \
			lpoints_handler.c \
			bresenham.c \
			scale.c \
			init_functions.c \
			array_handler.c \
			parsing.c \
			error_handler.c \
			key_handler.c \
			print_map.c \
			zoom_handler.c \
			mlx_img_handler.c \
			free_structs.c \
			move.c \
			reset_map.c \
			transfo_iso.c \
			legend_displayer.c \
			modif_height.c

SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))

###############			OBJECTS			###############

OBJ_PATH = obj

OBJ = $(addprefix $(OBJ_PATH)/,$(SRCS_NAME:.c=.o))

###############			RULES			###############

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@ $(CC) $(CC_FLAGS) $(OS_FLAGS) -o $@ $(OBJ) $(INCLUDES)  $(LIBFT) $(MLX)
	@ printf "Compilation de %s ✅\n" $@ 

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c $(INC)
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@ $(CC) $(CC_FLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT):
	 @ make -C $(LIBFT_PATH)
	 @ printf "Compilation de %s ✅\n" $@

$(MLX):
	 @ make -C $(MLX_PATH)
	 @ printf "Compilation de %s ✅\n" $@ 

clean:
	@ /bin/rm -rf $(OBJ_PATH)
	@ make -C $(LIBFT_PATH) clean
	@ printf "Suppression des .o %s ✅\n" $(OBJ_PATH)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C $(MLX_PATH) clean
	@ make -C $(LIBFT_PATH) fclean
	@ printf "Suppression du binaire %s ✅\n" $(NAME)

re: fclean all
