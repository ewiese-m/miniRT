# Library name
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Header file
HEADER = libft.h

# Source files - Basic libft functions
SRCS_BASIC = ft_isalpha.c \
			 ft_isdigit.c \
			 ft_isalnum.c \
			 ft_isascii.c \
			 ft_isprint.c \
			 ft_toupper.c \
			 ft_tolower.c \
			 ft_isspace.c \
			 ft_strlen.c \
			 ft_memset.c \
			 ft_bzero.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_strlcpy.c \
			 ft_strlcat.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_strncmp.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_strnstr.c \
			 ft_atoi.c \
			 ft_calloc.c \
			 ft_strdup.c \
			 ft_substr.c \
			 ft_strjoin.c \
			 ft_strtrim.c \
			 ft_split.c \
			 ft_itoa.c \
			 ft_strmapi.c \
			 ft_striteri.c \
			 ft_putchar_fd.c \
			 ft_putstr_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_strcmp.c \
			 ft_strcpy.c \
			 ft_strcat.c \
			 ft_atoll.c

# Bonus functions (linked lists)
SRCS_BONUS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c

# Get_next_line functions
SRCS_GNL = get_next_line.c \
		   get_next_line_utils.c

# Garbage collector functions
SRCS_GC = gc_init.c \
		  gc_malloc.c \
		  gc_add.c \
		  gc_remove.c \
		  gc_free.c \
		  gc_free_all.c \
		  gc_track_fd.c \
		  gc_close_fd.c \
		  gc_close_all_fds.c \
		  gc_memory_wrappers.c

# Extra utility functions
SRCS_EXTRA = ft_exit.c \
			 ft_args_check.c \
			 ft_ext_file_check.c \
			 ft_file_check_path.c \
			 ft_free_2d_list.c \
			 ft_error.c \
			 ft_tablen.c \
			 ft_isfloat.c \
			 ft_atof.c \
			 ft_pow.c \
			 ft_isint.c

# All source files
SRCS = $(SRCS_BASIC) $(SRCS_BONUS) $(SRCS_GNL) $(SRCS_GC) $(SRCS_EXTRA)
SRCS_ALL = $(SRCS) $(SRCS_BONUS)

# Object files
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m # No Color

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	@echo "$(YELLOW)Creating libft.a...$(NC)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ libft.a created successfully!$(NC)"

# Compile object files
%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Removing object files...$(NC)"
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$(GREEN)✓ Object files removed!$(NC)"

# Full clean (remove library too)
fclean: clean
	@echo "$(RED)Removing libft.a...$(NC)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ libft.a removed!$(NC)"

# Rebuild everything
re: fclean all
	@echo "$(GREEN)✓ libft.a rebuilt successfully!$(NC)"

# Install readline (for systems that need it)
install:
	@echo "$(YELLOW)Installing readline library...$(NC)"
	@sudo apt-get update && sudo apt-get install -y libreadline-dev
	@echo "$(GREEN)✓ Readline library installed!$(NC)"

# Test compilation (compile a test program)
test: $(NAME)
	@echo "$(YELLOW)Testing libft compilation...$(NC)"
	@echo "#include \"libft.h\"\nint main(){ft_putstr_fd(\"Test OK!\\n\", 1);return 0;}" > test.c
	@$(CC) $(CFLAGS) test.c -L. -lft -lreadline -o test_program
	@./test_program
	@$(RM) test.c test_program
	@echo "$(GREEN)✓ Test passed!$(NC)"

# Debug version with -g flag
debug: CFLAGS += -g
debug: re
	@echo "$(GREEN)✓ Debug version created!$(NC)"

# Show help
help:
	@echo "$(GREEN)Available targets:$(NC)"
	@echo "  all      - Build the library"
	@echo "  bonus    - Build the library with bonus functions"
	@echo "  clean    - Remove object files"
	@echo "  fclean   - Remove object files and library"
	@echo "  re       - Rebuild everything"
	@echo "  install  - Install readline library"
	@echo "  test     - Test compilation"
	@echo "  debug    - Build with debug flags"
	@echo "  help     - Show this help"

# Declare phony targets
.PHONY: all clean fclean re bonus install test debug help
