# ===== PROGRAM NAME =====
NAME		:= miniRT

# ===== DIRECTORIES =====
SRC_DIR		:= srcs
OBJ_DIR		:= .objs
INCL_DIR	:= includes

# ===== LIBRARY DIRECTORIES =====
LIBFT_DIR	:= libft
MLX_DIR		:= minilibx-linux

# ===== SOURCE FILES =====
# Automatically find all .c files in srcs directory
SRCS		:= $(shell find ${SRC_DIR} -name "*.c" -type f)

# ===== OBJECT FILES =====
OBJS		:= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

# ===== HEADER FILES =====
# Automatically find all .h files in includes directory
HEADERS		:= $(shell find ${INCL_DIR} -name "*.h" -type f 2>/dev/null)

# ===== LIBRARIES =====
LIBFT		:= ${LIBFT_DIR}/libft.a
MLX_LIB		:= ${MLX_DIR}/libmlx.a

# ===== COMPILER AND FLAGS =====
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
DFLAGS		:= -MMD -MF $(@:.o=.d)

# ===== INCLUDE PATHS =====
IFLAGS		:= -I${INCL_DIR} \
			   -I${LIBFT_DIR}/includes \
			   -I${MLX_DIR}

# ===== SYSTEM DETECTION =====
UNAME		:= $(shell uname)

# ===== LINKING FLAGS =====
ifeq ($(UNAME), Darwin)
	# macOS
	LFLAGS	:= -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	LFLAGS	:= -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lbsd
else
	# Linux and others
	LFLAGS	:= -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lbsd
endif

# ===== COLORS =====
RED			:= \033[0;31m
GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
BLUE		:= \033[0;34m
PURPLE		:= \033[0;35m
CYAN		:= \033[0;36m
WHITE		:= \033[0;37m
RESET		:= \033[0m

# ===== MAIN TARGETS =====
all: ${NAME}

${NAME}: ${LIBFT} ${MLX_LIB} ${OBJS}
	@echo "${CYAN}Linking ${NAME}...${RESET}"
	@${CC} ${OBJS} ${LIBFT} ${LFLAGS} -o ${NAME}
	@echo "${GREEN}✅ ${NAME} compiled successfully!${RESET}"

# ===== OBJECT COMPILATION =====
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${HEADERS} | ${OBJ_DIR}
	@mkdir -p ${@D}
	@printf "${YELLOW}Compiling: %-50s${RESET}\r" ${<F}
	@${CC} ${CFLAGS} ${DFLAGS} ${IFLAGS} -c $< -o $@

# ===== DIRECTORY CREATION =====
${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

# ===== LIBRARY COMPILATION =====
${LIBFT}:
	@echo "${PURPLE}Building libft...${RESET}"
	@${MAKE} -C ${LIBFT_DIR} --no-print-directory

${MLX_LIB}:
	@echo "${PURPLE}Building minilibx...${RESET}"
	@${MAKE} -C ${MLX_DIR} --no-print-directory

# ===== CLEANUP TARGETS =====
clean:
	@echo "${RED}Cleaning object files...${RESET}"
	@${MAKE} -C ${LIBFT_DIR} clean --no-print-directory
	@${MAKE} -C ${MLX_DIR} clean --no-print-directory
	@rm -rf ${OBJ_DIR}

fclean: clean
	@echo "${RED}Full clean...${RESET}"
	@${MAKE} -C ${LIBFT_DIR} fclean --no-print-directory
	@rm -f ${NAME}

re: fclean all

# ===== UTILITY TARGETS =====
norm:
	@echo "${BLUE}Running norminette...${RESET}"
	@norminette ${SRC_DIR} ${INCL_DIR}

debug: CFLAGS += -DDEBUG -fsanitize=address
debug: ${NAME}

show:
	@echo "${CYAN}=== PROJECT CONFIGURATION ===${RESET}"
	@echo "${YELLOW}NAME:${RESET}      ${NAME}"
	@echo "${YELLOW}CC:${RESET}        ${CC}"
	@echo "${YELLOW}CFLAGS:${RESET}    ${CFLAGS}"
	@echo "${YELLOW}IFLAGS:${RESET}    ${IFLAGS}"
	@echo "${YELLOW}LFLAGS:${RESET}    ${LFLAGS}"
	@echo "${YELLOW}UNAME:${RESET}     ${UNAME}"
	@echo "${YELLOW}SRCS:${RESET}      ${words ${SRCS}} files"
	@echo "${YELLOW}OBJS:${RESET}      ${words ${OBJS}} files"
	@echo "${YELLOW}HEADERS:${RESET}   ${words ${HEADERS}} files"
	@echo ""
	@echo "${BLUE}=== SOURCE FILES ===${RESET}"
	@echo "${SRCS}" | tr ' ' '\n' | sort
	@echo ""
	@echo "${BLUE}=== HEADER FILES ===${RESET}"
	@echo "${HEADERS}" | tr ' ' '\n' | sort

# ===== DEPENDENCY MANAGEMENT =====
-include ${OBJS:.o=.d}

# ===== PHONY TARGETS =====
.PHONY: all clean fclean re norm debug show
