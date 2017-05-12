/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:18:24 by gduron            #+#    #+#             */
/*   Updated: 2017/05/12 17:03:37 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# define BUFFSIZE 4096

typedef struct s_flag t_flag;

typedef void (*f)(va_list *app, struct s_flag *flag);

typedef struct	s_flag
{
	char		flag[256];
	char		buff[BUFFSIZE];
	int			id;
	int			i;
	int			space;
	int			precision;
	f			cvt[256];
	va_list		ap;
	long long	printed_char;
}				t_flag;

int				ft_printf(const char *format, ...);
void			fmt_print(t_flag *flag, const char *fmt);
void			init_flag(t_flag *flag);
void			reset_flag(t_flag *flag);
void			get_flags(t_flag *flag, const char **fmt);
void			add_to_buff(t_flag *flag, char c);
long long		ft_printf_get_arg(va_list *app, t_flag *flag);

void			ft_printf_cvt_d(va_list *app, t_flag *flag);
void            ft_printf_cvt_o(va_list *app, t_flag *flag);
void            ft_printf_cvt_lo(va_list *app, t_flag *flag);
void            ft_printf_cvt_u(va_list *app, t_flag *flag);
void            ft_printf_cvt_lu(va_list *app, t_flag *flag);
void            ft_printf_cvt_x(va_list *app, t_flag *flag);
void            ft_printf_cvt_c(va_list *app, t_flag *flag);
void            ft_printf_cvt_lc(va_list *app, t_flag *flag);
void            ft_printf_cvt_p(va_list *app, t_flag *flag);
void            ft_printf_cvt_s(va_list *app, t_flag *flag);
void            ft_printf_cvt_ls(va_list *app, t_flag *flag);
void			ft_printf_cvt_pourcent(va_list *app, t_flag *flag);

void			ft_printf_putd(char *p, int len, t_flag *flag, int s_len);
void            ft_printf_puts(char *p, int len, t_flag *flag);

#endif
