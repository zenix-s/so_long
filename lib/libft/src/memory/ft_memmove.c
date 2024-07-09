/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:01:14 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:02:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_byte;
	unsigned char	*src_byte;

	if (!dest && !src)
		return (NULL);
	dest_byte = (unsigned char *)dest;
	src_byte = (unsigned char *)src;
	if (dest_byte < src_byte)
	{
		while (len--)
		{
			*dest_byte++ = *src_byte++;
		}
	}
	else
	{
		dest_byte = dest_byte + (len - 1);
		src_byte = src_byte + (len - 1);
		while (len--)
		{
			*dest_byte-- = *src_byte--;
		}
	}
	return (dest);
}
