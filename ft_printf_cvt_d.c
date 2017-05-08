/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/05/08 18:18:48 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_printf_cvt_d(va_list *app, t_flag *flag)
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
}
