/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:22:51 by serferna          #+#    #+#             */
/*   Updated: 2024/12/08 00:22:51 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H

# define SHARED_H

// MLX42 LIB
# include "../lib/MLX42/include/MLX42/MLX42.h"

// LIBFT
# include "../lib/libft/libft.h"

// NULL
# include <stdio.h>

// Malloc, free, exit
# include <stdlib.h>

// Close
# include <unistd.h>

// Open
# include <fcntl.h>

// STRUCTS
# include "./structs.h"

// General utilities
# include "./utils/utils.h"

// Map related global utilities
# include "./map/map_shared.h"

# define TILE_SIZE 64
// Character Speed pixels per second
# define CHARACTER_SPEED 320.0
# define VALID_EXTENSION ".ber"

void	ft_error(char *msg);

#endif
