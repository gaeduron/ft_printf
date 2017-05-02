/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:58:43 by gduron            #+#    #+#             */
/*   Updated: 2017/05/02 19:45:09 by gduron           ###   ########.fr       */
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

void	get_flags(t_flag *flag, const char **fmt)
{
	int i = 0;
	while (!(flag->cvt[**fmt]) && is_flag(**fmt))
	{
		if ((flag->flag[**fmt] == 1) && (**fmt == 'l' || **fmt == 'h'))
			flag->flag[**fmt - ('a' - 'A')] = 1;
		flag->flag[**fmt] = 1;
		if (**fmt == '.' || ft_isdigit(**fmt))
		{
		   **fmt == '.' ? (flag->precision = atoi(*fmt + 1)) : 
			   (flag->space = atoi(*fmt));
		   while (ft_isdigit(*(*fmt + 1)))
			   (*fmt)++;
		}
		(*fmt)++;
	}
//	while (i < 256)
//	{
//		if (flag->flag[i])
//			printf("flag: |%c|\n", i);
//		i++;
//	}
//	printf("space = %d && precision = %d\n", flag->space, flag->precision);
}
