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

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
}

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

void	ft_putstr_trunc(char *str, int len)
{
	char	*trunc_str;

	if (str == NULL)
		trunc_str = "(null)";
	else
		trunc_str = str;
	write(1, trunc_str, len);
}
