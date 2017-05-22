/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:19:14 by gduron            #+#    #+#             */
/*   Updated: 2017/05/22 10:54:01 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		put_wchar(t_flag *flag, wchar_t c)
{
	size_t	u_fmt;
	size_t	tmp_mask;
	int		nboctet;
	
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
		c = (size_t)c == u_fmt ? c >> 7: c >> 6;
		nboctet = c ? nboctet + 1 : nboctet;
	}
	u_fmt > 0b11110000100000001000000010000000 ? nboctet++ : 0;
	while (nboctet)
	{
		if (flag->precision-- > 0)
			add_to_buff(flag ,(char)(u_fmt >> (8 * (nboctet - 1))));
		nboctet--;
	}
}

static void		ft_put_space(int call, int s_len, int len, t_flag *flag)
{
	if (call == 1)
	{
		while (!flag->flag['-'] && !flag->flag['0'] && flag->space > 
				(flag->precision > len ? flag->precision : len) + s_len)
			add_to_buff(flag, ' ');
	}
	else if (call == 2)
	{
		while (flag->flag['-'] && flag->space > 0)
			add_to_buff(flag, ' ');
	}
}

static void		ft_put_value(t_flag *flag, wchar_t *p)
{
	if (flag->id == 'C')
		put_wchar(flag, *p++);
	while (*p != L'\0')
		put_wchar(flag, *p++);
}

void			ft_printf_putls(wchar_t *p, int len, t_flag *flag)
{
	flag->space ? ft_put_space(1, 0, len, flag) : 0;
	ft_put_value(flag, p);
	flag->space > 0 ? ft_put_space(2, 0, len, flag) : 0;
}
