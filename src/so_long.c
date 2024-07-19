#include "../include/so_long.h"
#include <fcntl.h>

// the map has to be constructed with 3 components: walls, collectibles,
// and free
// space.
// • The map can be composed of only these 5 characters:
// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.
// The map must contain 1 exit, at least 1 collectible,
// and 1 starting position to
// be valid.
// The map must be rectangular.
// • The map must be closed/surrounded by walls. If it’s not,
// the program must return
// an error.
// • You have to check if there’s a valid path in the map.
// • You must be able to parse any kind of map,
// as long as it respects the above rules

static void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		ft_player_move(game, 'u', 25);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		ft_player_move(game, 'd', 25);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_player_move(game, 'l', 25);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_player_move(game, 'r', 25);
}

void	init_map(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (game->map == NULL)
		ft_error("Failed to allocate memory for map structure");
	game->map->width = 0;
	game->map->height = 0;
	game->map->map = NULL;
}

void	init_map_width(t_game *game, char *line)
{
	game->map->width = ft_strlen(line);
	if (game->map->width <= 2)
		ft_error("Invalid map file");
	ft_printf("Map width: %d\n", game->map->width);
}

void	check_line(t_game *game, char *line)
{
	size_t	i;

	if (game->map->width != ft_strlen(line))
		ft_error("Invalid map file");
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' && line[i] != 'E'
			&& line[i] != '\n' && line[i] != 'P')
			ft_error("Invalid map file");
		i++;
	}
}

void	alloc_map(t_game *game, char **line)
{
	char	**new_map;
	size_t	i;

	new_map = (char **)malloc(sizeof(char *) * (game->map->height));
	if (new_map == NULL)
		ft_error("Failed to allocate memory for map");
	i = 0;
	while (i < game->map->height - 1)
	{
		new_map[i] = game->map->map[i];
		i++;
	}
	new_map[i] = *line;
	if (game->map->map != NULL)
		free(game->map->map);
	game->map->map = new_map;
}

void	parse_map(t_game *game, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	ft_printf("Parsing map file: %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Failed to open map file");
	init_map(game);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
			init_map_width(game, line);
		check_line(game, line);
		game->map->height++;
		alloc_map(game, &line);
		i++;
	}
	if (i == 0)
		ft_error("Empty map file");
	close(fd);
}

void	print_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			ft_printf("%c", game->map->map[y][x]);
			x++;
		}
		y++;
	}
}

void	load_map(t_game *game)
{
	size_t	x;
	size_t	y;
	int		i;
	int		j;
			mlx_image_t *tile;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == '\n')
				continue ;
			tile = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
			mlx_image_to_window(game->mlx, tile, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map->map[y][x] == '0' || game->map->map[y][x] == 'C'
				|| game->map->map[y][x] == 'P')
			{
				i = 0;
				while (i < TILE_SIZE)
				{
					j = 0;
					while (j < TILE_SIZE)
					{
						mlx_put_pixel(tile, i, j, 0x00FF00FF);
						j++;
					}
					i++;
				}
			}
			else if (game->map->map[y][x] == '1')
			{
				i = 0;
				while (i < TILE_SIZE)
				{
					j = 0;
					while (j < TILE_SIZE)
					{
						mlx_put_pixel(tile, i, j, 0x0000FFFF);
						j++;
					}
					i++;
				}
			}
			else if (game->map->map[y][x] == 'E')
			{
				i = 0;
				while (i < TILE_SIZE)
				{
					j = 0;
					while (j < TILE_SIZE)
					{
						mlx_put_pixel(tile, i, j, 0xF0F000FF);
						j++;
					}
					i++;
				}
			}
			x++;
		}
		y++;
	}
}

// void	alloc_tiles(t_game *game)
// {
// 	int	total_tiles;

// 	ft_printf("Allocating memory for tiles\n");
// 	total_tiles = game->map->width * game->map->height;
// 	game->map->tiles = (t_tile **)malloc(sizeof(t_tile *) * total_tiles);
// 	if (game->map->tiles == NULL)
// 		ft_error("Failed to allocate memory for tiles");
// }
// //
// void	init_tile(t_tile **tile)
// {
// 	*tile = (t_tile *)malloc(sizeof(t_tile));
// 	if (*tile == NULL)
// 		ft_error("Failed to allocate memory for tile");
// }

