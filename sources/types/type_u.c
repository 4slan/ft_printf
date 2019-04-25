/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:11:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/25 16:12:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_number() receive  an addresse of a number and info structure.
** It retrieve an integer from arguments then depending on what type of length
** was specified (which bit is setted to 1) it cast retrieved integer.
*/

static void		get_ui(intmax_t *number, t_info *info)
{
	if (info->type == 'U')
		*number = (intmax_t)va_arg(info->ap, intmax_t);
	else if (info->specs->length == 0)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
	else if (info->specs->length == LENGTH_H)
		*number = (unsigned short int)va_arg(info->ap, int);
	else if (info->specs->length == LENGTH_HH)
		*number = (unsigned char)va_arg(info->ap, int);
	else if (info->specs->length == LENGTH_L)
		*number = (unsigned long int)va_arg(info->ap, unsigned long int);
	else if (info->specs->length == LENGTH_LL)
		*number = (unsigned long long int)
					va_arg(info->ap, unsigned long long int);
	else if (info->specs->length == LENGTH_J)
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->specs->length == LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
	else if (info->specs->length == LENGTH_T)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
}

void			type_u(const char **format, t_info *info)
{
	intmax_t	number;
	t_data		data;

	info->type = **format;
	get_ui(&number, info);
	info->specs->flags->hash = 0;
	data.str = ft_uitoa_base(number, 10, 0);
	data.length = ft_nblen(number);
	data.negative = 0;
	apply_specs(info, &data);
	free(data.str);
}
