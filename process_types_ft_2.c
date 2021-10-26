/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_types_ft_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:28 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 15:40:32 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_str_itoa(long int n, long int l, long int rank)
{
	long int	i;
	char		*str;

	str = (char *)malloc(sizeof(*str) * (l + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -1 * n;
		str[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (i < l)
	{
		str[i] = n / rank + '0';
		n = n - rank * (n / rank);
		rank = rank / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	n1;
	long int	rank;
	long int	l;

	n1 = n;
	if (n1 < 0)
	{
		n1 = -1 * n1;
		l = 2;
	}
	else
		l = 1;
	rank = 1;
	while (n1 >= 10)
	{
		n1 = n1 / 10;
		rank = rank * 10;
		l++;
	}
	n1 = n;
	str = ft_get_str_itoa(n1, l, rank);
	return (str);
}

char	*ft_get_str_uns_itoa(unsigned int n, unsigned int l, unsigned int rank)
{
	unsigned int	i;
	char			*str;

	str = (char *)malloc(sizeof(*str) * (l + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		str[i] = n / rank + '0';
		n = n - rank * (n / rank);
		rank = rank / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_uns_itoa(unsigned int n)
{
	char			*str;
	unsigned int	n1;
	unsigned int	rank;
	unsigned int	l;

	n1 = n;
	l = 1;
	rank = 1;
	while (n1 >= 10)
	{
		n1 = n1 / 10;
		rank = rank * 10;
		l++;
	}
	str = ft_get_str_uns_itoa(n, l, rank);
	return (str);
}
