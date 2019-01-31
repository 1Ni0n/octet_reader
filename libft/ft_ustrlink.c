/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:51:32 by aguillot          #+#    #+#             */
/*   Updated: 2019/01/11 10:51:33 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned char	*ft_ustrlink(unsigned char **over, unsigned char *buff)
{
	int				over_s;
	int				buff_s;
	unsigned char	*tmp;

	over_s = 0;
	buff_s = 0;
	if (*over)
		over_s = ft_ustrlen(*over);
	if (buff)
		buff_s = ft_ustrlen(buff);
	if (!(tmp = (unsigned char*)malloc(sizeof(unsigned char) *\
		(buff_s + over_s + 1))))
	{
		free(*over);
		return (NULL);
	}
	ft_memcpy(tmp, *over, over_s);
	ft_memcpy(tmp + over_s, buff, buff_s);
	tmp[over_s + buff_s] = '\0';
	if (over)
		free(*over);
	return (tmp);
}
