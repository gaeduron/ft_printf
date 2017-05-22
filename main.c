/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:54:03 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 12:05:58 by gduron           ###   ########.fr       */
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

void	ft_print(char c)
{
	c < 32 || c == 127 ? ft_putchar('.') : ft_putchar(c);
}

void	ft_puthex(unsigned char c)
{
	c / 16 > 0 ? ft_puthex(c / 16) : 0;
	c % 16 > 9 ? ft_putchar(c % 16 + 'a' - 10) : ft_putchar(c % 16 + '0');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*s = (unsigned char *)addr;
	int				col = -1;
	size_t			i = -1;
	size_t			tmp = -1;

	while (++i < size)
	{
		col = -1;
		tmp = i;
		while (++col < 16)
		{
			if (i < size)
			{
				if (s[i] < 16)
					ft_putchar('0');
				ft_puthex(s[i]);
			}
			else
				write(1, "  ", 2);
			if (col % 2)
				ft_putchar(' ');
			i++;
		}
		col = -1;
		i = tmp;
		while (++col < 16 && i < size)
		{
			ft_print(s[i]);
			i++;
		}
		i--;
		ft_putchar('\n');
	}
}

static void     put_wchar(wchar_t c)
{
	size_t  u_fmt;
	size_t  tmp_mask;
	int     nboctet;

	u_fmt = 0;
	nboctet = 1;
	u_fmt = c <= 0x1FFFFF ? 0b11110000100000001000000010000000 : u_fmt;
	u_fmt = c <= 0xFFFF ? 0b111000001000000010000000 : u_fmt;
	u_fmt = c <= 0x7FF ? 0b1100000010000000 : u_fmt;
	u_fmt = c <= 0x7F ? 0b00000000 : u_fmt;
	while (c)
	{
		tmp_mask = u_fmt ? c & 0b00111111 : c;
		tmp_mask <<= 8 * (nboctet - 1);
		u_fmt = tmp_mask | u_fmt;
		nboctet++;
		c >>= 6;
	}
//	put_int_bin(u_fmt);
	while (nboctet)
	{
		putchar((char)(((u_fmt >> (8 * (nboctet - 1))))));
		nboctet--;
	}
}


int		main()
{
	setlocale(LC_CTYPE,"en_US.UTF-8");
	/*	wchar_t i = 0b11011000;

		unsigned int c = 0b1010111011000010;
		wchar_t d = L"∑";

		put_int_bin(*(int *)L"∑");
		printf("\n%C\n", i);
		write(1, &c, 4);
		write(1, "\n", 1);
		write(1, L"∑", 4);
		write(1, &d, 4);
		putchar('\n');
		put_int_bin(174);
		printf("\n\n%C   240x + 32\n", 0x23B2);
		printf("%C\n", 0x23B3);

		printf("\n\nprintf return = %d\n", printf("%C", 0x7F));
		printf("\n\nprintf return = %d\n", printf("%C", 0x7FF));
		printf("\n\nprintf return = %d\n", printf("%5C", 0xFFFF));*/
//	printf("\n\nprintf return = %d\n", printf("%10S", L"∑∑abc"));
//	print_memory(L"∑", 4);
//	print_memory("∑", 4);
/*	print_memory(L"∑ abc", sizeof(L"∑ abc"));
	print_memory(L"∑ abc", sizeof(int));
	print_memory("∑ abc", sizeof("∑ abc"));
	put_int_bin(*L"∑");
	putchar('\n');
	put_int_bin(L'∑');
	putchar('\n');
	printf("%S || %s\n", L"∑", ("∑"));
*/
//	printf("%lC\n\n=>put_wchar: ", L'™');
//	ft_printf("printing 'U+1F60E' => %lc\n", 0x1f60e);
//	ft_printf("printing 'U+1F60E' => %lc\n", L'猫');
//	ft_printf("printing 'U+1F60E' => %lc\n", 0x7ee);
//	ft_printf("printing 'U+1F60E' => %lc\n", 'c');
//	put_wchar(0);
//	printf("  \n");

	//	printf
	//	write(1, &c, 4);

	//	printf("return = %d\n", printf("{%C}\n", L'◊'));
	//	s[0] = *(&i + 1);
	//	write(1, &c, 4);
	// _______undefined behavior test_________
	//printf("{%10R}");
	//printf("{%03c}", 0);
	//printf("{%05s}", "abc");
	//printf("{%030S}", L"我是一只猫。");
	//printf("{%05p}", 0);
	//printf("{%05p}", 0x9efa0);
	//printf("{%-15Z}", 123);
	//printf("%#.O", 0);
	//printf("%.4S", L"我是一只猫。");
	//printf("%15.4S", L"我是一只猫。");
	//printf("%.3%");
	//printf("{%05.c}", 0);
	//printf("{%05.s}", 0);
	//printf("{%05.%}", 0);
	//printf("{%05.Z}", 0);
	//printf("{%05.S}", L"42 c est cool");
	return (0);
}
