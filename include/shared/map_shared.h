/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shared.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:21:08 by serferna          #+#    #+#             */
/*   Updated: 2024/12/08 00:21:55 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_SHARED_H

# define MAP_SHARED_H

# include "../structs.h"

t_bool	is_floor(const t_game *game, const int32_t x, const int32_t y);

t_bool	is_collectible(const t_game *game, const int32_t x, const int32_t y);

t_bool	is_exit(const t_game *game, const int32_t x, const int32_t y);

t_bool	is_wall(const t_game *game, const int32_t x, const int32_t y);

t_bool	is_special(const t_game *game, const int32_t x, const int32_t y);

void	print_layout(t_game *game);

#endif
