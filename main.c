/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:54:03 by gduron            #+#    #+#             */
/*   Updated: 2017/05/02 15:48:08 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int		main()
{
	ft_printf("nbr = %d nbr2 = %d\n", (42 + 42), 'd');
//    ft_printf(" = %d" , ft_printf(" = %d" , ft_printf("coucou\n")));
	return (0);
}