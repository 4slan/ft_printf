/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 05:08:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/11 03:50:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** conversion_type() checks if given argument match integer conversion (diouxX)
** or floating-point conversion (eEfgG). If given argument doesn't match any
** of those function return 0
*/

int		conversion_type(const char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'e' || c == 'E' || c == 'f' || c == 'g' || c == 'G')
		return (2);
	return (0);
}

/*
** Depending what type is given argument integer_conversion() sets up
** type field of t_placeholder structure
*/

void	integer_conversion(const char c, t_placeholder *placeholder)
{
	if (c == 'd' || c == 'i')
		placeholder->type = 'd';
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		placeholder->type = 'u';
}

void	floating_point_conversion(const char c, t_placeholder *placeholder)
{
	if (c)
		placeholder->type = 'f';
}
