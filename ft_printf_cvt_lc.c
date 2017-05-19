/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cvt_pourcent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:18:13 by gduron            #+#    #+#             */
/*   Updated: 2017/05/19 18:16:03 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_printf_cvt_lc(va_list *app, t_flag *flag)
{
	wchar_t		buf[2];

	buf[0] = (wchar_t)va_arg(*app, wchar_t);
	buf[1] = 0;
	flag->precision = 4;
	ft_printf_putls(buf, 4, flag);
}

