/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 10:40:55 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/08 16:25:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_ui(intmax_t *number, t_info *info)
{
	if (info->length == 0)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
	else if (info->length == LENGTH_H)
		*number = (unsigned short int)va_arg(info->ap, int);
	else if (info->length == LENGTH_HH)
		*number = (unsigned char)va_arg(info->ap, int);
	else if (info->length == LENGTH_L)
		*number = (unsigned long int)va_arg(info->ap, unsigned long int);
	else if (info->length == LENGTH_LL)
		*number = (unsigned long long int)
					va_arg(info->ap, unsigned long long int);
	else if (info->length == LENGTH_J)
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->length == LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
	else if (info->length == LENGTH_T)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
}

void			type_x(const char **format, t_info *info)
{
	intmax_t	number;
	t_data		data;

	info->type = **format;
	info->space = 0;
	info->plus = 0;
	get_ui(&number, info);
	data.negative = 0;
	if (number == 0)
	{
		info->hash = 0;
		data.str = (info->point == 1 && info->precision == 0) ? "\0" : "0";
	}
	else
		data.str = ft_uitoa_base_static(number, 16, ft_isupper(info->type));
	if (info->hash == 1)
		data.prefix = ft_isupper(info->type) ? "0X" : "0x";
	data.length = ft_strlen(data.str);
	apply_specs(info, &data);
}
