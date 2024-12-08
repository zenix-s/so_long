/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:31 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/map.h"
#include "../../include/map/map_private.h"

static t_bool	alloc_map(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (game->map == NULL)
		return (FALSE);
	game->map->layout = NULL;
	game->map->height = 0;
	game->map->width = 0;
	game->map->player = NULL;
	game->map->exit = NULL;
	game->map->collectibles = NULL;
	game->map->n_collectibles = 0;
	return (TRUE);
}

static t_bool	re_alloc_layout(t_game *game, t_map_node_item ****new_layout)
{
	int32_t	i;

	*new_layout = malloc(sizeof(t_map_node_item **) * (game->map->height + 1));
	if (*new_layout == NULL)
		return (ft_error("Failed to allocate memory for map"), FALSE);
	i = -1;
	while (++i < game->map->height)
		(*new_layout)[i] = game->map->layout[i];
	(*new_layout)[i] = malloc(sizeof(t_map_node_item *) * game->map->width);
	if ((*new_layout)[i] == NULL)
	{
		free(*new_layout);
		return (ft_error("Failed to allocate memory for map"), FALSE);
	}
	return (TRUE);
}

static t_bool	init_item(
	t_game *game,
	t_map_node_item **item,
	int32_t x,
	char type
)
{
	if (!is_valid_char(type))
		return (ft_error("Invalid character in map"), FALSE);
	*item = (t_map_node_item *)malloc(sizeof(t_map_node_item));
	if (*item == NULL)
		return (ft_error("Failed to allocate memory for item"), FALSE);
	(*item)->x = x;
	(*item)->y = game->map->height;
	(*item)->type = type;
	(*item)->parent = *item;
	return (TRUE);
}

static t_bool	alloc_layout(t_game *game, char *line)
{
	t_map_node_item	***new_layout;
	int32_t			i;

	if (!validate_line(game, line))
		return (FALSE);
	new_layout = NULL;
	if (!re_alloc_layout(game, &new_layout))
		return (FALSE);
	i = -1;
	while (++i < game->map->width)
	{
		if (!init_item(game, &new_layout[game->map->height][i], i, line[i]))
			return (free(new_layout), FALSE);
		if (!validate_item(game, new_layout[game->map->height][i]))
			return (free(new_layout), FALSE);
	}
	if (game->map->layout != NULL)
		free(game->map->layout);
	game->map->layout = new_layout;
	return (TRUE);
}

t_bool	init_map(t_game *game, char **file_path)
{
	int		fd;
	char	*line;

	if (!alloc_map(game))
		return (ft_error("Failed to allocate memory\n"), FALSE);
	fd = open(file_path[1], O_RDONLY);
	if (fd <= 1)
		return (ft_error("Failed to open map file\n"), FALSE);
	game->map->height = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!alloc_layout(game, line))
			return (free(line), FALSE);
		free(line);
		game->map->height++;
	}
	if (!valid_map(game))
		return (close(fd), FALSE);
	if (!valid_path(game))
		return (close(fd), FALSE);
	return (close(fd), TRUE);
}
