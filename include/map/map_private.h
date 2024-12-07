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

# include "../structs.h"

t_bool		alloc_dis_set(t_dis_set **dis_set, t_game *game);

int32_t		get_dis_set_size(t_game *game);

t_dis_item	*find_dis_item(t_dis_item *item);

void		union_dis_items(t_dis_item *item1, t_dis_item *item2);

t_dis_item	*get_dis_item(t_dis_set *dis_set, int32_t x, int32_t y);

t_bool		find_valid_path(t_game *game);

void		free_dis_set(t_dis_set *dis_set);

t_bool		check_border(t_game *game);

t_bool		valid_n_items(t_map_info *validate_map);

t_bool		check_line(t_game *game, char *line, t_map_info *validate_map);

void		init_map_info(t_map_info *validate_map);

t_bool		valid_map(t_game *game, t_map_info *validate_map);

#endif
