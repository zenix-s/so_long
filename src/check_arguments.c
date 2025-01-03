/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:09:08 by serferna          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:46 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_bool	check_arguments(int argc, char **argv)
{
	char	*extension;
	int		i;

	if (argc != 2)
		return (ft_error("Invalid number of arguments\n"), FALSE);
	extension = ft_strrchr(argv[1], '.');
	if (extension == NULL)
		return (ft_error("Invalid file extension\n"), FALSE);
	i = 0;
	while (extension[i] != '\0' && VALID_EXTENSION[i] != '\0')
	{
		if (extension[i] != VALID_EXTENSION[i])
			return (ft_error("Invalid file extension\n"), FALSE);
		i++;
	}
	if (extension[i] != '\0' && VALID_EXTENSION[i] == '\0')
		return (ft_error("Invalid file extension\n"), FALSE);
	return (TRUE);
}
