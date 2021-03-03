/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:09:54 by amilis            #+#    #+#             */
/*   Updated: 2021/03/03 12:10:45 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h> // a enlever

int		is_space(char c);
int		is_type(char c);
int		ft_strlen(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);

int		ft_atoi(const char *str);
int		dec_to_hex(unsigned long n, int lower, int first_call);
int		ft_putnbr(long n, int first_call);
int		print_pointer(void *ptr);
int		is_number(char c);

int		get_len_conv2(char type, va_list args_cpy);
int		get_len_conv(char type, va_list args_cpy, int *sign);
int		arg_len(long long i, int base);
void	print_zeroes(int n);
void	print_spaces(int n);

void	ft_putstr_trunc(char *str, int len);
int		print_conversions(char type, va_list args);
int		flags(const char *str, va_list args);
int		ft_printf_start(const char *str, va_list args);
int		ft_printf(const char *str, ...);

int		get_width(const char *str, va_list args, va_list args_cpy);
int		flag_point_int(va_list args, int prec);
int		flag_point_unsigned(va_list args, int prec, char type);
int		flag_point(const char *str, va_list args, int prec_as_param, int prec);

int		width_int(va_list args, int width, char type);
int		width_unsigned(va_list args, int width, char type, int base);
int		width_char_or_string(va_list args, int width, char type);
int		width_point(const char *str, va_list args, int width, va_list args_cpy);
int		flag_width(const char *str, va_list args,
					int width_as_param, int width);

int		flag_minus(const char *str, va_list args, int width);
int		flag_zero_int(va_list args, int width, int len_conv);
int		flag_zero2(const char *str, va_list args, va_list args_cpy, int width);
int		flag_zero(const char *str, va_list args);

#endif
