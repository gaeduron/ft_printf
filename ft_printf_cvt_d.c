/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/05/11 17:03:04 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *cvt_d(long long nbr, char *buf)
{
	char				*p;
	unsigned long long	m;

	p = buf + 44;
	*p = 0;
	if (nbr < 0)
		m = (unsigned long long)nbr;
	else
		m = nbr;
	if (m == 0)
		*--p = '0';
	while (m)
	{
		*--p = m % 10 + '0';
		m /= 10;
	}
	return (p);
}

void    ft_printf_cvt_d(va_list *app, t_flag *flag)
{
	long long		nbr;
	char			buf[44];
	char			*p;
	int				s_len;

	s_len = 0;
	nbr = 0;
	nbr = ft_printf_get_arg(app, flag);
	p = cvt_d(nbr, buf);
	if (nbr <= 4294967295)
	{
		(int)nbr < 0 ? flag->flag['+'] = 2 : 0;
		(int)nbr < 0 ? flag->flag[' '] = 0 : 0;
	}
	else
	{
		nbr < 0 ? flag->flag['+'] = 2 : 0;
		nbr < 0 ? flag->flag[' '] = 0 : 0;
	}
	flag->flag['+'] || flag->flag[' '] ? s_len = 1: 0;
	ft_printf_putd(p, (buf + sizeof buf) - p, flag, s_len);
}
/*void    ft_printf_cvt_d(va_list *app, t_flag *flag)
{
	int     nbr;
	char    buf[44];
	char    *p;
	long    m;

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
	ft_printf_putd(p, (buf + sizeof buf) - p, flag);
}*/
