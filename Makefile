#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#
NAME	= so_long

SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}

HEADERS	= -I ./include -I $(LIBMLX)/include

LIBFT_SRC = ./lib/libft
LIBMLX	= ./lib/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a $(LIBFT_SRC)/libft.a -ldl -lglfw -pthread -lm


CC = cc
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
RM = rm -rf

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#
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
	@$(RM) $(OBJS)
	@$(RM) $(LIBMLX)/build

fclean: clean
	@$(RM)  $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_SRC)

re: clean all

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#
.PHONY: all, clean, fclean, re, libmlx, libft
.DEFAULT_GOAL = all
