# Nombre del compilador
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft -L./minilibx-linux -lmlx -lX11 -lXext -lm
INCLUDE = -I./includes -I./libft

# Directories
OBJ_DIR = obj
SRC_DIR = src
INCLUDES_DIR = includes
LIBFT_DIR = libft

SRCS = $(SRC_DIR)/main.c

# Archivos fuente

# Archivos objeto
OBJ = $(SRC:.c=.o)

# Flags para la compilación


# Nombre del programa
NAME = miniRT

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
