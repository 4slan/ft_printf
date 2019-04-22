/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:03:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/22 16:54:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_number() receive  an addresse of a number and info structure.
** It retrieve an integer from arguments then depending on what type of length
** was specified (which bit is setted to 1) it cast retrieved integer.
*/

static void		get_number(intmax_t *number, t_info *info)
{
	if (info->specs->length == 0)
		*number = (int)va_arg(info->ap, int);
	else if (info->specs->length == LENGTH_H)
		*number = (short int)va_arg(info->ap, short int);
	else if (info->specs->length == LENGTH_HH)
		*number = (signed char)va_arg(info->ap, signed char);
	else if (info->specs->length == LENGTH_L)
		*number = (long int)va_arg(info->ap, long int);
	else if (info->specs->length == LENGTH_LL)
		*number = (long long int)va_arg(info->ap, long long int);
	else if (info->specs->length == LENGTH_J)
		*number = (intmax_t)va_arg(info->ap, intmax_t);
	else if (info->specs->length == LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
	else if (info->specs->length == LENGTH_T)
		*number = (int)va_arg(info->ap, int);
}

void			type_di(const char **format, t_info *info)
{
	intmax_t	number;
	t_data		data;

	info->type = **format;
	get_number(&number, info);
	info->specs->flags->hash = 0;
	if (info->specs->length == 0)
		data.str = ft_itoa(ABS(number));
	else
		data.str = ft_litoa(ABS(number));
	data.length = ft_nblen(number);
	data.negative = 0;
	if (number < 0)
		data.negative = 1;
	apply_specs(info, &data);
}
