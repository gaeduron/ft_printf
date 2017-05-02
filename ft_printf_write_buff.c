/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 17:25:53 by gduron            #+#    #+#             */
/*   Updated: 2017/05/02 20:46:56 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
::
void	write_d(char *p, int len, t_flag *flag)
{
	if (flag->flag['-'])
	{
		
	}
	else
	{
		
	}
	while (len--)
		flag->buff[flag->i++] = *p++;
}

void	cvt_d(va_list *app, t_flag *flag)
{
	int		nbr;
	char	buf[43];
	char	*p;
	long	m;

	p = buf + sizeof(buf);
	nbr = va_arg(*app, int);
	if (nbr < 0)
		m = -nbr;
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
	if (flag->cvt[**fmt])
	{
		(flag->cvt[**fmt])(&(flag->ap), flag);
		(*fmt)++;
	}
}
