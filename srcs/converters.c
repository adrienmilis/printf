/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amilis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:01:05 by amilis            #+#    #+#             */
/*   Updated: 2021/02/18 15:01:06 by amilis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
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

void	dec_to_hex(int n, int lower)
{
	unsigned int 	nb_unsigned;
	char			*base;
	char			modulo;

	base = "0123456789abcdef0123456789ABCDEF";
	if (n < 0)
	{
		nb_unsigned = -n;
		ft_putchar('-');
	}
	else
		nb_unsigned = n;
	if (lower == 1)
		modulo = base[nb_unsigned % 16];
	else
		modulo = base[(nb_unsigned % 16) + 16];
	if (nb_unsigned / 16 == 0)
	{
		ft_putchar(modulo);
		return ;
	}
	dec_to_hex(nb_unsigned / 16, lower);
	ft_putchar(modulo);
	return ;
}

void	ft_putnbr(int n)
{
	unsigned int	nb_unsigned;

	if (n < 0)
	{
		ft_putchar('-');
		nb_unsigned = (unsigned int)(-1 * n);
	}
	else
		nb_unsigned = (unsigned int)(n);
	if (nb_unsigned < 10)
		ft_putchar(48 + nb_unsigned);
	else
	{
		ft_putnbr(nb_unsigned / 10);
		ft_putnbr(nb_unsigned % 10);
	}
}

int main()
{
	ft_putnbr(2147483647);
	return (0);
}