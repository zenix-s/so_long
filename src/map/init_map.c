#include "../../include/so_long.h"

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
	int		fd;
	char	*line;

	// ft_printf("Allocating memory for map\n");
	if (!alloc_map(game))
		return (ft_error("Failed to allocate memory\n"), FALSE);
	// ft_printf("Opening map file\n");
	fd = open(file_path[1], O_RDONLY);
	if (fd <= 1)
		return (ft_error("Failed to open map file\n"), FALSE);
	game->map->height = 0;
	line = NULL;
	// ft_printf("Reading map file\n");
	while (get_next_line(fd, &line) > 0)
	{
		// ft_printf("Checking line: %s\n", line);
		if (!check_line(game, line))
			return (FALSE);
		// ft_printf("Allocating memory for layout\n");
		if (!alloc_layout(game, &line))
			return (FALSE);
		game->map->height++;
	}
	// ft_printf("Closing map file\n");
	// ft_printf("Map width: %d\n", (int)game->map->width);
	// ft_printf("Map height: %d\n", (int)game->map->height);
	close(fd);
	return (TRUE);
}
