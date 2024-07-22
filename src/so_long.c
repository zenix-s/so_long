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

// static void	ft_hook(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->mlx);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
// 		ft_player_move(game, 'u', 5);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 		ft_player_move(game, 'd', 5);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		ft_player_move(game, 'l', 5);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		ft_player_move(game, 'r', 5);
// }

// void	init_map(t_game *game)
// {
// 	game->map = (t_map *)malloc(sizeof(t_map));
// 	if (game->map == NULL)
// 		ft_error("Failed to allocate memory for map structure");
// 	game->map->width = 0;
// 	game->map->height = 0;
// 	game->map->map = NULL;
// }

// void	init_map_width(t_game *game, char *line)
// {
// 	game->map->width = ft_strlen(line);
// 	if (game->map->width <= 2)
// 		ft_error("Invalid map file");
// 	ft_printf("Map width: %d\n", game->map->width);
// }

// void alloc_tiles(t_game *game)
// {
//     int total_tiles = game->map->width * game->map->height;
//     game->map->tiles = (t_tile **)malloc(sizeof(t_tile *) * total_tiles);
//     if (game->map->tiles == NULL)
//         ft_error("Failed to allocate memory for tiles");

//     for (int i = 0; i < total_tiles; i++)
// //     {
// //         game->map->tiles[i] = (t_tile *)malloc(sizeof(t_tile));
// //         if (game->map->tiles[i] == NULL)
// //             ft_error("Failed to allocate memory for tile");

// //         game->map->tiles[i]->img = mlx_new_image(game->mlx, TILE_SIZE,
// 		// TILE_SIZE);
// 		//         if (game->map->tiles[i]->img == NULL)
// 		//             ft_error("Failed to create tile image");
// 		//     }
// 		// }

// 		// void	init_tile(t_tile **tile)
// 		// {
// 		// 	*tile = (t_tile *)malloc(sizeof(t_tile));
// 		// 	if (*tile == NULL)
// 		// 		ft_error("Failed to allocate memory for tile");
// 		// }

// 		// void	init_tile_img(t_tile *tile, t_game *game)
// 		// {
// 		// 	tile->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
// 		// 	if (tile->img == NULL)
// 		// 		ft_error("Failed to create tile image");
// 		// }

// 		// void	draw_green_tile(t_tile *tile)
// 		// {
// 		// 	int	i;
// 		// 	int	j;

// 		// 	i = 0;
// 		// 	while (i < TILE_SIZE)
// 		// 	{
// 		// 		j = 0;
// 		// 		while (j < TILE_SIZE)
// 		// 		{
// 		// 			mlx_put_pixel(tile->img, i, j, 0x00FF00FF);
// 		// 			j++;
// 		// 		}
// 		// 		i++;
// 		// 	}
// 		// }

// 		// void	draw_blue_tile(t_tile *tile)
// 		// {
// 		// 	int	i;
// 		// 	int	j;

// 		// 	i = 0;
// 		// 	while (i < TILE_SIZE)
// 		// 	{
// 		// 		j = 0;
// 		// 		while (j < TILE_SIZE)
// 		// 		{
// 		// 			mlx_put_pixel(tile->img, i, j, 0x0000FFFF);
// 		// 			j++;
// 		// 		}
// 		// 		i++;
// 		// 	}
// 		// }

// 		// void	draw_yellow_tile(t_tile *tile)
// 		// {
// 		// 	int	i;
// 		// 	int	j;

// 		// 	i = 0;
// 		// 	while (i < TILE_SIZE)
// 		// 	{
// 		// 		j = 0;
// 		// 		while (j < TILE_SIZE)
// 		// 		{
// 		// 			mlx_put_pixel(tile->img, i, j, 0xF0F000FF);
// 		// 			j++;
// 		// 		}
// 		// 		i++;
// 		// 	}
// 		// }

// 		// void	draw_yellow_triangle_tile(t_tile *tile)
// 		// {
// 		// 	int	i;
// 		// 	int	j;

