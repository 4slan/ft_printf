/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/09 03:31:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	/*char	*world = "World";
	char	exclam = '!';*/
	float	nb = 42.68;

	printf("%+f \n", nb);
	if (ft_printf("%-+f \n", nb) < 0)
		return (1);
	/*printf("Hello, %s%c %+.2f%%\n", world, exclam, nb);
	if (ft_printf("Hello, %s%c %+.2f%%\n", world, exclam, nb) < 0)
		return (1);*/
	return (0);
}
