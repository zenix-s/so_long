#include "../../include/so_long.h"

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

t_bool	check_line(t_game *game, char *line)
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
		i++;
	}
	return (TRUE);
}
