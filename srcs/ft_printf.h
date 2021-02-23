/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:51:13 by amilis            #+#    #+#             */
/*   Updated: 2021/02/23 11:51:15 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> // a enlever !!

int		is_space(char c);
int		is_type(char c);
void	ft_putchar(char c);
int		ft_putstr(char *str);

int		ft_atoi(const char *str);
int		dec_to_hex(unsigned int n, int lower);
int		ft_putnbr(long n);
int		print_pointer(void	*ptr);


#endif
