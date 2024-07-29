#include "../../include/so_long.h"

// Check if the map is valid
// Valid characters: '1', '0', 'P', 'E', 'C'
// 'P' and 'E' must appear exactly once
// 'C' must appear at least once
// '1' must be the border of the map
// All 'C' must be reachable from 'P'

typedef struct s_validate_map
{
	t_bool		player;
	t_bool		exit;
	t_bool		collectible;
}				t_validate_map;

t_bool			check_line(t_game *game, char *line,
					t_validate_map *validate_map);

t_bool	check_border(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (y == 0 || y == game->map->height - 1)
			{
				if (game->map->layout[y][x] != '1')
					return (ft_error("Invalid map file"), FALSE);
			}
			else if (x == 0 || x == game->map->width - 1)
			{
				if (game->map->layout[y][x] != '1')
					return (ft_error("Invalid map file"), FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}
t_bool	alloc_layout(t_game *game, char **line)
{
	char	**new_layout;
	size_t	i;

	new_layout = (char **)malloc(sizeof(char *) * (game->map->height + 1));
	if (new_layout == NULL)
		return (ft_error("Failed to allocate memory for map"), FALSE);
	i = 0;
	while (i < game->map->height)
	{
		new_layout[i] = game->map->layout[i];
		i++;
	}
	new_layout[i] = *line;
	if (game->map->layout != NULL)
		free(game->map->layout);
	game->map->layout = new_layout;
	return (TRUE);
}

void	init_validate_map(t_validate_map *validate_map)
{
	validate_map->player = FALSE;
	validate_map->exit = FALSE;
	validate_map->collectible = FALSE;
}

t_bool	init_map(t_game *game, char **file_path)
{
	int				fd;
	char			*line;
	t_validate_map	validate_map;

	if (!alloc_map(game))
		return (ft_error("Failed to allocate memory\n"), FALSE);
	fd = open(file_path[1], O_RDONLY);
	if (fd <= 1)
		return (ft_error("Failed to open map file\n"), FALSE);
	init_validate_map(&validate_map);
	game->map->height = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_line(game, line, &validate_map))
			return (FALSE);
		if (!alloc_layout(game, &line))
			return (FALSE);
		game->map->height++;
	}
	close(fd);
	if (!check_border(game))
		return (FALSE);
	return (TRUE);
}

static size_t	line_len(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	return (len);
}

static t_bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == '\n');
}

t_bool	found_player(t_validate_map *validate_map)
{
	if (validate_map->player)
		return (ft_error("Player must appear exactly once"), TRUE);
	validate_map->player = TRUE;
	return (FALSE);
}

t_bool	found_exit(t_validate_map *validate_map)
{
	if (validate_map->exit)
		return (ft_error("Exit must appear exactly once"), TRUE);
	validate_map->exit = TRUE;
	return (FALSE);
}

t_bool	check_line(t_game *game, char *line, t_validate_map *validate_map)
{
	size_t	i;

	if (game->map->height == 0)
	{
		game->map->width = line_len(line);
		if (game->map->width <= 2)
			return (ft_error("Invalid map file"), FALSE);
	}
	else if (game->map->width != line_len(line))
		return (ft_error("Invalid map file"), FALSE);
	i = 0;
	while (line[i])
	{
		if (!is_valid_char(line[i]))
			return (ft_error("Invalid map file"), FALSE);
		if (line[i] == 'P' && found_player(validate_map))
			return (FALSE);
		else if (line[i] == 'E' && found_exit(validate_map))
			return (FALSE);
		else if (line[i] == 'C')
			validate_map->collectible = TRUE;
		i++;
	}
	return (TRUE);
}
