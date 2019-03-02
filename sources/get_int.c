/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:18:09 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/02 14:41:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_int(const char **format, t_placeholder *placeholder)
{
	int			nb;
	int			precision;

	nb = 0;
	precision = 0;
	if (**format == '.') // Если текущий символ это '.' то значит следует точность
	{
		precision = 1; // Установить значение 1 для провери в конце функции
		(*format)++; // Пропускаем символ '.' для определения целого числа
	}
	while (ft_isdigit(**format)) // Пока текущий символ это цифра то определить значение числа
	{
		nb *= 10;
		nb = nb + (**format - '0');
		(*format)++;
	}
	if (precision == 0) // Если переменная precision равна 0 то установить целое число в поле width
		placeholder->specs->width = nb;
	else // Иначе установить определенное число в поле точности
		placeholder->specs->precision = nb;
}