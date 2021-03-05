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

int	width_int(va_list args, int width, char type)
{
	int	arg_num;
	int	len_conv;

	if (type == '%')
	{
		print_spaces(width - 1);
		ft_putchar('%');
		width = (width - 1 > 0) ? width : 1;
		return (width);
	}
	arg_num = va_arg(args, int);
	len_conv = arg_len(arg_num, 10);
	if (arg_num < 0)
		len_conv += 1;
	print_spaces(width - len_conv);
	ft_putnbr(arg_num, 1);
	if (width - len_conv > 0)
		return (width);
	return (len_conv);
}

int	width_unsigned(va_list args, int width, char type, int base)
{
	unsigned int	arg_unsigned;
	int				len_conv;
	void			*ptr;

	if (type == 'u' || type == 'x' || type == 'X')
		arg_unsigned = va_arg(args, unsigned int);
	if (type == 'u' || type == 'x' || type == 'X')
		len_conv = arg_len(arg_unsigned, base);
	if (type == 'p')
		ptr = va_arg(args, void*);
	if (type == 'p')
		len_conv = arg_len((unsigned long)(ptr), 16) + 2;
	if (len_conv < width)
		print_spaces(width - len_conv);
	if (type == 'u')
		ft_putnbr(arg_unsigned, 1);
	if (type == 'x')
		dec_to_hex(arg_unsigned, 1, 1);
	if (type == 'X')
		dec_to_hex(arg_unsigned, 0, 1);
	if (type == 'p')
		print_pointer(ptr, 0);
	if (len_conv < width)
		return (width);
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
	prec = get_width(str, args, args_cpy);
	while (!is_type(str[i]))
		i++;
	len = get_len_conv(str[i], args_cpy, &sign, 1);
	len_print = (prec == 0 && len == -1) ? 0 : 1;
	if (prec < len && str[i] != 's' && str[i] != 'c' && len != -1)
		len_print = (sign == 1) ? (len + 1) : len;
	else if (prec >= len && prec >= 0 && str[i] != 's' && str[i] != 'c')
		len_print = (sign == 1) ? (prec + 1) : prec;
	else if (str[i] == 's')
		len_print = (len > prec && prec >= 0) ? prec : len;
	if (len_print < width)
		print_spaces(width - len_print);
	len = flag_point(str, args, 1, prec);
	if (len_print < width)
		return (width);
	return (len);
}

int	flag_width(const char *str, va_list args, int width_as_param, int width)
{
	int		len_ret;
	va_list	args_cpy;
	int		base;

	va_copy(args_cpy, args);
	if (width_as_param == 0)
		width = get_width(str, args, args_cpy);
	if (width < 0)
		return (flag_minus(str, args, width));
	while (!is_type(str[0]) && str[0] != '.')
		str++;
	base = (str[0] == 'u') ? 10 : 16;
	if (is_type(str[0]))
	{
		if (str[0] == 'd' || str[0] == 'i' || str[0] == '%')
			len_ret = width_int(args, width, str[0]);
		if (str[0] == 'u' || str[0] == 'x' || str[0] == 'X' || str[0] == 'p')
			len_ret = width_unsigned(args, width, str[0], base);
		if (str[0] == 'c' || str[0] == 's')
			len_ret = width_char_or_string(args, width, str[0]);
	}
	else
		len_ret = width_point(str + 1, args, width, args_cpy);
	return (len_ret);
}
