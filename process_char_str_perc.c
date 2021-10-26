/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char_str_perc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:38:09 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 13:53:28 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_char(va_list *ap, t_flags *f, int len)
{
	char	c;

	c = (char)va_arg(*ap, int);
	if (f->minus == 1)
	{
		write(1, &c, 1);
		len = len + ft_put_width(' ', f->width - 1);
	}
	if (f->minus == 0)
	{
		len = len + ft_put_width(' ', f->width - 1);
		write(1, &c, 1);
	}
	return (len + 1);
}

int	ft_process_str(va_list *ap, t_flags *f, int len)
{
	char	*s;
	int		l;
	int		width;

	s = va_arg(*ap, char *);
	if (f->precision > ft_strlen(s) || f->precision < 0)
		f->precision = ft_strlen(s);
	if (f->minus == 1)
	{
		l = ft_put_s(s, f->precision);
		width = f->width - l;
		l = l + ft_put_width(' ', width);
	}
	if (f->minus == 0)
	{
		width = f->width - f->precision;
		l = ft_put_width(' ', width);
		l = l + ft_put_s(s, f->precision);
	}
	return (len + l);
}

int	ft_process_percent(t_flags *f, int len)
{
	char	space;

	if (f->zero == 1)
		space = '0';
	else
		space = ' ';
	if (f->minus == 1)
	{
		write(1, "%", 1);
		len = 1 + len + ft_put_width(space, f->width - 1);
	}
	else
	{
		len = 1 + len + ft_put_width(space, f->width - 1);
		write(1, "%", 1);
	}
	return (len);
}
