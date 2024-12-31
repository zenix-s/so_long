/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:45:45 by serferna          #+#    #+#             */
/*   Updated: 2024/12/07 18:45:45 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"

static int32_t	line_len(char *line)
{
	int32_t	len;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
	{
		len++;
	}
	return (len);
}

t_bool	validate_line(t_game *game, char *line)
{
	if (game->map->height == 0)
	{
		game->map->width = line_len(line);
		if (game->map->width <= 2)
		{
			return (ft_error("Invalid line length"), FALSE);
		}
	}
	if (game->map->height != 0 && game->map->width != line_len(line))
	{
		return (ft_error("Invalid line length"), FALSE);
	}
	return (TRUE);
}
