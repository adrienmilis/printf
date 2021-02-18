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

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
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

char	*dec_to_hex(int n)
{

}


