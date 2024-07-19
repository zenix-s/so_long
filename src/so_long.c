#include "../include/so_long.h"
#include <fcntl.h>

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

void	realloc_map(t_game *game)
{
	char	**new_map;
	size_t	i;

	new_map = (char **)malloc(sizeof(char *) * (game->map->height + 1));
	if (new_map == NULL)
		ft_error("Failed to allocate memory for map");
	i = 0;
	while (i < game->map->height)
	{
		new_map[i] = game->map->map[i];
		i++;
	}
	free(game->map->map);
	game->map->map = new_map;
}

void	parse_map(t_game *game, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Failed to open map file");
	init_map(game);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
			game->map->width = ft_strlen(line);
		else if (game->map->width != ft_strlen(line))
			ft_error("Invalid map file");
		game->map->height++;
		if (game->map->height == 1)
		{
			game->map->map = (char **)malloc(sizeof(char *) * (game->map->height
						+ 1));
			if (game->map->map == NULL)
				ft_error("Failed to allocate memory for map");
		}
		else
			realloc_map(game);
		game->map->map[i] = ft_strdup(line);
		if (game->map->map[i] == NULL)
			ft_error("Failed to allocate memory for map");
		free(line);
		i++;
	}
	if (game->map->map != NULL)
		game->map->map[game->map->height] = NULL;
	close(fd);
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[i] != NULL)
	{
		ft_printf("%s\n", game->map->map[i]);
		i++;
	}
}

void	alloc_tiles(t_game *game)
{
	int	total_tiles;

	total_tiles = game->map->width * game->map->height;
	game->map->tiles = (t_tile *)malloc(sizeof(t_tile) * total_tiles);
	if (game->map->tiles == NULL)
		ft_error("Failed to allocate memory for tiles");
}

void	init_tile(t_tile **tile)
{
	*tile = (t_tile *)malloc(sizeof(t_tile));
	if (*tile == NULL)
		ft_error("Failed to allocate memory for tile");
}

void	load_tiles(t_game *game)
{
	// total tiles = game->map->width * game->map->height
	int x;
	int y;

	alloc_tiles(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			init_tile(&(game->map->tiles[y * game->map->width + x]));
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error("Usage: ./so_long [map.ber]");
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
		ft_error("Invalid map file");
	game = (t_game *)malloc(sizeof(t_game));
	parse_map(game, argv);
	print_map(game);
	if (game == NULL)
		ft_error("Failed to allocate memory for game structure");
	mlx_set_setting(MLX_MAXIMIZED, false);
	game->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (game->mlx == NULL)
		ft_error("Failed to initialize MLX");
	init_player(game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
