/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octet_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:35:10 by aguillot          #+#    #+#             */
/*   Updated: 2019/01/29 14:35:11 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/octet_reader.h"

void 	clean_screen(void)
{
	size_t 			i;
	struct winsize 	max;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &max);
	i = -1;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar_int);
	while (++i <= max.ws_row)
		tputs(tgetstr("dl", NULL), 1, ft_putchar_int);
}

void	octet_reader(void)
{
	unsigned char 	c;
	int				i;

	i = 0;
	while (read(1, &c, 1) > 0)
	{
		i++;
		if (c == '0')
		{
			printf("Fin du prgm\n");
			reset_term();
			exit(0);
		}
		if (c == 10)
		{
			i = 0;
			clean_screen();
			continue;
		}
		printf("Compteur i: %d, Unsigned Char c: %d\n", i, c);
	}
}
