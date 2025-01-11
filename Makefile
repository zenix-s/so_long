#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#
NAME	= so_long

SRCS	=	./src/player/free_player.c \
			./src/player/hook/player_hook.c \
			./src/player/init_player.c \
			./src/player/player_movement.c \
			./src/player/render_player.c \
			./src/clean/end_game.c \
			./src/clean/end_mlx.c \
			./src/clean/free_game.c \
			./src/collectibles/collect_collectible.c \
			./src/collectibles/free_collectibles.c \
			./src/collectibles/init_collectibles.c \
			./src/collectibles/render_collectibles.c \
			./src/exit/free_exit.c \
			./src/exit/init_exit.c \
			./src/exit/open_exit.c \
			./src/exit/render_exit.c \
			./src/map/free_map.c \
			./src/map/init_map.c \
			./src/map/map_validation/check_border.c \
			./src/map/map_validation/is_valid_char.c \
			./src/map/map_validation/item_validation.c \
			./src/map/map_validation/line_validation.c \
			./src/map/map_validation/valid_items.c \
			./src/map/map_validation/validate_map.c \
			./src/map/path_validation/validate_path.c \
			./src/check_arguments.c \
			./src/init_game.c \
			./src/init_mlx.c \
			./src/map_render/free_map_render.c \
			./src/map_render/init_map_render.c \
			./src/map_render/render_map_render.c \
			./src/shared/collectibles/all_collected.c \
			./src/shared/ft_error.c \
			./src/shared/map/is_type/is_collectible.c \
			./src/shared/map/is_type/is_exit.c \
			./src/shared/map/is_type/is_floor.c \
			./src/shared/map/is_type/is_special.c \
			./src/shared/map/is_type/is_wall.c \
			./src/shared/map/print_layout.c \
			./src/shared/moves_text/update_text.c \
			./src/shared/utils/gen_rand.c \
			./src/so_long.c \

OBJS	= ${SRCS:.c=.o}

HEADERS	= -I ./include -I $(LIBMLX)/include

LIBFT_SRC = ./lib/libft
LIBMLX	= ./lib/MLX42
LIBS	= $(LIBMLX)/build/libmlx42.a $(LIBFT_SRC)/libft.a -ldl -lglfw -pthread -lm


CC = cc
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -g3
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
