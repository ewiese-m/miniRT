# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 22:41:26 by ewiese-m          #+#    #+#              #
#    Updated: 2025/06/04 22:41:34 by ewiese-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

# Source files
SOURCES = main.c \
          init/init_scene.c \
          init/init_mlx.c \
          init/init_objects.c \
          parser/parser.c \
          parser/parse_scene.c \
          parser/parse_camera.c \
          parser/parse_lights.c \
          parser/parse_objects.c \
          parser/parse_utils.c \
          raytracing/ray.c \
          raytracing/camera.c \
          raytracing/intersections.c \
          raytracing/lighting.c \
          raytracing/render.c \
          objects/sphere.c \
          objects/plane.c \
          objects/cylinder.c \
          objects/object_utils.c \
          math/vector_operations.c \
          math/vector_math.c \
          math/matrix.c \
          math/math_utils.c \
          utils/error_handling.c \
          utils/memory_management.c \
          utils/string_utils.c \
          utils/validation.c \
          graphics/mlx_interface.c \
          graphics/image.c \
          graphics/color.c \
          graphics/window.c

# Bonus sources
BONUS_SOURCES = bonus/bonus_objects.c \
                bonus/specular.c \
                bonus/textures.c \
                bonus/advanced_lighting.c

# Object files
OBJS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SOURCES:%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@echo "$(BLUE)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@echo "$(BLUE)Building minilibx...$(RESET)"
	@make -C $(MLX_DIR)

bonus: $(OBJS) $(BONUS_OBJS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	@echo "$(BLUE)Linking $(NAME) with bonus...$(RESET)"
	@$(CC) $(OBJS) $(BONUS_OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) with bonus created successfully!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

test: $(NAME)
	@echo "$(BLUE)Running tests...$(RESET)"
	@./$(NAME) scenes/test_basic.rt

.PHONY: all clean fclean re bonus test
