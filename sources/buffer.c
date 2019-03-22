/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 04:48:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/22 11:08:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		buffer_full(t_buffer *buffer)
{
	return (buffer->index == BUFF_SIZE - 1);
}

void	print_buffer(t_buffer *buffer)
{
	write(1, buffer->content, buffer->index); // Вывести на экран строку в количестве индекса
	buffer->index = 0; // Передвинуть индекс на 0
}

void	write_char(t_buffer *buffer, char c)
{
	if (buffer_full(buffer) == 1) // Если буффер переполнен, то вывести (и обнулить) его
		print_buffer(buffer);
	buffer->content[buffer->index++] = c;
	buffer->length++; // Увеличить счётчик количества символов в строке
}

void	write_str(t_buffer *buffer, char *str, int length)
{
	while (str && *str && length--)
		write_char(buffer, *str++);
}
