/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:10 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared/shared.h"

unsigned int	gen_random_int(
	const unsigned int min,
	const unsigned int max,
	unsigned int *seed
)
{
	*seed = *seed * 1103515245 + 12345;
	return (1 + (((*seed / 65536) % 32768) % (max - min + 1)));
}
