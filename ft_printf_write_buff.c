/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 17:25:53 by gduron            #+#    #+#             */
/*   Updated: 2017/05/05 16:28:04 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	write_d(char *p, int len, t_flag *flag)
{
	if (flag->flag['-'])
	{
		if ((flag->flag['+'] || flag->flag[' ']) && ft_isdigit(*p))
			flag->flag['+'] ? add_to_buff(flag, '+') : add_to_buff(flag, ' ');
		while ((flag->precision--) - len > 0)
			add_to_buff(flag, '0');
		while (*p)
			add_to_buff(flag, *p++);
		while (flag->space > 0)
			add_to_buff(flag, ' ');
	}
	else
	{
//		printf("%s = c\n", p);
		if (*p == '-' && (flag->flag['0'] || flag->precision)
			   	&& len-- && !(flag->flag['+'] = 0) && !(flag->flag[' '] = 0))
			add_to_buff(flag, *p++);
		while (!flag->flag['0'] && (flag->space - 
				(flag->precision - len > 0 ? flag->precision : len) -
				(flag->flag['+'] || flag->flag[' '] ? 1 : 0)) > 0)
			add_to_buff(flag, ' ');
		if ((flag->flag['+'] || flag->flag[' ']) && ft_isdigit(*p))
			flag->flag['+'] ? add_to_buff(flag, '+') : add_to_buff(flag, ' ');
		while (((flag->precision) - len > 0) || ((flag->space) - len > 0))
		{
			if ((flag->space) <= (flag->precision))
				(flag->precision--) ? add_to_buff(flag, '0') : 0;
			else
				(flag->flag['0'] && !flag->precision) ? 
					add_to_buff(flag, '0') : add_to_buff(flag, ' ');
		}
		while (*p)
			add_to_buff(flag, *p++);
	}
}

void	cvt_d(va_list *app, t_flag *flag)
{
	int		nbr;
	char	buf[44];
	char	*p;
	long	m;

	p = buf + sizeof(buf);
	*p = 0;
	nbr = va_arg(*app, int);
	if (nbr < 0)
		m = -(long)nbr;
	else
		m = nbr;
	if (m == 0)
		*--p = '0';
	while (m)
	{
		*--p = m % 10 + '0';
		m /= 10;
	}
	if (nbr < 0)
		*--p = '-';
	write_d(p, (buf + sizeof buf) - p, flag);
}

void	write_buff(t_flag *flag, const char **fmt)
{
	if (flag->cvt[(int)**fmt])
	{
		(flag->cvt[(int)**fmt])(&(flag->ap), flag);
		(*fmt)++;
	}
}
