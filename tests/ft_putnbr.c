#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putnbr(long n)
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

int main()
{
	int i;

	i = ft_putnbr(LONG_MAX);
	printf("\n");
	printf("%d\n", i);
}