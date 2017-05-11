/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:19:14 by gduron            #+#    #+#             */
/*   Updated: 2017/05/11 11:58:50 by gduron           ###   ########.fr       */
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

void	ft_put_sign(t_flag *flag)
{
	if (flag->flag['#'])
	{
		add_to_buff(flag, '0'): 0;
		flag->id == 'x' ? add_to_buff(flag, 'x'): 0;
		flag->id == 'X' ? add_to_buff(flag, 'X'): 0;
	}
	flag->flag[' '] ? add_to_buff(flag, ' '): 0;
	flag->flag['+'] == 1 ? add_to_buff(flag, '+'): 0;
	flag->flag['+'] == 2 ? add_to_buff(flag, '-'): 0;
}

void	ft_put_precision_or_0(t_flag *flag)
{
	while (flag->precision-- > len)	
}

void	ft_putd()
{
	while (!flag->flag['-'] && need_space)
		add_to_buff(flag, ' ');
	ft_put_sign(flag);
	ft_put_precision_or_0();
	ft_put_value();
	while (flag->flag['-'] && flag->space > 0)
		add_to_buff(flag, ' ');
}
