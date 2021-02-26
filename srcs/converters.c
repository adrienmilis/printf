/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:01:05 by amilis            #+#    #+#             */
/*   Updated: 2021/02/23 11:51:08 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	nb;

	nb = 0;
	signe = 1;
	i = 0;
	while (is_space(str[i]) && str[i])
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i++] - 48;
	}
	if (nb >= LONG_MAX && signe == 1)
		return (-1);
	if (nb >= LONG_MAX && signe == -1)
		return (0);
	return ((int)(nb * signe));
}

int	dec_to_hex(unsigned long n, int lower)
{
	char		*base;
	char		modulo;
	static int	count;

	base = "0123456789abcdef0123456789ABCDEF";
	if (lower == 0)
		modulo = base[(n % 16) + 16];
	else
		modulo = base[n % 16];
	if (n / 16 == 0)
	{
		ft_putchar(modulo);
		count++;
		return (count);
	}
	dec_to_hex(n / 16, lower);
	ft_putchar(modulo);
	count++;
	return (count);
}

int	ft_putnbr(long n)
{
	long		number;
	static int	count;

	if (n < 0)
	{
		ft_putchar('-');
		count++;
		number = -n;
	}
	else
		number = n;
	if (number < 10)
	{
		ft_putchar(48 + number);
		count++;
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
	return (count);
}

int	print_pointer(void *ptr)
{
	int i;

	ft_putstr("0x");
	i = dec_to_hex((unsigned long)ptr, 1);
	return (i + 2);
}

int	get_len_conv(char type, va_list args_cpy, int *sign)
{
	int len_conv;
	int	arg_num;

	*sign = 0;
	if (type == 'd' || type == 'i')
	{
		arg_num = va_arg(args_cpy, int);
		if (arg_num < 0)
			*sign = 1;
		len_conv = arg_len(arg_num, 10);
	}
	if (type == 'u')
		len_conv = arg_len(va_arg(args_cpy, unsigned int), 10);
	if (type == 'x' || type == 'X')
		len_conv = arg_len(va_arg(args_cpy, unsigned int), 16);
	if (type == 's')
		len_conv = ft_strlen(va_arg(args_cpy, char*));
	if (type == 'c')
		len_conv = 1;
	return (len_conv);
}
