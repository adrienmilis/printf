/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:25:43 by amilis            #+#    #+#             */
/*   Updated: 2021/02/23 13:25:44 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_conversions(char type, va_list args)
{
	int	len; //va retourner la longueur de ce qui a été print

	if (type == 'c')
	{
		ft_putchar(va_arg(args, int));
		len = 1;
	}
	if (type == 's')
		len = ft_putstr(va_arg(args, char*));
	if (type == 'p')
		len = print_pointer(va_arg(args, void*));
	if (type == 'd' || type == 'i' || type == 'u')
		len = ft_putnbr(va_arg(args, long));
	if (type == 'x')
		len = dec_to_hex(va_arg(args, unsigned int), 1);
	if (type == 'X')
		len = dec_to_hex(va_arg(args, unsigned int), 0);
	return (len);
	// verifier que la len retournee est la bonne
}

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list args;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			ft_putchar(str[i++]);
		if (str[i] == 0)
			return i;
		i++;
		if (is_type(str[i]))
			print_conversions(str[i++], args);
		else if (str[i] == '-')
			printf("rien\n");//fonction pour gerer le -
		else if (str[i] == '0')
			printf("rien\n");//fonction pour gerer le 0
		else if (str[i] == '.')
			printf("rien\n");//fonction pour gerer le .
		else if (str[i] == '*')
			printf("rien\n");//fonction pour gerer l'etoile
		else
			ft_putchar(str[i++]); //gere le % et les mauvais types normalement
	}
	va_end(args);
	return (i + 1);
}

int main()
{
	unsigned int	i = 2147483647;
	char	*s = "ceci est un test";
	char 	c = 'a';

	ft_printf("ptr : [%kw]\n");
	printf("ptr : [%kw]\n");
	return (0);
}