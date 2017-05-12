/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:54:03 by gduron            #+#    #+#             */
/*   Updated: 2017/05/12 19:44:06 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>

int		main()
{
	ft_printf("@moulitestft: %c\n", 'Z');
	printf("@moulitest  : %c\n", 'Z');
//	printf("%d\n", (12 ? (1 ? -1 : 1) : 0) * (0 ? 12 : 10));
//	ft_printf("% d nbr = %   d %% nbr2 = %+-54d\n", 42, 42, 'd');
//	ft_printf("% d", 42);
//	ft_printf("10 == %5d\n", 10);
//	long long a = -1;
//	int b = (unsigned int)a;
//	printf("%d", 2147483648);
	//printf("% d nbr = %   d %% nbr2 = %+-54d\n", 42, 42, 'd');
	return (0);
}
