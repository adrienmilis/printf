#include <stdio.h>

int main()
{
	int i = -1500;
	char	*s = "test";
	void	*ptr = &i;
	void	*ptr2 = s;

	printf("%p\n", ptr);
	printf("%p\n", s);
	printf("i : %i\n", i);
	printf("u : %u\n", i);
	printf("x : %x\n", i);
	printf("X : %X\n", i);
	return (0);
}