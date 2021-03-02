/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:06:43 by amilis            #+#    #+#             */
/*   Updated: 2021/02/25 16:06:45 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width(const char *str, va_list args, va_list args_cpy)
{
	int	i;

	i = 0;
	while (str[i] != '*' && !(str[i] >= '1' && str[i] <= '9')
		&& str[i] != '.' && !is_type(str[i]))
		i++;
	if (str[i] == '*')
	{
		if (args_cpy != 0)
			va_arg(args_cpy, int);
		return (va_arg(args, int));
	}
	else if (is_number(str[i]))
		return (ft_atoi(str));
	else
		return (0);
}

int	flag_point_int(va_list args, int prec)
{
	long	arg;
	int		diff;

	arg = va_arg(args, int);
	if (arg == 0 && prec == 0)
		return (0);
	if ((diff = prec - arg_len(arg, 10)) > 0)
	{
		if (arg < 0)
			ft_putchar('-');
		print_zeroes(diff);
		arg < (0) ? ft_putnbr(-arg, 1) : ft_putnbr(arg, 1);
		if (arg < 0)
			return (diff + arg_len(arg, 10) + 1);
		else
			return (diff + arg_len(arg, 10));
	}
	else
	{
		ft_putnbr(arg, 1);
		if (arg < 0)
			return (arg_len(arg, 10) + 1);
		else
			return (arg_len(arg, 10));
	}
}

int	flag_point_unsigned(va_list args, int prec, char type)
{
	unsigned int	arg;
	int				diff;
	int				base;
	int				len_conv;

	if (type == 'u')
		base = 10;
	else
		base = 16;
	arg = va_arg(args, unsigned int);
	len_conv = arg_len(arg, base);
	if (arg == 0 && prec == 0)
		return (0);
	if ((diff = prec - len_conv) > 0)
		print_zeroes(diff);
	if (type == 'u')
		ft_putnbr(arg, 1);
	if (type == 'x')
		dec_to_hex(arg, 1, 1);
	if (type == 'X')
		dec_to_hex(arg, 0, 1);
	if (diff > 0)
		return (diff + len_conv);
	else
		return (len_conv);
}

int	flag_point(const char *str, va_list args, int prec_as_param, int prec)
{
	char	*arg_str;

	if (prec_as_param == 0)
		prec = get_width(str, args, 0);
	while (!is_type(str[0]))
		str++;
	if (str[0] == 'd' || str[0] == 'i')
		return (flag_point_int(args, prec));
	if (str[0] == 'u')
		return (flag_point_unsigned(args, prec, str[0]));
	if (str[0] == 'x' || str[0] == 'X')
		return (flag_point_unsigned(args, prec, str[0]));
	if (str[0] == 's')
	{
		arg_str = va_arg(args, char*);
		if (ft_strlen(arg_str) > prec && prec >= 0)
		{
			ft_putstr_trunc(arg_str, prec);
			return (prec);
		}
		return (ft_putstr(arg_str));
	}
	else
		return (print_conversions(str[0], args));
}
