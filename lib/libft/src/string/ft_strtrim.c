/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:13:43 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 16:02:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strtrim(const char *str, const char *set)
{
	char	*new_str;
	int		len;
	int		start;
	int		end;

	if (!str || !set)
		return (NULL);
	len = ft_strlen(str);
	start = 0;
	end = len - 1;
	while (str[start] && ft_strchr(set, str[start]) != 0)
		start++;
	while (end > start && str[end] && ft_strchr(set, str[end]) != 0)
		end--;
	len = end - start + 1;
	new_str = ft_substr(str, start, len);
	return (new_str);
}
