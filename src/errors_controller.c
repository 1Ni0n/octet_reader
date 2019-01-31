/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:54:31 by aguillot          #+#    #+#             */
/*   Updated: 2019/01/29 14:54:32 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/octet_reader.h"

void 	print_usage()
{
	printf("Init prgrm, then type commands to see corresponding octet sequences eaten by the prgm. Use 0 to quit the prgrm, RET to clean screen\n");
}

void	errors_controller(int errnum)
{
	if (errnum == PRINT_USAGE)
		print_usage();
	else if (errnum == NO_TERM_ENV)
		ft_putstr("Can't find env variable TERM. Exit..\n");
	else if (errnum == NO_TERM_INFO)
		ft_putstr("Can't retreive term info. Exit\n");
	reset_term();
	exit(1);
}
