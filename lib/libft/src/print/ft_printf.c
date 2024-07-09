/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:18:08 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:18:09 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	dispatcher(const char **format, va_list arguments, int *position)
{
	if ((*format)[*position] == 'd' || (*format)[*position] == 'i')
		return (print_int_base(va_arg(arguments, int), 10, DEC_BASE));
	else if ((*format)[*position] == 'c')
		return (ft_putchar_fd(va_arg(arguments, int), 1));
	else if ((*format)[*position] == 's')
		return (ft_putstr_fd(va_arg(arguments, char *), 1));
	else if ((*format)[*position] == 'x')
		return (print_uint_base(va_arg(arguments, unsigned int), 16,
				HEX_LOW_BASE));
	else if ((*format)[*position] == 'X')
		return (print_uint_base(va_arg(arguments, unsigned int), 16,
				HEX_UP_BASE));
	else if ((*format)[*position] == 'u')
		return (print_uint_base(va_arg(arguments, unsigned int), 10, DEC_BASE));
	else if ((*format)[*position] == 'p')
		return (print_pointer(va_arg(arguments, unsigned long long)));
	else if ((*format)[*position] == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		characters_printed;
	va_list	arguments;
	int		i;

	i = 0;
	characters_printed = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			characters_printed += dispatcher(&format, arguments, &i);
		}
		else
			characters_printed += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(arguments);
	return (characters_printed);
}
