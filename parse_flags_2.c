/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:05:27 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 13:12:37 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_dot(const char *str, va_list *ap, t_flags *f, int i)
{
	int	dot;

	i++;
	dot = 0;
	if (str[i] == '*')
	{
		f->precision = va_arg(*ap, int);
		return (i + 1);
	}
	else
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			dot = dot * 10 + (str[i] - '0');
			i++;
		}
		f->precision = dot;
	}
	return (i);
}

int	ft_if_minus(t_flags *f)
{
	f->minus = 1;
	f->zero = 0;
	return (1);
}

int	ft_if_star(va_list *ap, t_flags *f)
{
	f->star = 1;
	f->width = va_arg(*ap, int);
	if (f->width < 0)
	{
		f->minus = 1;
		f->width = -1 * f->width;
		f->zero = 0;
	}
	return (1);
}

int	ft_if_digit(const char *str, t_flags *f, int i)
{
	int	width;

	width = 0;
	if (f->star == 1)
		i++;
	else
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			width = width * 10 + (str[i] - '0');
			i++;
		}
	}
	f->width = width;
	return (i);
}