// // void	load_textures(t_game *game)
// // {
// // 	game->textures = (t_texture *)malloc(sizeof(t_texture) * 5);
// // 	if (game->textures == NULL)
// // 		ft_error("Failed to allocate memory for textures");
// // 	game->textures[0].img = mlx_xpm_file_to_image(game->mlx,
// "textures/wall.xpm",
// 	// 			&game->textures[0].width, &game->textures[0].height);
// 	// 	game->textures[1].img = mlx_xpm_file_to_image(game->mlx,
// 	"textures/floor.xpm",
// 	// 			&game->textures[1].width, &game->textures[1].height);
// 	// 	game->textures[2].img = mlx_xpm_file_to_image(game->mlx,
// 	"textures/collectible.xpm",
// 	// 			&game->textures[2].width, &game->textures[2].height);
// 	// 	game->textures[3].img = mlx_xpm_file_to_image(game->mlx,
// 	"textures/exit.xpm",
// 	// 			&game->textures[3].width, &game->textures[3].height);
// 	// 	game->textures[4].img = mlx_xpm_file_to_image(game->mlx,
// 	"textures/player.xpm",
// 	// 			&game->textures[4].width, &game->textures[4].height);
// 	// 	if (game->textures[0].img == NULL || game->textures[1].img == NULL
// 	// 		|| game->textures[2].img == NULL || game->textures[3].img == NULL
// 	// 		|| game->textures[4].img == NULL)
// 	// 		ft_error("Failed to load textures");
// 	// }
// 	//

// 	// if player is on a tile, draw 0 (floor) white
// 	// if collectible is on a tile, draw 0 (floor) white
// 	// if exit blue
// 	// if wall red

// void	draw_tile(t_game *game, int x, int y)
// {
// 	t_tile	*tile;
// 	int		i;
// 	int		j;

// 	tile = game->map->tiles[y * game->map->width + x];
// 	i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < TILE_SIZE)
// 		{
// 			if (tile->type == '1')
// 				mlx_put_pixel(tile->img, i, j, 0xFF0000);
// 			else if (tile->type == '0')
// 				mlx_put_pixel(tile->img, i, j, 0xFFFFFF);
// 			else if (tile->type == 'C')
// 				mlx_put_pixel(tile->img, i, j, 0xFFD700);
// 			else if (tile->type == 'E')
// 				mlx_put_pixel(tile->img, i, j, 0x0000FF);
// 			else if (tile->type == 'P')
// 				mlx_put_pixel(tile->img, i, j, 0x00FF00);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	load_tiles(t_game *game)
// {
// 	size_t	x;
// 	size_t	y;

// 	ft_printf("Loading tiles\n");
// 	// total tiles = game->map->width * game->map->height
// 	alloc_tiles(game);
// 	ft_printf("Allocated memory for tiles\n");

// 	y = 0;
// 	while (y < game->map->height)
// 	{
// 		ft_printf("Loading tiles for row %u\n", (unsigned int)y);
// 		x = 0;
// 		while (x < game->map->width)
// 		{
// 			ft_printf("Loading tile %u, %u\n", (unsigned int)x,
				(unsigned int)y);
// 			if (game->map->map[y][x] == '1')
// 				game->map->tiles[y * game->map->width + x]->type = '1';
// 			else if (game->map->map[y][x] == '0')
// 				game->map->tiles[y * game->map->width + x]->type = '0';
// 			else if (game->map->map[y][x] == 'C')
// 				game->map->tiles[y * game->map->width + x]->type = 'C';
// 			else if (game->map->map[y][x] == 'E')
// 				game->map->tiles[y * game->map->width + x]->type = 'E';
// 			else if (game->map->map[y][x] == 'P')
// 				game->map->tiles[y * game->map->width + x]->type = 'P';
// 			else if (game->map->map[y][x] == '\n')
// 			{
// 				ft_printf("Newline\n");
// 				continue ;
// 			}
// 			else
// 				ft_error("Invalid map");
// 			ft_printf("%c", game->map->tiles[y * game->map->width + x]->type);
// 			init_tile(&game->map->tiles[y * game->map->width + x]);
// 			game->map->tiles[y * game->map->width
// 				+ x]->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
// 			if (game->map->tiles[y * game->map->width + x]->img == NULL)
// 				ft_error("Failed to create tile image");
// 			if (mlx_image_to_window(game->mlx, game->map->tiles[y
// 					* game->map->width + x]->img, x * TILE_SIZE, y
// 					* TILE_SIZE) < 0)
// 				ft_error("Failed to draw tile");
// 			draw_tile(game, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error("Usage: ./so_long [map.ber]");
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		ft_error("Invalid map file");
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Failed to allocate memory for game structure");
	parse_map(game, argv);
	print_map(game);
	mlx_set_setting(MLX_MAXIMIZED, false);
	game->mlx = mlx_init(game->map->width, game->map->height, "so_long", true);
	if (game->mlx == NULL)
		ft_error("Failed to initialize MLX");
	// load_tiles(game);
	load_map(game);
	// int x = 0;
	// int y = 0;
	// mlx_image_t *img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	// mlx_image_to_window(game->mlx, img, 10, 10);
	// while (y < TILE_SIZE)
	// {
	// 	x = 0;
	// 	while (x < TILE_SIZE)
	// 	{
	// 		mlx_put_pixel(img, x, y, 0x00FF00FF);
	// 		x++;
	// 	}
	// 	y++;
	// }
	init_player(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
