/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:54:55 by serferna          #+#    #+#             */
/*   Updated: 2024/12/06 16:03:56 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SHARED_H

# define SHARED_H

unsigned int	gen_random_int(
					const unsigned int min,
					const unsigned int max,
					unsigned int *seed);

void			ft_error(char *msg);

#endif
