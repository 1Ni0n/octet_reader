/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carac_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:20:50 by aguillot          #+#    #+#             */
/*   Updated: 2019/01/16 18:21:27 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_carac_nb(unsigned char *str)
{
	size_t 	i;
	int 	size;

	i = 0;
	size = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] >= 0 && str[i] <= 127)
				i++;
			else if (str[i] >= 192 && str[i] <= 223 && i + 2 <= ft_ustrlen(str))
				i += 2;
			else if (str[i] >= 224 && str[i] <= 239 && i + 3 <= ft_ustrlen(str))
				i += 3;
			else if (str[i] >= 240 && str[i] <= 247 && i + 4 <= ft_ustrlen(str))
				i += 4;
			else if (str[i] >= 248 && str[i] <= 251 && i + 5 <= ft_ustrlen(str))
				i += 5;
			else if (str[i] >= 252 && str[i] <= 253 && i + 6 <= ft_ustrlen(str))
				i += 6;
			else
				return (-1);
			size++;
		}
	}
	return (size);
}
