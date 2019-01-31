/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:34:59 by aguillot          #+#    #+#             */
/*   Updated: 2019/01/29 14:34:59 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/octet_reader.h"

void	init_term(void)
{
	char		*term;
	t_term		term_info;
	int			ret;

	if (!(term = getenv("TERM")))
		term = TERM;
 	if ((ret = tgetent(NULL, term)) == -1)
		errors_controller(NO_TERM_INFO);
	if (tcgetattr(STDERR_FILENO, &term_info.origin) == -1 ||\
		tcgetattr(STDERR_FILENO, &term_info.capa) == -1 ||\
		ioctl(STDERR_FILENO, TIOCGWINSZ, &term_info.max) == -1)
		errors_controller(NO_TERM_INFO);
	g_oct_reader.term_info = term_info;
}

void		modify_term(void)
{
	g_oct_reader.term_info.capa.c_lflag &= ~(ICANON | ECHO);
	g_oct_reader.term_info.capa.c_cc[VMIN] = 1;
	g_oct_reader.term_info.capa.c_cc[VTIME] = 0;
	if (tcsetattr(STDERR_FILENO, TCSADRAIN, &g_oct_reader.term_info.capa) == -1)
		errors_controller(CANT_MODIFY_TERM);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_int);
}

void		reset_term(void)
{
	if ((tcsetattr(STDERR_FILENO, TCSADRAIN, &g_oct_reader.term_info.origin)) == -1)
		errors_controller(CANT_MODIFY_TERM);
	tputs(tgetstr("te", NULL), 1, ft_putchar_int);
}

int 		main(int ac, char **av)
{
	(void)ac;
	if (ac > 1)
	{
		if (ft_strcmp(av[1], "usage") == 0)
		{
			ascii_art();
			errors_controller(PRINT_USAGE);
		}
	}
	init_term();
	modify_term();
	octet_reader();
	return (0);
}