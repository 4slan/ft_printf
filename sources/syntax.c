/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:09:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/09 04:31:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_syntax(const char c, t_type *type)
{
	/* %[parameter][flags][width][.precision][length]type */

	if (c && type)
	{
		//check_parameter();
		check_flags(c, type->specifiers->flags);
		//check_width();
		//check_precision();
		//check_length();
		check_type(c, type);
		return (1);
	}
	return (0);
}

void		reset_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->hash = 0;
}

int			isflag(const char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#');
}

int			check_flags(const char c, t_flags *flags)
{
	if (isflag(c) && flags)
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
		{
			reset_flags(flags);
			return (0);
		}
		return (1);
	}
	return (0);
}

int			check_type(const char c, t_type *type)
{
	if (c && type)
	{
		if (conversion_type(c) == 1)
		{
			//integer_conversion(c, type);
		}
		/*else if (conversion_type(c) == 2)
		{
		}*/
		else
			return (0);
		return (1);
	}
	return (0);
}
