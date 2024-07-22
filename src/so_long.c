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

void ft_player_move(t_game *game, char direction, int total);

// HOOK
static void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		ft_player_move(game, 'u', 32);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		ft_player_move(game, 'd', 32);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_player_move(game, 'l', 32);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_player_move(game, 'r', 32);
}

// DRAW
void	draw_green_tile(t_tile *tile)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(tile->img, x, y, 0x00FF00FF);
			x++;
		}
		y++;
	}
}

void	draw_red_tile(t_tile *tile)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(tile->img, x, y, 0xFF0000FF);
			x++;
		}
		y++;
	}
}

void	draw_blue_tile(t_tile *tile)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(tile->img, x, y, 0x0000FFFF);
			x++;
		}
		y++;
	}
}

void	draw_white_tile(t_tile *tile)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(tile->img, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_collectible(t_collectible *collectible)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (i + j < TILE_SIZE)
				mlx_put_pixel(collectible->img, i, j, 0xF0F00FFF);
			j++;
		}
		i++;
	}
}

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
t_bool	is_floor(char type)
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
			if (is_floor(game->map->map[y][x]))
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
	game->map->n_tiles = game->map->height * game->map->width;
}

// INIT COLLECTIBLE
t_bool	init_collectible(t_collectible **collectible, t_game *game, size_t x,
		size_t y)
{
	*collectible = (t_collectible *)malloc(sizeof(t_collectible));
	if (*collectible == NULL)
		return (false);
	(*collectible)->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if ((*collectible)->img == NULL)
		return (false);
	(*collectible)->x = x;
	(*collectible)->y = y;
	return (true);
}

// INIT COLLECTIBLESET

void	init_collectibles(t_game *game)
{
	size_t	x;
	size_t	y;

	game->map->collectibles = (t_collectible **)malloc(sizeof(t_collectible *)
			* game->map->n_collectibles);
	if (game->map->collectibles == NULL)
		ft_error("Failed to allocate memory for collectibles");
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'C')
			{
				init_collectible(&game->map->collectibles[game->map->n_collectibles],
					game, x * TILE_SIZE, y * TILE_SIZE);
				game->map->n_collectibles++;
			}
			x++;
		}
		y++;
	}
}

// PRINT_TILES
// mlx_image_to_window(mlx_t *mlx, mlx_image_t *img, int32_t x, int32_t y)
void	print_tiles(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map->n_tiles)
	{
		if (game->map->tiles[i] == NULL)
			{
				i++;
				continue ;
			}
		if (game->map->tiles[i]->type == '0')
		{
			mlx_image_to_window(game->mlx, game->map->tiles[i]->img,
				game->map->tiles[i]->x, game->map->tiles[i]->y);
			draw_white_tile(game->map->tiles[i]);
		}
		else if (game->map->tiles[i]->type == '1')
		{
			mlx_image_to_window(game->mlx, game->map->tiles[i]->img,
				game->map->tiles[i]->x, game->map->tiles[i]->y);
			draw_green_tile(game->map->tiles[i]);
		}
		i++;
	}
}

// PRINT_COLLECTIBLES
void	print_collectibles(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map->n_collectibles)
	{
		mlx_image_to_window(game->mlx, game->map->collectibles[i]->img,
			game->map->collectibles[i]->x, game->map->collectibles[i]->y);
		draw_collectible(game->map->collectibles[i]);
		i++;
	}
}

// INIT PLAYER
static void	draw_player(t_game *game)
{
	int	i;
	int	x;

	i = 0;
	while (i < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_put_pixel(game->player->img, x, i, 0xFF0000FF);
			x++;
		}
		i++;
	}
}

void	init_player(t_game *game)
{
	size_t	x;
	size_t	y;

	t_bool player_found = FALSE;
	game->player = (t_player *)malloc(sizeof(t_player));
	if (game->player == NULL)
		ft_error("Failed to allocate memory for player");
	game->player->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	if (game->player->img == NULL)
		ft_error("Failed to create player image");
	y = 0;
	x = 0;
	while (y < game->map->height && !player_found)
	{
		x = 0;
		while (x < game->map->width && !player_found)
		{
			if (game->map->map[y][x] == 'P')
			{
				game->map->map[y][x] = '0';
				player_found = TRUE;
			}
			else
				x++;
		}
		if (!player_found)
			y++;
	}
	if (!player_found)
		ft_error("Player starting position not found in the map");
	if (mlx_image_to_window(game->mlx, game->player->img, x * TILE_SIZE, y
			* TILE_SIZE) < 0)
		ft_error("Failed to display player image");
	draw_player(game);
}

int is_within_bounds(int new_x, int new_y, t_game *game)
{
    if (!game || !game->map) {
        printf("Error: game or game->map is NULL\n");
        return 0;
    }

    unsigned long map_width_in_pixels = game->map->width * TILE_SIZE;
    unsigned long map_height_in_pixels = game->map->height * TILE_SIZE;

    if (new_x < 0 || (unsigned int)new_x >= map_width_in_pixels ||
        new_y < 0 || (unsigned int)new_y >= map_height_in_pixels)
    {
        printf("Position out of bounds\n");
        return 0; // Out of bounds
    }
    return 1; // Within bounds
}

int is_walkable_tile(size_t new_x, size_t new_y, t_game *game)
{
    if (!game || !game->map || !game->map->tiles) {
        printf("Error: game or game->map or game->map->tiles is NULL\n");
        return 0;
    }

    size_t i = 0;
    while (i < (game->map->height * game->map->width))
    {
    			if (game->map->tiles[i] == NULL)
		{
			i++;
			continue;
		}
		if (game->map->tiles[i]->x == new_x && game->map->tiles[i]->y == new_y)
		{
			if (game->map->tiles[i]->type == '1')
			{
				printf("Wall found\n");
				return 0; // Wall found
			}
			return 1; // Walkable tile
		}
		i++;
    }
    printf("No matching tile found\n");
    return 0; // No matching tile found (should not happen)
}

void update_player_position(int new_x, int new_y, t_game *game)
{
    if (!game || !game->player || !game->player->img) {
        printf("Error: game or game->player or game->player->img is NULL\n");
        return;
    }

    game->player->img->instances[0].x = new_x;
    game->player->img->instances[0].y = new_y;
}
void ft_player_move(t_game *game, char direction, int total)
{
    if (!game || !game->player || !game->player->img) {
        printf("Error: game or game->player or game->player->img is NULL\n");
        return;
    }

    int new_x = game->player->img->instances[0].x;
    int new_y = game->player->img->instances[0].y;

    // Determine new position based on direction
    if (direction == 'u')
        new_y -= total;
    else if (direction == 'd')
        new_y += total;
    else if (direction == 'l')
        new_x -= total;
    else if (direction == 'r')
        new_x += total;

    printf("New position: (%d, %d)\n", new_x, new_y);

    // Check if new position is within bounds and walkable
    if (is_walkable_tile(new_x, new_y, game))
    {
        update_player_position(new_x, new_y, game);
    }
}



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
	game->mlx = mlx_init(game->map->width * TILE_SIZE, game->map->height
			* TILE_SIZE, "so_long", true);
	init_tileset(game);
	init_collectibles(game);
	print_tiles(game);
	print_collectibles(game);
	init_player(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
