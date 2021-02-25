#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	dec_to_hex(unsigned long n, int lower)
{
	char			*base;
	char			modulo;

	base = "0123456789abcdef0123456789ABCDEF";
	if (lower == 0)
		modulo = base[(n % 16) + 16];
	else
		modulo = base[n % 16];
	if (n / 16 == 0)
	{
		ft_putchar(modulo);
		return ;
	}
	dec_to_hex(n / 16, lower);
	ft_putchar(modulo);
	return ;
}

int main()
{
	int	i = 19;
	int	*address = &i;

	ft_putchar('0');
	ft_putchar('x');
	dec_to_hex((unsigned long) address, 1);
	ft_putchar('\n');
	printf("printf : %p\n", &i);
	return (0);
}