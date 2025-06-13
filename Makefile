# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 14:54:39 by ewiese-m          #+#    #+#              #
#    Updated: 2025/06/13 21:08:18 by ewiese-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

SRC_DIR		:= srcs

SRCS := \
			main.c \
			args/args_check.c \
			color/color_new.c \
			color/color_operations.c \
			data/data_free.c \
			data/data_initialize.c \
			double/double_comparaisons.c \
			events/event_key.c \
			events/event_resize.c \
			file/file_check.c \
			matrix/matrix_cofactor.c \
			matrix/matrix_comparaisons.c \
			matrix/matrix_create.c \
			matrix/matrix_determinant.c \
			matrix/matrix_inverse.c \
			matrix/matrix_minor.c \
			matrix/matrix_operations.c \
			matrix/matrix_rotation.c \
			matrix/matrix_scale.c \
			matrix/matrix_submatrix.c \
			matrix/matrix_translation.c \
			matrix/matrix_transpose.c \
			matrix/matrix_transform.c \
			matrix/matrix_skew_sym.c \
			mlx/mlx_exit.c \
			mlx/mlx_initialize.c \
			mlx/mlx_loop.c \
			mlx/mlx_render.c \
			mlx/mlx_pixel_put.c \
			inits/material_init.c \
			inits/camera_init.c \
			inits/minirt_init.c \
			parsing/parse_camera.c \
			parsing/parse_hittable.c \
			parsing/parse_lighting.c \
			parsing/parse_subcomponents.c \
			parsing/parse_transforms.c \
			parsing/parsing.c \
			free/parsing_free.c \
			free/scene_free.c \
			ray/ray_create.c \
			ray/ray_position.c \
			ray/ray_transform.c \
			tuple/tuple_functions.c \
			tuple/tuple_new.c \
			tuple/tuple_operations.c \
			tuple/tuple_transform.c \
			utils/ft_exit.c \
			render/render_scene.c \
			render/lighting.c \
			intersections/cylinder_intersection.c \
			intersections/sphere_intersection.c \
			intersections/plane_intersection.c \
			intersections/intersect.c \
			intersections/hit.c \
			normal/normal_at.c \
			normal/reflect.c \


SRCS := ${SRCS:%=${SRC_DIR}/%}

OBJ_DIR	:= .objs
OBJS	:= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

INCL_DIR	:= includes
MAIN_HEADER	:= ${INCL_DIR}/miniRT.h

INCL_FLAGS	:= -I${INCL_DIR}

MLX_DIR	:= minilibx-linux
MLX 		:= $(MLX_DIR)/libmlx.a

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

LDFLAGS	:= -L./libft/
LDLIBS	:= -lft

LIB_FLAGS	:= $(LDFLAGS) $(LDLIBS) -lm

OS_NAME := $(shell uname -s | tr A-Z a-z)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror


ifeq ($(OS_NAME),linux)
	MLX_LINK	:= -L$(MLX_DIR) -lmlx -lX11 -lXext
	MLX_INCL	:= -I$(MLX_DIR)
endif
ifeq ($(OS_NAME),darwin)
	MLX_LINK	:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L/usr/X11/lib -lX11 -lXext
	MLX_INCL	:= -I$(MLX_DIR) -I/usr/X11/include
	CFLAGS		:= -Wall -Wextra -g
endif

RM			:= rm -rf
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p ${@D}

all: ${NAME}

bonus: ${NAME}

${LIBFT}:
	git submodule update --init
	${MAKE} all -C ${LIBFT_DIR}

${MLX}:
	git submodule update --init
	${MAKE} all -C ${MLX_DIR}

${NAME}: ${MLX} ${LIBFT} ${OBJS}
	${CC} ${OBJS} ${MLX_LINK} ${LIB_FLAGS} -o ${NAME}
	${info EXECUTABLE CREATED: ${NAME}}


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} ${MLX_INCL} $(INCL_FLAGS) -c -o $@ $<
	${info OBJECT CREATED: $@}


clean:
	${RM} ${OBJS}
	make clean -C ${LIBFT_DIR}
	make clean -C ${MLX_DIR}
	${info REMOVED OBJECTS: ${OBJS}}

fclean: clean
	${RM} ${NAME} ${OBJ_DIR}
	make fclean -C ${LIBFT_DIR}
	${info REMOVED EXECUTABLES: ${NAME}}

re:
	${MAKE} fclean
	${MAKE} all

.PHONY: clean fclean re all bonus
.SILENT: ${NAME} ${SRCS} ${OBJS} ${LIBFT} all clean fclean re bonus
