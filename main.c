/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:54:03 by gduron            #+#    #+#             */
/*   Updated: 2017/05/17 16:24:43 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>
#include <locale.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_int_bin(wchar_t i)
{
	i / 2 ? put_int_bin(i / 2) : 0;
	ft_putchar(i % 2 + '0');
}

int		main()
{
	setlocale(LC_CTYPE,"en_US.UTF-8");
	wchar_t i = 0b11011000;

//	char s[8];
	unsigned int c = 0b1010111011000010;

	put_int_bin(i);
	printf("\n%C\n", i);
	write(1, &c, 4);
	putchar('\n');
	put_int_bin(174);
	printf("\n\n%C   240x + 32\n", 0x23B2);
	printf("%C\n", 0x23B3);

//	printf("return = %d\n", printf("{%C}\n", L'◊'));
//	s[0] = *(&i + 1);
//	write(1, &c, 4);
	return (0);
}