// 		// 	i = 0;
// 		// 	while (i < TILE_SIZE)
// 		// 	{
// 		// 		j = 0;
// 		// 		while (j < TILE_SIZE)
// 		// 		{
// 		// 			if (i + j < TILE_SIZE)
// 		// 				mlx_put_pixel(tile->img, i, j, 0xF0F00FFF);
// 		// 			j++;
// 		// 		}
// 		// 		i++;
// 		// 	}
// 		// }

// 		// void	load_map(t_game *game)
// 		// {
// 		// 	size_t	x;
// 		// 	size_t	y;

// 		// 	alloc_tiles(game);
// 		// 	y = 0;
// 		// 	while (y < game->map->height)
// 		// 	{
// 		// 		x = 0;
// 		// 		while (x < game->map->width)
// 		// 		{
// 		// 			if (game->map->map[y][x] == '\n')
// 		// 			{
// 		// 				x++;
// 		// 				continue ;
// 		// 			}
// 		// 			init_tile(&game->map->tiles[y * game->map->width + x]);
// 		// 			init_tile_img(game->map->tiles[y * game->map->width + x],
// 						game);
// 		// 			mlx_image_to_window(game->mlx, game->map->tiles[y
// 						* game->map->width
// 		// 				+ x]->img, x * TILE_SIZE, y * TILE_SIZE);
// 		// 			if (game->map->map[y][x] == '0')
// 		// 				draw_green_tile(game->map->tiles[y * game->map->width
// 							+ x]);
// 		// 			else if (game->map->map[y][x] == '1')
// 		// 				draw_blue_tile(game->map->tiles[y * game->map->width
// 							+ x]);
// 		// 			else if (game->map->map[y][x] == 'C')
// 		// 			{
// 		// 				draw_green_tile(game->map->tiles[y * game->map->width
// 							+ x]);
// 		// 				game->map->n_collectibles++;
// 		// 			}
// 		// 			else if (game->map->map[y][x] == 'E')
// 		// 				draw_yellow_tile(game->map->tiles[y * game->map->width
// 							+ x]);
// 		// 			else if (game->map->map[y][x] == 'P')
// 		// 			{
// 		// 				draw_green_tile(game->map->tiles[y * game->map->width
// 							+ x]);
// 		// 			}
// 		// 			x++;
// 		// 		}
// 		// 		y++;
// 		// 	}
// 		// }

// 		// void	draw_collectible(t_collectible *collectible)
// 		// {
// 		// 	int	i;
// 		// 	int	j;

// 		// 	i = 0;
// 		// 	while (i < TILE_SIZE)
// 		// 	{
// 		// 		j = 0;
// 		// 		while (j < TILE_SIZE)
// 		// 		{
// 		// 			if (i + j < TILE_SIZE)
// 		// 				mlx_put_pixel(collectible->img, i, j, 0xF0F00FFF);
// 		// 			j++;
// 		// 		}
// 		// 		i++;
// 		// 	}
// 		// }

// 		// void	alloc_collectibles(t_game *game)
// 		// {
// 		// 	game->map->collectibles = (t_collectible **)malloc(sizeof(t_collectible *)
// 		// 			* game->map->n_collectibles);
// 		// 	if (game->map->collectibles == NULL)
// 		// 		ft_error("Failed to allocate memory for collectibles");
// 		// }

// 		// void	init_collectible(t_collectible **collectible)
// 		// {
// 		// 	*collectible = (t_collectible *)malloc(sizeof(t_collectible));
// 		// 	if (*collectible == NULL)
// 		// 		ft_error("Failed to allocate memory for collectible");
// 		// }

// 		// void	init_collectible_img(t_collectible *collectible, t_game *game)
// 		// {
// 		// 	collectible->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
// 		// 	if (collectible->img == NULL)
// 		// 		ft_error("Failed to create image for collectible");
// 		// }

// 		// void	load_collectibles(t_game *game)
// 		// {
// 		// 	size_t	x;
// 		// 	size_t	y;
// 		// 	size_t	i;

