/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <amilis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:01:05 by amilis            #+#    #+#             */
/*   Updated: 2021/03/10 12:44:13 by amilis           ###   ########.fr       */
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
	if (nb >= INT_MAX)
		return (INT_MAX);
	return ((int)(nb * signe));
}

int	dec_to_hex(unsigned long n, int lower, int first_call)
{
	char		*base;
	char		modulo;
	static int	count;

	if (first_call == 1)
		count = 0;
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
	dec_to_hex(n / 16, lower, 0);
	ft_putchar(modulo);
	count++;
	return (count);
}

int	ft_putnbr(long n, int first_call)
{
	long		number;
	static int	count;

	if (first_call == 1)
		count = 0;
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
		ft_putnbr(number / 10, 0);
		ft_putnbr(number % 10, 0);
	}
	return (count);
}

int	print_pointer(void *ptr, int is_point)
{
	int i;

	ft_putstr("0x");
	if (is_point == 1 && ptr == 0)
		return (2);
	i = dec_to_hex((unsigned long)ptr, 1, 1);
	return (i + 2);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
