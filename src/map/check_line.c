#include "../../include/so_long.h"

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

static t_bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == '\n');
}

static size_t	line_len(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	return (len);
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
