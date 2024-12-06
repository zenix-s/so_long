/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:08:30 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map/map_private.h"
#include "../../include/shared/shared.h"

static t_bool	found_player(t_map_info *map_info)
{
	if (map_info->player)
		return (ft_error("Player must appear exactly once"), TRUE);
	map_info->player = TRUE;
	return (FALSE);
}

static t_bool	found_exit(t_map_info *map_info)
{
	if (map_info->exit)
		return (ft_error("Exit must appear exactly once"), TRUE);
	map_info->exit = TRUE;
	return (FALSE);
}

static t_bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == '\n');
}

static int32_t	line_len(char *line)
{
	int32_t	len;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	return (len);
}

t_bool	check_line(t_game *game, char *line, t_map_info *map_info)
{
	int32_t	i;

	if (game->map->height == 0)
	{
		game->map->width = line_len(line);
		if (game->map->width <= 2)
			return (ft_error("Invalid map file_2"), FALSE);
	}
	else if (game->map->width != line_len(line))
		return (ft_error("Invalid map file_3"), FALSE);
	i = 0;
	while (line[i])
	{
		if (!is_valid_char(line[i]))
			return (ft_error("Invalid map file_4"), FALSE);
		if (line[i] == 'P' && found_player(map_info))
			return (FALSE);
		else if (line[i] == 'E' && found_exit(map_info))
			return (FALSE);
		else if (line[i] == 'C')
			map_info->collectible = TRUE;
		i++;
	}
	return (TRUE);
}
