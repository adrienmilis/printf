/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:06:51 by amilis            #+#    #+#             */
/*   Updated: 2021/02/25 16:06:52 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		arg_len(long long i, int base)
{
	int	len;

	len = 0;
	if (i < 0)
		i = -i;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= base;
		len++;
	}
	return (len);
}

int		get_len_conv2(char type, va_list args_cpy, int is_point)
{
	unsigned int	arg_unsigned;
	int				base;
	unsigned long	ptr;

	if (type == 'p')
	{
		ptr = (unsigned long)va_arg(args_cpy, void*);
		if (ptr == 0 && is_point == 1)
			return (2);
		return (arg_len(ptr, 16) + 2);
	}
	arg_unsigned = va_arg(args_cpy, unsigned int);
	if (type == 'u')
		base = 10;
	else
		base = 16;
	if (arg_unsigned == 0)
		return (-1);
	return (arg_len(arg_unsigned, base));
}

int		get_len_conv(char type, va_list args_cpy, int *sign, int is_point)
{
	int	len_conv;
	int	arg_int;

	*sign = 0;
	if (type == '%')
		return (1);
	if (type == 'd' || type == 'i')
	{
		if ((arg_int = va_arg(args_cpy, int)) == 0)
			return (-1);
		*sign = (arg_int < 0) ? 1 : 0;
		return (arg_len(arg_int, 10));
	}
	if (type == 'u')
		return (get_len_conv2(type, args_cpy, 0));
	if (type == 'x' || type == 'X')
		return (get_len_conv2(type, args_cpy, 0));
	if (type == 'p')
		return (get_len_conv2(type, args_cpy, is_point));
	if (type == 's')
		len_conv = ft_strlen(va_arg(args_cpy, char*));
	if (type == 'c')
		len_conv = 1;
	return (len_conv);
}

void	print_zeroes(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, "0", 1);
		i++;
	}
}

void	print_spaces(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
}
