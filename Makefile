NAME	= so_long

# DIRECTORIES
SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}

# Includes
HEADERS	= -I ./include -I $(LIBMLX)/include

# LIBRARIES

LIBFT_SRC = ./lib/libft

LIBMLX	= ./lib/MLX42

LIBS	= $(LIBMLX)/build/libmlx42.a $(LIBFT_SRC)/libft.a -ldl -lglfw -pthread -lm


# VARIABLES
CC = cc
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
RM = rm -rf


%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

libft:
	@$(MAKE) -s all -C $(LIBFT_SRC)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

all: libmlx libft $(NAME)

clean:
	@$(MAKE) -s clean -C $(LIBFT_SRC)
	@$(rm) $(OBJS)
	@$(rm) $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_SRC)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
.DEFAULT_GOAL = all