// 		// 	alloc_collectibles(game);
// 		// 	y = 0;
// 		// 	i = 0;
// 		// 	while (y < game->map->height)
// 		// 	{
// 		// 		x = 0;
// 		// 		while (x < game->map->width)
// 		// 		{
// 		// 			if (game->map->map[y][x] == 'C')
// 		// 			{
// 		// 				init_collectible(&game->map->collectibles[i]);
// 		// 				init_collectible_img(game->map->collectibles[i], game);
// 		// 				draw_collectible(game->map->collectibles[i]);
// 		// 				mlx_image_to_window(game->mlx,
// 							game->map->collectibles[i]->img,
// 		// 					x * TILE_SIZE, y * TILE_SIZE);
// 		// 				i++;
// 		// 			}
// 		// 			x++;
// 		// 		}
// 		// 		y++;
// 		// 	}
// 		// }
// 		// void draw_map(t_game *game)
// 		// {
// 		//     for (size_t y = 0; y < game->map->height; y++)
// 		//     {
// 		//         for (size_t x = 0; x < game->map->width; x++)
// 		//         {
// 		//             t_tile *tile = game->map->tiles[y * game->map->width
// 			+ x];
// 		//             char tile_type = game->map->map[y][x];
// 		//             if (tile_type == '0')
// 		//                 draw_green_tile(tile);
// 		//             else if (tile_type == '1')
// 		//                 draw_blue_tile(tile);
// 		//             else if (tile_type == 'C')
// 		//             {
// 		//                 draw_green_tile(tile);
// 		//                 game->map->n_collectibles++;
// 		//             }
// 		//             else if (tile_type == 'E')
// 		//                 draw_yellow_tile(tile);
// 		//             else if (tile_type == 'P')
// 		//                 draw_green_tile(tile);

// 		//             mlx_image_to_window(game->mlx, tile->img, x * TILE_SIZE,
// 			y
// 	* TILE_SIZE);
// 	//         }
// 	//     }
// 	// }
// 	// // void	load_textures(t_game *game)
// 	// // {
// 	// // 	game->textures = (t_texture *)malloc(sizeof(t_texture) * 5);
// 	// // 	if (game->textures == NULL)
// 	// // 		ft_error("Failed to allocate memory for textures");
// 	// // 	game->textures[0].img = mlx_xpm_file_to_image(game->mlx,
// 	// "textures/wall.xpm",
// 	// 	// 			&game->textures[0].width, &game->textures[0].height);
// 	// 	// 	game->textures[1].img = mlx_xpm_file_to_image(game->mlx,
// 	// 	"textures/floor.xpm",
// 	// 	// 			&game->textures[1].width, &game->textures[1].height);
// 	// 	// 	game->textures[2].img = mlx_xpm_file_to_image(game->mlx,
// 	// 	"textures/collectible.xpm",
// 	// 	// 			&game->textures[2].width, &game->textures[2].height);
// 	// 	// 	game->textures[3].img = mlx_xpm_file_to_image(game->mlx,
// 	// 	"textures/exit.xpm",
// 	// 	// 			&game->textures[3].width, &game->textures[3].height);
// 	// 	// 	game->textures[4].img = mlx_xpm_file_to_image(game->mlx,
// 	// 	"textures/player.xpm",
// 	// 	// 			&game->textures[4].width, &game->textures[4].height);
// 	// 	// 	if (game->textures[0].img == NULL || game->textures[1].img == NULL
// 	// 	// 		|| game->textures[2].img == NULL
// 					|| game->textures[3].img == NULL
// 	// 	// 		|| game->textures[4].img == NULL)
// 	// 	// 		ft_error("Failed to load textures");
// 	// 	// }
// 	// 	//

// 	// 	// if player is on a tile, draw 0 (floor) white
// 	// 	// if collectible is on a tile, draw 0 (floor) white
// 	// 	// if exit blue
// 	// 	// if wall red

// 	// int main(int argc, char **argv)
// 	// {
// 	//     if (argc != 2)
// 	//         ft_error("Usage: ./so_long [map.ber]");

// 	//     t_game *game;
// 	//     init_game(&game);
// 	//     parse_map(game, argv);
// 	//     print_map(game);

// 	//     mlx_set_setting(MLX_MAXIMIZED, false);
// 	//     game->mlx = mlx_init(game->map->width * TILE_SIZE, game->map->height
// 		* TILE_SIZE, "so_long", true);
// 		//     if (game->mlx == NULL)
// 		//         ft_error("Failed to initialize MLX");

