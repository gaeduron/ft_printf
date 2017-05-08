/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:12:27 by gduron            #+#    #+#             */
/*   Updated: 2017/05/08 17:38:01 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reset_flag(t_flag *flag)
{
	ft_memset(flag->flag, 0, 256);
	flag->space = 0;
	flag->precision = 0;
	flag->code = 0;
}

void	init_flag(t_flag *flag)
{
	ft_memset(flag->cvt, 0, sizeof(flag->cvt));
	reset_flag(flag);
	flag->cvt['d'] = &ft_printf_cvt_d;
	flag->i = 0;
	flag->printed_char = 0;
}
