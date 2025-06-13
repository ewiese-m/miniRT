# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 14:54:39 by ewiese-m          #+#    #+#              #
#    Updated: 2025/06/14 00:17:36 by ewiese-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

SRC_DIR		:= srcs

SRCS := \
    main.c \
    core/data_initialize.c \
    core/data_free.c \
    core/minirt_init.c \
    math/vectors/tuple_new.c \
    math/vectors/tuple_operations.c \
    math/vectors/tuple_functions.c \
    math/vectors/tuple_transform.c \
    math/matrices/matrix_create.c \
    math/matrices/matrix_operations.c \
    math/matrices/matrix_determinant.c \
    math/matrices/matrix_inverse.c \
    math/matrices/matrix_transpose.c \
    math/matrices/matrix_cofactor.c \
    math/matrices/matrix_minor.c \
    math/matrices/matrix_submatrix.c \
    math/matrices/matrix_comparaisons.c \
    math/matrices/matrix_transform.c \
    math/matrices/matrix_rotation.c \
    math/matrices/matrix_translation.c \
    math/matrices/matrix_scale.c \
    math/matrices/matrix_skew_sym.c \
    math/rays/ray_create.c \
    math/rays/ray_position.c \
    math/rays/ray_transform.c \
    math/utils/double_comparaisons.c \
    input/args_check.c \
    input/file_check.c \
    parsing/parsing.c \
    parsing/parse_camera.c \
    parsing/parse_hittable.c \
    parsing/parse_lighting.c \
    parsing/parse_subcomponents.c \
    parsing/parse_transforms.c \
    objects/intersections/sphere_intersection.c \
    objects/intersections/plane_intersection.c \
    objects/intersections/cylinder_intersection.c \
    objects/intersections/intersect.c \
    objects/intersections/hit.c \
    objects/normals/normal_at.c \
    objects/normals/reflect.c \
    rendering/render_scene.c \
    rendering/lighting.c \
    rendering/color/color_new.c \
    rendering/color/color_operations.c \
    camera/camera_init.c \
    camera/material_init.c \
    graphics/mlx_initialize.c \
    graphics/mlx_render.c \
    graphics/mlx_pixel_put.c \
    graphics/mlx_loop.c \
    graphics/mlx_exit.c \
    graphics/events/event_key.c \
    graphics/events/event_resize.c \
    memory/parsing_free.c \
    memory/scene_free.c \
    utils/ft_exit.c \


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
