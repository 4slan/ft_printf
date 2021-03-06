/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_silen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:43:10 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/05 16:23:53 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_silen(intmax_t number, int base)
{
	size_t	length;

	length = 0;
	if (number == 0)
		return (1);
	else if (number < 0)
		length = 1;
	while (number != 0)
	{
		number /= base;
		++length;
	}
	return (length);
}
