/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:49:17 by serferna          #+#    #+#             */
/*   Updated: 2024/12/07 18:52:52 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/map/map_private.h"

t_bool	is_valid_char(char c)
{
	return (
		c == FLOOR
		|| c == WALL
		|| c == COLLECTIBLE
		|| c == EXIT
		|| c == PLAYER
		|| c == '\n'
	);
}
