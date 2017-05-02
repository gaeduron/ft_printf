/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 11:18:24 by gduron            #+#    #+#             */
/*   Updated: 2017/05/02 20:32:17 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

# define BUFFSIZE 4096

typedef struct s_flag t_flag;

typedef void (*f)(va_list *app, struct s_flag *flag);

typedef struct	s_flag
{
	char		flag[256];
	char		buff[BUFFSIZE];
	int			i;
	int			space;
	int			precision;
	f			cvt[256];
	va_list		ap;
	long long	printed_char;
}				t_flag;

int				ft_printf(const char *format, ...);
void			print_fmt(t_flag *flag, const char *fmt);
void			init_flag(t_flag *flag);
void			reset_flag(t_flag *flag);
void			write_buff(t_flag *flag, const char **fmt);
void			cvt_d(va_list *app, t_flag *fleag);
void			write_d(char *p, int len, t_flag *flag);
void			get_flags(t_flag *flag, const char **fmt);
void			add_to_buff(t_flag *flag, char c);

#endif
