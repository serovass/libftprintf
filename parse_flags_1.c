/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:00:01 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 13:05:12 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_type(char s, t_flags *f)
{
	int	type;

	type = 0;
	if (s == 'c')
		type = 1;
	if (s == 's')
		type = 2;
	if (s == 'p')
		type = 3;
	if (s == 'd' || s == 'i')
		type = 4;
	if (s == 'u')
		type = 5;
	if (s == 'x')
		type = 6;
	if (s == 'X')
		type = 7;
	if (s == '%')
		type = 8;
	if (type > 0)
		f->type = type;
	return (type);
}

int	ft_if_parseable(char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	if (s == '.' || s == '-' || s == '*')
		return (1);
	return (0);
}

int	ft_parse_flags(const char *str, va_list *ap, t_flags *f, int i)
{
	while (str[i] != '\0')
	{
		if (ft_if_type(str[i], f) != 0)
			return (i);
		if (ft_if_parseable(str[i]) == 1)
		{
			if (str[i] == '0' && f->width == 0 && f->minus == 0)
			{
				f->zero = 1;
				i++;
			}
			if (str[i] == '.')
				i = ft_if_dot(str, ap, f, i);
			if (str[i] == '-')
				i = i + ft_if_minus(f);
			if (str[i] == '*')
				i = i + ft_if_star(ap, f);
			if (str[i] >= '0' && str[i] <= '9')
				i = ft_if_digit(str, f, i);
		}
		else
			i++;
	}
	return (i);
}
