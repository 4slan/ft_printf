/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:42:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/10 22:42:45 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Setting up all fields of t_flags structure to 0
*/

void		initialize_flags(t_flags *flags)
{
	flags->space = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
}

/*
** Checking if given char is one of the flags
*/

int			is_flag(const char c)
{
	return (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0');
}

/*
** Checking if passed character in argument is one of the flags and
** setting up the corresponding bit to 1
*/

/*
? void ?????
  |
  V       */
int			check_flags(const char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
	else
		return (0);
	return (1);
}


void		set_space(t_flags *flags)
{
	flags->space = 1;
}

void		set_hash(t_flags *flags)
{
	flags->hash = 1;
}

void		set_plus(t_flags *flags)
{
	flags->plus = 1;
}

void		set_minus(t_flags *flags)
{
	flags->minus = 1;
}

void		set_zero(t_flags *flags)
{
	flags->zero = 1;
}
