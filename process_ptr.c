/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:11:07 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 15:19:00 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long arg)
{
	int	i;

	i = 0;
	while (arg != 0)
	{
		arg = arg / 16;
		i++;
	}
	return (i);
}

char	*ft_get_ptr(unsigned long arg)
{
	int		i;
	char	*ptr;

	i = ft_ptr_len(arg);
	ptr = (char *)malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	i--;
	while (arg != 0)
	{
		if ((arg % 16) < 10)
			ptr[i] = (arg % 16) + 48;
		else
			ptr[i] = (arg % 16) + 87;
		arg = arg / 16;
		i--;
	}
	return (ptr);
}

int	ft_put_ptr(char *ptr, t_flags *f)
{
	int	len;

	if (f->minus == 1)
	{
		write(1, "0x", 2);
		len = ft_put_str(ptr) + 2;
		len = len + ft_put_width(' ', f->width - len);
	}
	else
	{
		len = ft_strlen(ptr);
		len = ft_put_width(' ', f->width - len - 2);
		write(1, "0x", 2);
		len = len + 2 + ft_put_str(ptr);
	}
	return (len);
}

int	ft_process_ptr(va_list *ap, t_flags *f, int len)
{
	unsigned long	arg;
	char			*ptr;

	arg = va_arg(*ap, unsigned long);
	if (arg == 0 && f->precision == 0)
	{
		len = len + ft_put_ptr("\0", f);
		return (len);
	}
	if (arg == 0)
	{
		len = len + ft_put_ptr("0", f);
		return (len);
	}
	ptr = ft_get_ptr(arg);
	if (ptr == NULL)
		return (-1);
	len = len + ft_put_ptr(ptr, f);
	free (ptr);
	return (len);
}
