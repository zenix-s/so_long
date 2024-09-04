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

#include "../../include/so_long.h"

t_bool	alloc_map(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (game->map == NULL)
		return (FALSE);
	game->map->layout = NULL;
	game->map->height = 0;
	game->map->width = 0;
	return (TRUE);
}

t_bool	alloc_layout(t_game *game, char **line)
{
	char	**new_layout;
	int32_t	i;

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
	int			fd;
	char		*line;
	t_map_info	*map_info;

	if (!alloc_map(game))
		return (ft_error("Failed to allocate memory\n"), FALSE);
	fd = open(file_path[1], O_RDONLY);
	if (fd <= 1)
		return (ft_error("Failed to open map file\n"), FALSE);
	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (map_info == NULL)
		return (ft_error("Failed to allocate memory\n"), FALSE);
	init_map_info(map_info);
	game->map->height = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_line(game, line, map_info) || !alloc_layout(game, &line))
			return (free(line), free(map_info), FALSE);
		game->map->height++;
	}
	close(fd);
	if (!valid_map(game, map_info))
		return (FALSE);
	return (free(map_info), TRUE);
}
