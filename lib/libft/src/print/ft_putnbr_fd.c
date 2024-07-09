/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:01:41 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:02:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	long int	num_act_val;

	num_act_val = num;
	if (num_act_val < 0)
	{
		ft_putchar_fd('-', fd);
		num_act_val = -num_act_val;
	}
	if ((num_act_val / 10) > 0)
		ft_putnbr_fd(num_act_val / 10, fd);
	ft_putchar_fd((num_act_val % 10) + '0', fd);
}
