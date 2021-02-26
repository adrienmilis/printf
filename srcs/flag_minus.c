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

int	flag_minus(const char *str, va_list args)
{
	int	width;
	int	len;
	int	i;

	i = 0;
	width = get_width(str, args);
	while (!is_type(str[i]) && str[i] != '.')
		i++;
	if (is_type(str[i]))
		len = print_conversions(str[i], args);
	else if (str[i] == '.')
		len = flag_point(str + i + 1, args);
	if (len < width)
		print_spaces(width - len);
	if (len - width < 0)
		return (len + width - len);
	else
		return (len);
}
