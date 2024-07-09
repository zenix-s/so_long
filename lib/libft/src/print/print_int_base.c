/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:18:21 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:18:33 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	print_int_base(int number, int base, char *base_str)
{
	int	characters_printed;

	characters_printed = 0;
	if (number < 0)
	{
		characters_printed += ft_putchar_fd('-', 1);
		if (-(number / base) > 0)
			characters_printed += print_int_base(-(number / base), base,
					base_str);
		number = -(number % base);
	}
	if (number >= base)
	{
		characters_printed += print_int_base(number / base, base, base_str);
		characters_printed += ft_putchar_fd(base_str[number % base], 1);
	}
	else
		characters_printed += ft_putchar_fd(base_str[number], 1);
	return (characters_printed);
}
