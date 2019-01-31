/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrprepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:04:41 by aguillot          #+#    #+#             */
/*   Updated: 2019/01/15 16:04:43 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_ustrprepend(unsigned char *sequence, unsigned char **buff)
{
	int				sequence_s;
	int				buff_s;
	unsigned char	*tmp;

	sequence_s = 0;
	buff_s = 0;
	if (sequence)
		sequence_s = ft_ustrlen(sequence);
	if (*buff)
		buff_s = ft_ustrlen(*buff);
	if (!(tmp = (unsigned char*)malloc(sizeof(unsigned char) *\
		(buff_s + sequence_s + 1))))
	{
		free(*buff);
		return (NULL);
	}
	ft_memcpy(tmp, sequence, sequence_s);
	ft_memcpy(tmp + sequence_s, *buff, buff_s);
	tmp[sequence_s + buff_s] = '\0';
	if (buff)
		free(*buff);
	return (tmp);
}