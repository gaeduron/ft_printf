/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:27:55 by gduron            #+#    #+#             */
/*   Updated: 2017/05/05 10:42:08 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_to_buff(t_flag *flag, char c)
{
	if (flag->i == BUFFSIZE)
	{
	    write(1, flag->buff, flag->i);
	    flag->i = 0;
	}
	flag->buff[flag->i] = c;
	flag->i++;
	//printf("i = %d\n", flag->i);
	flag->space--;
	flag->printed_char++;
}