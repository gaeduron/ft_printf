/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:12:27 by gduron            #+#    #+#             */
/*   Updated: 2017/05/02 18:39:25 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	reset_flag(t_flag *flag)
{
	ft_memset(flag->flag, 0, 256);
	flag->space = 0;
	flag->precision = 0;
}

void	init_flag(t_flag *flag)
{
	reset_flag(flag);
	flag->cvt['d'] = &cvt_d;
}
