/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:12:27 by gduron            #+#    #+#             */
/*   Updated: 2017/05/15 18:04:31 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reset_flag(t_flag *flag)
{
	flag->flag['l'] = 0;
	flag->flag['L'] = 0;
	flag->flag['h'] = 0;
	flag->flag['H'] = 0;
	flag->flag['z'] = 0;
	flag->flag['j'] = 0;
	flag->flag['+'] = 0;
	flag->flag['-'] = 0;
	flag->flag[' '] = 0;
	flag->flag['.'] = 0;
	flag->flag['#'] = 0;
	flag->space = 0;
	flag->precision = -1;
	flag->id = 0;
}

void	init_cvt(t_flag *flag)
{
	flag->cvt['d'] = &ft_printf_cvt_d;
	flag->cvt['%'] = &ft_printf_cvt_pourcent;
	flag->cvt['u'] = &ft_printf_cvt_u;
	flag->cvt['U'] = &ft_printf_cvt_u;
	flag->cvt['o'] = &ft_printf_cvt_o;
	flag->cvt['O'] = &ft_printf_cvt_o;
	flag->cvt['x'] = &ft_printf_cvt_x;
	flag->cvt['X'] = &ft_printf_cvt_x;
	flag->cvt['c'] = &ft_printf_cvt_c;
	flag->cvt['s'] = &ft_printf_cvt_s;
/*	flag->cvt['D'] = &ft_printf_cvt_ld;
	flag->cvt['o'] = &ft_printf_cvt_o;
	flag->cvt['O'] = &ft_printf_cvt_lo;
	flag->cvt['u'] = &ft_printf_cvt_u;
	flag->cvt['U'] = &ft_printf_cvt_lu;
	flag->cvt['x'] = &ft_printf_cvt_x;
	flag->cvt['X'] = &ft_printf_cvt_x;
	flag->cvt['c'] = &ft_printf_cvt_c;
	flag->cvt['C'] = &ft_printf_cvt_lc;
	flag->cvt['p'] = &ft_printf_cvt_p;
	flag->cvt['s'] = &ft_printf_cvt_s;
	flag->cvt['S'] = &ft_printf_cvt_ls;*/
}

void	init_flag(t_flag *flag)
{
	flag->init++;
	init_cvt(flag);
}
