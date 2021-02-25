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

int	flag_minus(const char *str, va_list args)
{
	return (0);
}

/*int	flag_zero(const char *str)
{

}*/

int	get_precision(const char *str, va_list args)
{
	if (str[0] == '*')
		return (va_arg(args, int));
	else if (is_number(str[0]))
		return (ft_atoi(str));
	else
		return (0);
}

int	flag_point_int(const char *str, va_list args, int prec)
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
		arg < (0) ? ft_putnbr(-arg) : ft_putnbr(arg);
		if (arg < 0)
			return (diff + arg_len(arg, 10) + 1);
		else
			return (diff + arg_len(arg, 10));
	}
	else
	{
		ft_putnbr(arg);
		if (arg < 0)
			return (arg_len(arg, 10) + 1);
		else
			return (arg_len(arg, 10));
	}
}

int	flag_point_unsigned(const char *str, va_list args, int prec, char type)
{
	unsigned int	arg;
	int				diff;
	int				base;

	if (type == 'u')
		base = 10;
	else
		base = 16;
	arg = va_arg(args, unsigned int);
	if (arg == 0 && prec == 0)
		return (0);
	if ((diff = prec - arg_len(arg, base)) > 0)
		print_zeroes(diff);
	if (type == 'u')
		ft_putnbr(arg);
	if (type == 'x')
		dec_to_hex(arg, 1);
	if (type == 'X')
		dec_to_hex(arg, 0);
	if (diff > 0)
		return (diff + arg_len(arg, base));
	else
		return (arg_len(arg, base));
}

int	flag_point(const char *str, va_list args)
{
	int				prec;
	int				i;
	char			*arg_str;

	i = 0;
	prec = get_precision(str, args);
	while (!is_type(str[i]))
		i++;
	if (str[i] == 'd' || str[i] == 'i')
		return (flag_point_int(str, args, prec));
	if (str[i] == 'u')
		return (flag_point_unsigned(str, args, prec, str[i]));
	if (str[i] == 'x' || str[i] == 'X')
		return (flag_point_unsigned(str, args, prec, str[i]));
	if (str[i] == 's')
	{
		arg_str = va_arg(args, char*);
		if (ft_strlen(arg_str) > prec)
			write(1, arg_str, prec);
		else
			ft_putstr(arg_str);
		return (ft_strlen(arg_str) > prec ? prec : ft_strlen(arg_str));
	}
	else
		return (print_conversions(str[i], args));
}

/*int flag_asterisk(const char *str)
{

}
*/
