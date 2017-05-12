/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:58:43 by gduron            #+#    #+#             */
/*   Updated: 2017/05/12 13:44:11 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_flag(char c)
{
	char *all;

	all = "0123456789lhjz.#0+- ";
	while (*all)
	{
		if (*all++ == c)
			return (1);
	}
	return (0);
}

void    resolve_flag_conflic(t_flag *flag)
{
	if (flag->id != 'o' && flag->id != 'X' && flag->id != 'x')
		flag->flag['#'] = 0;
	if (flag->precision && 
			(flag->id != 'o' && flag->id != 'X' && flag->id != 'x' && 
			flag->id != 'u' && flag->id != 'd' && flag->id != 'i'))
		flag->flag['0'] = 0;
	flag->flag['-'] ? flag->flag['0'] = 0 : 0;
	flag->flag['+'] ? flag->flag[' '] = 0 : 0;
	flag->id != 'd' && flag->id != 'i' ? flag->flag[' '] = 0 : 0;
	flag->id != 'd' && flag->id != 'i' ? flag->flag['+'] = 0 : 0;
//	if (flag->precision == -1 && flag->flag['0'])
//		flag->precision = flag->space;
}

void	get_flags(t_flag *flag, const char **fmt)
{
	while (!(flag->cvt[(int)**fmt]) && is_flag((int)**fmt))
	{
		if ((flag->flag[(int)**fmt] == 1) && (**fmt == 'l' || **fmt == 'h'))
		{
			flag->flag[(int)**fmt - ('a' - 'A')] = 1;
			flag->flag[(int)**fmt] = 0;
		}
		else 
			flag->flag[(int)**fmt] = 1;
		if (**fmt == '.' || ft_isdigit(**fmt))
		{
			**fmt == '.' ? (flag->precision = atoi(*fmt + 1)) : 
				(flag->space = atoi(*fmt));
			while (ft_isdigit(*(*fmt + 1)))
				(*fmt)++;
		}
		(*fmt)++;
	}
	flag->cvt[(int)**fmt] ? (flag->id = **fmt) : 0;
	(*fmt)++;
	resolve_flag_conflic(flag);
}
