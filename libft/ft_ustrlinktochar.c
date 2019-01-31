/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrlinktochar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:51:45 by aguillot          #+#    #+#             */
/*   Updated: 2019/01/11 10:51:46 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_ustrlinktochar(unsigned char **str, unsigned char c)
{
	size_t			str_s;
	unsigned char	*tmp;

	str_s = 0;
	if (*str)
		str_s = ft_ustrlen(*str);
	if (!c)
		return (*str);
	if (!(tmp = (unsigned char*)malloc(sizeof(unsigned char) * (str_s + 2))))
	{
		free(*str);
		return (NULL);
	}
	ft_memcpy(tmp, *str, str_s);
	tmp[str_s] = c;
	tmp[str_s + 1] = '\0';
	if (*str)
		free(*str);
	return (tmp);
}
