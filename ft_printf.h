/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:58:02 by gnaida            #+#    #+#             */
/*   Updated: 2021/06/17 18:58:19 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	precision;
	int	star;	
}				t_flags;

int		ft_printf(const char *str, ...);
int		ft_parse_str(const char *str, va_list *ap);
t_flags	ft_init_flags(void);
int		ft_process_types(va_list *ap, t_flags *f, int len);

int		ft_parse_flags(const char *str, va_list *ap, t_flags *f, int i);
int		ft_if_parseable(char s);
int		ft_if_type(char s, t_flags *f);

int		ft_if_digit(const char *str, t_flags *f, int i);
int		ft_if_star(va_list *ap, t_flags *f);
int		ft_if_minus(t_flags *f);
int		ft_if_dot(const char *str, va_list *ap, t_flags *f, int i);

int		ft_put_char(char c);
int		ft_strlen(char *s);
int		ft_put_str(char *str);
int		ft_put_width(char space, int width);
int		ft_put_s(char *s, int n);

char	*ft_get_str_itoa(long int n, long int l, long int rank);
char	*ft_itoa(int n);
char	*ft_get_str_uns_itoa(unsigned int n, unsigned int l, unsigned int rank);
char	*ft_uns_itoa(unsigned int n);

int		ft_process_char(va_list *ap, t_flags *f, int len);
int		ft_process_str(va_list *ap, t_flags *f, int len);
int		ft_process_percent(t_flags *f, int len);

char	*ft_get_hex(unsigned int arg, int X);
int		ft_put_hex(char *hex, t_flags *f);
int		ft_process_hexs(va_list *ap, t_flags *f, int X, int len);

int		ft_ptr_len(unsigned long arg);
char	*ft_get_ptr(unsigned long arg);
int		ft_put_ptr(char *ptr, t_flags *f);
int		ft_process_ptr(va_list *ap, t_flags *f, int len);

void	ft_if_flag_zero_int(t_flags *f, int sign);
int		ft_put_int(char *s, t_flags *f, int sign);
int		ft_process_int(va_list *ap, t_flags *f, int len);
int		ft_put_uns_int(char *s, t_flags *f);
int		ft_process_uns_int(va_list *ap, t_flags *f, int len);

#endif
