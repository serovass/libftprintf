/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:27:11 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 12:59:34 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	f;

	f.type = 0;
	f.width = 0;
	f.minus = 0;
	f.zero = 0;
	f.star = 0;
	f.precision = -1;
	return (f);
}

int	ft_process_types(va_list *ap, t_flags *f, int len)
{
	if (f->type == 1)
		return (ft_process_char(ap, f, len));
	if (f->type == 2)
		return (ft_process_str(ap, f, len));
	if (f->type == 3)
		return (ft_process_ptr(ap, f, len));
	if (f->type == 4)
		return (ft_process_int(ap, f, len));
	if (f->type == 5)
		return (ft_process_uns_int(ap, f, len));
	if (f->type == 6)
		return (ft_process_hexs(ap, f, 0, len));
	if (f->type == 7)
		return (ft_process_hexs(ap, f, 1, len));
	if (f->type == 8)
		return (ft_process_percent(f, len));
	return (len);
}

int	ft_parse_str(const char *str, va_list *ap)
{
	int		i;
	int		len;
	t_flags	f;

	i = 0;
	len = 0;
	while (str[i] != '\0' && len >= 0)
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (str[i] == ' ')
				len = len + ft_put_char(str[i]);
			f = ft_init_flags();
			i = ft_parse_flags(str, ap, &f, i);
			len = ft_process_types(ap, &f, len);
			if (len < 0)
				return (-1);
		}
		else
			len = len + ft_put_char(str[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, str);
	len = ft_parse_str(str, &ap);
	va_end(ap);
	return (len);
}
