/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_types_ft_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:19:21 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 15:26:20 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (6);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_width(char space, int width)
{
	int	i;

	i = 0;
	while (width > 0)
	{
		write(1, &space, 1);
		width--;
		i++;
	}
	return (i);
}

int	ft_put_s(char *s, int n)
{
	if (s == NULL)
		write(1, "(null)", n);
	else
		write(1, s, n);
	return (n);
}
