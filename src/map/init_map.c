#include "../../include/so_long.h"

// Check if the map is valid
// Valid characters: '1', '0', 'P', 'E', 'C'
// 'P' and 'E' must appear exactly once
// 'C' must appear at least once
// '1' must be the border of the map
// All 'C' must be reachable from 'P'

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
	if (!valid_map(game, &validate_map))
		return (FALSE);
	return (TRUE);
}
