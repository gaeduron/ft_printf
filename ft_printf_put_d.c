/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:19:14 by gduron            #+#    #+#             */
/*   Updated: 2017/05/08 18:33:16 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_printf_putd(char *p, int len, t_flag *flag)
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
		if (*p == '-' && (flag->flag['0'] || flag->precision)
				&& len-- && !(flag->flag['+'] = 0) && !(flag->flag[' '] = 0))
			add_to_buff(flag, *p++);
		while (!flag->flag['0'] && (flag->space -
					(flag->precision - len > 0  ? flag->precision : len) -
					(flag->flag['+'] || flag->flag[' '] ? 1 : 0)) > 0)
			add_to_buff(flag, ' ');
		*p == '0' && flag->precision == 0 && flag->flag['.'] &&
			flag->space > 0 ? add_to_buff(flag, ' ') : 0;
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
		while (*p && (flag->flag['.'] && *p == '0' ? 0 : 1 ))
			add_to_buff(flag, *p++);
	}
}

