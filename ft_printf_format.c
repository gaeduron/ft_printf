/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:38:42 by gduron            #+#    #+#             */
/*   Updated: 2017/05/02 15:44:09 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_fmt(t_flag *flag, const char *fmt)
{
	init_flag(flag);
	while (*fmt)
	{
		if (flag->i == BUFFSIZE)
		{
			write(1, flag->buff, BUFFSIZE);
			flag->i = 0;
		}
		if (*fmt != '%' || *(fmt + 1) == '%')
		{
			flag->buff[flag->i++] = *fmt++;
			flag->printed_char++;
		}
		else
		{
			fmt++;
//			get_flags(flag, &fmt);
			write_buff(flag, fmt);
			fmt++;
			reset_flag(flag);
		}
	}
	write(1, flag->buff, flag->i);
	flag->i = 0;
}
