/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:04:45 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 21:48:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PRIVATE_H

# define MAP_PRIVATE_H

# include "../shared.h"

// Map Validation

t_bool	validate_line(t_game *game, char *line);

t_bool	validate_item(t_game *game, t_map_node_item *item);

t_bool	is_valid_char(char c);

t_bool	check_border(t_game *game);

t_bool	valid_items(t_game *game);

t_bool	valid_map(t_game *game);

// Path Validation

t_bool	valid_path(t_game *game);

#endif
