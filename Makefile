# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 16:53:28 by ewiese-m          #+#    #+#              #
#    Updated: 2025/05/31 16:33:56 by ewiese-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./includes -I./libft -I./minilibx-linux

# Directorios
SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

# Archivos fuente
SRCS = $(SRC_DIR)/main.c \
	   $(SRC_DIR)/events.c

# Archivos objeto
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Librerías
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Flags de enlazado
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Nombre del programa
NAME = miniRT

# Regla principal
all: $(NAME)

# Compilar el programa principal
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Compilar archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Crear directorio de objetos
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilar libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar minilibx
$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Limpiar archivos objeto
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

# Limpiar todo
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

# Recompilar todo
re: fclean all

# Reglas que no son archivos
.PHONY: all clean fclean re
