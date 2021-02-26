/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:41:13 by amilis            #+#    #+#             */
/*   Updated: 2021/02/25 16:41:14 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_int(va_list args, int width)
{
	int	arg_num;
	int	len_conv;

	arg_num = va_arg(args, int);
	len_conv = arg_len(arg_num, 10);
	if (arg_num < 0)
		len_conv += 1;
	if (width - len_conv > 0)
	{
		print_spaces(width - len_conv);
		ft_putnbr(arg_num);
		return (width);
	}
	else
	{
		ft_putnbr(arg_num);
		if (arg_num < 0)
			return (len_conv);
		else
			return (len_conv);
	}
}

int	width_unsigned(va_list args, int width, char type)
{
	unsigned int	arg_unsigned;
	int				len_conv;
	int				base;

	if (type == 'u')
		base = 10;
	else
		base = 16;
	arg_unsigned = va_arg(args, unsigned int);
	len_conv = arg_len(arg_unsigned, base);
	if (len_conv < width)
		print_spaces(width - len_conv);
	if (type == 'u')
		ft_putnbr(arg_unsigned);
	if (type == 'x')
		dec_to_hex(arg_unsigned, 1);
	if (type == 'X')
		dec_to_hex(arg_unsigned, 0);
	if (len_conv < width)
		return (width);
	else
		return (len_conv);
}

int	width_char_or_string(va_list args, int width, char type)
{
	char	*arg_str;
	char	arg_char;
	int		len_conv;

	if (type == 's')
	{
		arg_str = va_arg(args, char *);
		len_conv = ft_strlen(arg_str);
	}
	if (type == 'c')
	{
		arg_char = va_arg(args, int);
		len_conv = 1;
	}
	if (len_conv < width)
		print_spaces(width - len_conv);
	if (type == 's')
		ft_putstr(arg_str);
	if (type == 'c')
		ft_putchar(arg_char);
	if (len_conv < width)
		return (width);
	else
		return (len_conv);
}

int	width_point(const char *str, va_list args, int width, va_list args_cpy)
{
	int		prec;
	int		len;
	int		len_print;
	int		sign;
	int		i;

	i = 0;
	sign = 0;
	prec = get_width(str, args);
	while (!is_type(str[i]))
		i++;
	len = get_len_conv(str[i], args_cpy, &sign);
	if (prec < len && str[i] != 's' && str[i] != 'c')
		len_print = (sign == 1) ? (len + 1) : len;
	else if (str[i] == 'c')
		len_print = 1;
	else
		len_print = (len > prec) ? prec : len;
	if (len_print < width)
		print_spaces(width - len_print);
	len = flag_point(str, args);
	return ((len_print < width) ? width : len);
}

int	flag_width(const char *str, va_list args)
{
	int		width;
	int		i;
	int		len_ret;
	va_list	args_cpy;

	va_copy(args_cpy, args);
	i = 0;
	width = get_width(str, args);
	while (!is_type(str[i]) && str[i] != '.')
		i++;
	if (is_type(str[i]))
	{
		if (str[i] == 'd' || str[i] == 'i')
			len_ret = width_int(args, width);
		if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
			len_ret = width_unsigned(args, width, str[i]);
		if (str[i] == 'c' || str[i] == 's')
			len_ret = width_char_or_string(args, width, str[i]);
	}
	else
		len_ret = width_point(str + i + 1, args, width, args_cpy);
	return (len_ret);
}
