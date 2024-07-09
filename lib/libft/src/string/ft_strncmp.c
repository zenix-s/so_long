/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:21:12 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:02:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	if (!str1 && !str2)
		return (0);
	while (len > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		len--;
	}
	if (len == 0)
		return (0);
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
