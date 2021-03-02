/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:52:57 by amilis            #+#    #+#             */
/*   Updated: 2021/02/26 17:52:59 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_minus(const char *str, va_list args, int width)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (width < 0)
		width *= -1;
	while (!is_type(str[i]) && str[i] != '.')
		i++;
	if (is_type(str[i]))
		len = print_conversions(str[i], args);
	else if (str[i] == '.')
		len = flag_point(str + i + 1, args, 0, 0);
	if (len < width)
		print_spaces(width - len);
	if (len - width < 0)
		return (len + width - len);
	else
		return (len);
}

int	flag_zero_int(va_list args, int width, int len_conv)
{
	long	arg;

	arg = va_arg(args, int);
	if (arg < 0)
		ft_putchar('-');
	if (len_conv < width)
		print_zeroes(width - len_conv);
	if (arg < 0)
		ft_putnbr(-arg, 1);
	else
		ft_putnbr(arg, 1);
	if (len_conv < width)
		return (width);
	else
		return (len_conv);
}

int	flag_zero(const char *str, va_list args)
{
	int		width;
	int		sign;
	int		len_conv;
	va_list args_cpy;
	int		i;
	int 	prec;
	char	type;

	i = 0;
	va_copy(args_cpy, args);
	while (!is_type(str[i]))
		i++;
	type = str[i];
	i = 0;
	while (!is_type(str[i]) && str[i] != '-' && str[i] != '.')
		i++;
	width = get_width(str, args, args_cpy);
	if (str[i] == '.' && type != '%')
	{
		prec = get_width(str + i + 1, args_cpy, 0); // get la width avant pour avoir la bonne prec (on ne peut pas avoir direct la prec)
		if (prec >= 0)
			return (flag_width(str, args, 1, width));
		while (!is_type(str[i]))
			i++;
	}
//	width = get_width(str, args, args_cpy);
	if (width < 0 || str[i] == '-')
		return (flag_minus(str + 1, args, width));
	if ((len_conv = get_len_conv(str[i], args_cpy, &sign)) == -1)
		len_conv = 1;
	if (sign == 1)
		len_conv++;
	if (str[i] == 'd' || str[i] == 'i')
		return (flag_zero_int(args, width, len_conv));
	if (len_conv < width)
		print_zeroes(width - len_conv);
	print_conversions(str[i], args);
	return ((len_conv < width) ? width : len_conv);
}
