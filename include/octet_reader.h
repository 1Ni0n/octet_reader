/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octet_reader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:34:35 by aguillot          #+#    #+#             */
/*   Updated: 2019/01/29 14:34:37 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OCTET_READER_H
# define OCTET_READER_H

# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"


/*
*** DEFINE BASIC ENV VAR
*/
# define TERM "xterm-256color"

/*
*** DEFINE ERROR CODES
*/
enum e_errnum
{
	PRINT_USAGE = 0,
	NO_TERM_ENV, 
	NO_TERM_INFO,
	CANT_MODIFY_TERM,
};

/*
***DEFINE STRUCT
*/
typedef struct 		s_term
{
	struct termios	origin;
	struct termios	capa;
	struct winsize	max;
}					t_term;

typedef struct 		s_oct_reader
{
	t_term			term_info;
}					t_oct_reader;

t_oct_reader		g_oct_reader;


void				octet_reader(void);
void				reset_term(void);
void				errors_controller(int errnum);
void				ascii_art(void);
#endif