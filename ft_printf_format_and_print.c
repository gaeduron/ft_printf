/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_and_print.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:28:01 by gduron            #+#    #+#             */
/*   Updated: 2017/05/15 18:10:03 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    add_to_buff(t_flag *flag, char c)
{
	if (flag->i == BUFFSIZE)
	{
		write(1, flag->buff, flag->i);
		flag->i = 0;
	}
	flag->buff[flag->i] = c;
	flag->i++;
	flag->space--;
	flag->printed_char++;
}

void	fmt_print(t_flag *flag, const char *fmt)
{
	flag->i = 0;
	while (*fmt)
	{
		if (*fmt != '%' || *(++fmt) == '%')
			add_to_buff(flag, *fmt++);
		else
		{
			if (flag->init == 0)
				init_flag(flag);
			reset_flag(flag);
			get_flags(flag, &fmt);
			if (flag->cvt[flag->id])
				(flag->cvt[flag->id])(&(flag->ap), flag);
			else
				fmt--;
		}
	}
	write(1, flag->buff, flag->i);
	flag->i = 0;
}
