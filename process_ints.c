/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:06:07 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 15:10:41 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_flag_zero_int(t_flags *f, int sign)
{
	if (f->zero == 1 && f->precision < 0)
	{
		f->precision = f->width - sign;
		f->width = 0;
	}
}

int	ft_put_int(char *s, t_flags *f, int sign)
{
	int	l;

	l = 0;
	ft_if_flag_zero_int(f, sign);
	if (ft_strlen(s) > f->precision)
		f->precision = ft_strlen(s);
	if (f->minus == 1)
	{
		if (sign == 1)
			write(1, "-", 1);
		l = ft_put_width('0', f->precision - ft_strlen(s));
		l = l + ft_put_str(s);
		l = l + sign + ft_put_width(' ', f->width - f->precision - sign);
	}
	if (f->minus == 0)
	{
		l = ft_put_width(' ', f->width - f->precision - sign);
		if (sign == 1)
			write(1, "-", 1);
		l = l + ft_put_width('0', f->precision - ft_strlen(s));
		l = l + sign + ft_put_str(s);
	}
	return (l);
}

int	ft_process_int(va_list *ap, t_flags *f, int len)
{
	int		arg;
	char	*s;

	arg = va_arg(*ap, int);
	if (arg == 0 && f->precision == 0)
		return (len + ft_put_width(' ', f->width));
	s = ft_itoa(arg);
	if (s[0] == '-')
		len = len + ft_put_int(&s[1], f, 1);
	else
		len = len + ft_put_int(s, f, 0);
	free (s);
	return (len);
}

int	ft_put_uns_int(char *s, t_flags *f)
{
	int	l;

	l = 0;
	if (ft_strlen(s) > f->precision)
		f->precision = ft_strlen(s);
	if (f->minus == 1)
	{
		l = ft_put_width('0', f->precision - ft_strlen(s));
		l = l + ft_put_str(s);
		l = l + ft_put_width(' ', f->width - f->precision);
	}
	if (f->minus == 0)
	{
		l = ft_put_width(' ', f->width - f->precision);
		l = l + ft_put_width('0', f->precision - ft_strlen(s));
		l = l + ft_put_str(s);
	}
	return (l);
}

int	ft_process_uns_int(va_list *ap, t_flags *f, int len)
{
	unsigned int	arg;
	char			*s;

	arg = va_arg(*ap, unsigned int);
	if (arg == 0 && f->precision == 0)
		return (len + ft_put_width(' ', f->width));
	s = ft_uns_itoa(arg);
	if (f->zero == 1 && f->precision < 0)
	{
		f->precision = f->width;
		f->width = 0;
	}
	len = len + ft_put_uns_int(s, f);
	free (s);
	return (len);
}
