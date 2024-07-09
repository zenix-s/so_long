/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:53:21 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:02:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	len = ft_numlen(num);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	if (num < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	while (len > 0 && str[len - 1] != '-')
	{
		str[len - 1] = (num % 10) * sign + '0';
		num /= 10;
		len--;
	}
	return (str);
}
