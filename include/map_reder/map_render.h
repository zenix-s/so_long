/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:15:19 by serferna          #+#    #+#             */
/*   Updated: 2024/12/13 19:15:19 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_RENDER_H

# define MAP_RENDER_H

# include "../shared.h"

void	free_map_render(t_game *game);

t_bool	init_map_render(t_game *game);

t_bool	render_map_render(t_game *game);

#endif
