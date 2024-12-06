/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:04:53 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 20:55:29 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAP_H

# define MAP_H

# include "../structs.h"

t_bool	init_map(t_game *game, char **file_path);

void	free_map(t_game *game);

#endif
