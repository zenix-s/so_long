/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:03:39 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:02:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char	*act_byte1;
	const unsigned char	*act_byte2;

	if (!str1 && !str2)
		return (0);
	act_byte1 = (const unsigned char *)str1;
	act_byte2 = (const unsigned char *)str2;
	while (len--)
	{
		if (*act_byte1 != *act_byte2)
			return (*act_byte1 - *act_byte2);
		act_byte1++;
		act_byte2++;
	}
	return (0);
}