// 		//     alloc_tiles(game);
// 		//     draw_map(game);
// 		//     load_collectibles(game);
// 		//     init_player(game);
// 		//     mlx_loop_hook(game->mlx, ft_hook, game);
// 		//     mlx_loop(game->mlx);
// 		//     mlx_terminate(game->mlx);
// 		//     free(game);
// 		//     return (EXIT_SUCCESS);
// 		// }

// 		// int	main(int argc, char **argv)
// 		// {
// 		// 	t_game	*game;

// 		// 	if (argc != 2)
// 		// 		ft_error("Usage: ./so_long [map.ber]");
// 		// 	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
// 		// 		ft_error("Invalid map file");
// 		// 	game = (t_game *)malloc(sizeof(t_game));
// 		// 	if (game == NULL)
// 		// 		ft_error("Failed to allocate memory for game structure");
// 		// 	parse_map(game, argv);
// 		// 	print_map(game);
// 		// 	mlx_set_setting(MLX_MAXIMIZED, false);
// 		// 	game->mlx = mlx_init(game->map->width * TILE_SIZE, game->map->height
// 		// 			* TILE_SIZE, "so_long", true);
// 		// 	if (game->mlx == NULL)
// 		// 		ft_error("Failed to initialize MLX");
// 		// 	// load_tiles(game);
// 		// 	load_map(game);
// 		// 	load_collectibles(game);
// 		// 	init_player(game);
// 		// 	mlx_loop_hook(game->mlx, ft_hook, game);
// 		// 	mlx_loop(game->mlx);
// 		// 	mlx_terminate(game->mlx);
// 		// 	free(game);
// 		// 	return (EXIT_SUCCESS);
// 		// }

// INIT GAME STRUCTURE
void	init_game(t_game **game)
{
	*game = (t_game *)malloc(sizeof(t_game));
	if (*game == NULL)
		ft_error("Failed to allocate memory for game structure");
	(*game)->map = (t_map *)malloc(sizeof(t_map));
	if ((*game)->map == NULL)
		ft_error("Failed to allocate memory for map structure");
	(*game)->map->width = 0;
	(*game)->map->height = 0;
	(*game)->map->map = NULL;
	(*game)->map->tiles = NULL;
	(*game)->map->collectibles = NULL;
	(*game)->map->n_collectibles = 0;
	(*game)->player = NULL;
}

// MAP PARSING FUNCTIONS
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

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Failed to open map file");
	game->map->height = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (game->map->height == 0)
			game->map->width = ft_strlen(line);
		game->map->height++;
		check_line(game, line);
		alloc_map(game, &line);
	}
	if (game->map->height == 0)
		ft_error("Empty map file");
	close(fd);
}

// PRINT MAP

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

// INIT TILE

t_bool	init_tile(t_tile **tile, char type, t_game *game, size_t x, size_t y)
{
	*tile = (t_tile *)malloc(sizeof(t_tile));
	if (*tile == NULL)
		return (false);
	(*tile)->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if ((*tile)->img == NULL)
		return (false);
	(*tile)->type = type;
	(*tile)->x = x;
	(*tile)->y = y;
	return (true);
}

// INIT TILESET
t_bool	if_floor(char type)
{
	if (type == '0' || type == 'P' || type == 'E' || type == 'C')
		return (true);
	return (false);
}
void	init_tileset(t_game *game)
{
	size_t	x;
	size_t	y;

	game->map->tiles = (t_tile **)malloc(sizeof(t_tile *) * (game->map->height
				* game->map->width));
	if (game->map->tiles == NULL)
		ft_error("Failed to allocate memory for tileset");
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (if_floor(game->map->map[y][x]))
				init_tile(&game->map->tiles[y * game->map->width + x], '0',
					game, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->map[y][x] == '1')
				init_tile(&game->map->tiles[y * game->map->width + x], '1',
					game, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map->map[y][x] == '\n')
			{
				x++;
				continue ;
			}
			x++;
		}
		y++;
	}
}

// INIT COLLECTIBLE

// INIT COLLECTIBLESET

// INIT PLAYER

// MAIN FUNCTION
int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error("Usage: ./so_long [map.ber]");
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		ft_error("Invalid map file");
	init_game(&game);
	parse_map(game, argv);
}
