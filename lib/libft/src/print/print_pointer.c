/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:18:24 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:18:30 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	print_pointer(unsigned long long pointer)
{
	int		characters_printed;
	char	hex_value[17];
	int		i;

	characters_printed = 0;
	i = 0;
	if (pointer == 0)
		return (ft_putstr_fd("(nil)", 1));
	characters_printed += ft_putstr_fd("0x", 1);
	while (pointer != 0)
	{
		hex_value[i] = HEX_LOW_BASE[pointer % 16];
		pointer /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		characters_printed += ft_putchar_fd(hex_value[i], 1);
	}
	return (characters_printed);
}
