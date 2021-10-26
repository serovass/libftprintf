/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:53:58 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 14:03:38 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_hex(unsigned int arg, int X)
{
	int		i;
	char	*hex;

	i = ft_ptr_len(arg);
	hex = (char *)malloc(i + 1);
	if (hex == NULL)
		return (NULL);
	hex[i] = '\0';
	i--;
	while (arg != 0)
	{
		if ((arg % 16) < 10)
			hex[i] = (arg % 16) + 48;
		else
		{
			if (X == 0)
				hex[i] = (arg % 16) + 87;
			if (X == 1)
				hex[i] = (arg % 16) + 55;
		}
		arg = arg / 16;
		i--;
	}
	return (hex);
}

int	ft_put_hex(char *hex, t_flags *f)
{
	int	l;

	l = 0;
	ft_if_flag_zero_int(f, 0);
	if (ft_strlen(hex) > f->precision)
		f->precision = ft_strlen(hex);
	if (f->minus == 1)
	{
		l = ft_put_width('0', f->precision - ft_strlen(hex));
		l = l + ft_put_str(hex);
		l = l + 0 + ft_put_width(' ', f->width - f->precision - 0);
	}
	if (f->minus == 0)
	{
		l = ft_put_width(' ', f->width - f->precision - 0);
		if (0 == 1)
			write(1, "-", 1);
		l = l + ft_put_width('0', f->precision - ft_strlen(hex));
		l = l + 0 + ft_put_str(hex);
	}
	return (l);
}

int	ft_process_hexs(va_list *ap, t_flags *f, int X, int len)
{
	unsigned int	arg;
	char			*hex;

	arg = va_arg(*ap, unsigned long);
	if (arg == 0 && f->precision == 0)
	{
		len = len + ft_put_hex("\0", f);
		return (len);
	}
	if (arg == 0)
	{
		len = len + ft_put_hex("0", f);
		return (len);
	}
	hex = ft_get_hex(arg, X);
	if (hex == NULL)
		return (-1);
	if (f->zero == 1 && f->precision < 0)
	{
		f->precision = f->width;
		f->width = 0;
	}
	len = len + ft_put_hex(hex, f);
	free (hex);
	return (len);
}
