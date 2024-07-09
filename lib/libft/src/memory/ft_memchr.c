/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:02:14 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:02:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memchr(const void *ptr, int chr, size_t len)
{
	unsigned char	*act_byte;

	act_byte = (unsigned char *)ptr;
	while (len--)
	{
		if (*act_byte == (unsigned char)chr)
			return ((void *)act_byte);
		act_byte++;
	}
	return (NULL);
}
