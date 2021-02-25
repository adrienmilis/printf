#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	dec_to_hex(unsigned long n, int lower)
{
	char		*base;
	char		modulo;
	static int	i;

	base = "0123456789abcdef0123456789ABCDEF";
	if (lower == 0)
		modulo = base[(n % 16) + 16];
	else
		modulo = base[n % 16];
	if (n / 16 == 0)
	{
		ft_putchar(modulo);
		i++;
		return (i);
	}
	dec_to_hex(n / 16, lower);
	ft_putchar(modulo);
	i++;
	return (i);
}

int main()
{
	int count;

	count = dec_to_hex(2147483647, 1);
	printf("\n");
	printf("%d\n", count);
	return (0);
}