NAME		= miniRT

SRC_DIR		= srcs
OBJ_DIR		= .objs
INCL_DIR	= includes

LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

SRCS		= $(shell find ${SRC_DIR} -name "*.c" -type f)
OBJS		= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
HEADERS		= $(shell find ${INCL_DIR} -name "*.h" -type f 2>/dev/null)

LIBFT		= ${LIBFT_DIR}/libft.a
MLX_LIB		= ${MLX_DIR}/libmlx.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
DFLAGS		= -MMD -MF $(@:.o=.d)
IFLAGS		= -I${INCL_DIR} -I${LIBFT_DIR} -I${MLX_DIR}
LFLAGS		= -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lbsd

all: ${NAME}

${NAME}: ${LIBFT} ${MLX_LIB} ${OBJS}
	@${CC} ${OBJS} ${LIBFT} ${LFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${HEADERS} | ${OBJ_DIR}
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} ${DFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${LIBFT}:
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory

${MLX_LIB}:
	@${MAKE} -C ${MLX_DIR} --no-print-directory

clean:
	@${MAKE} -C ${LIBFT_DIR} clean --no-print-directory
	@${MAKE} -C ${MLX_DIR} clean --no-print-directory
	@rm -rf ${OBJ_DIR}

fclean: clean
	@${MAKE} -C ${LIBFT_DIR} fclean --no-print-directory
	@rm -f ${NAME}

re: fclean all

norm:
	@norminette ${SRC_DIR} ${INCL_DIR}

-include ${OBJS:.o=.d}

.PHONY: all clean fclean re norm
