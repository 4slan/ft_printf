/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:00:15 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 16:50:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_space(const char **format, t_info *info)
{
	info->specs->flags->space = 1;
	(*format)++;
}

void	flag_hash(const char **format, t_info *info)
{
	info->specs->flags->hash = 1;
	(*format)++;
}

void	flag_plus(const char **format, t_info *info)
{
	info->specs->flags->plus = 1;
	info->specs->flags->space = 0; // Флаг '+' превосходит флаг ' ' так что обнуляем ' '
	(*format)++;
}

void	flag_minus(const char **format, t_info *info)
{
	info->specs->flags->minus = 1;
	info->specs->flags->zero = 0;
	(*format)++;
}

void	flag_zero(const char **format, t_info *info)
{
	info->specs->flags->zero = 1;
	(*format)++;
}
