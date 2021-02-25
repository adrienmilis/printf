#include <stdarg.h>
#include <stdio.h>

/*void	print_ints(char *test, ...)
{
	int		i;
	int		value;
	va_list	args;

	va_start(args, test);
	i = 0;
	char *str = "int";
	while (i < 4)
	{
		value = va_arg(args, str);
		printf("%d : [%d]\n", i + 1, value);
		i++;
	}
	va_end(args);
}*/

void	print_arg(va_list args)
{
	int value;

	value = va_arg(args, int);
	printf("%d\n", value);
}

void	variatic(char *test, ...)
{
	va_list args;

	va_start(args, test);
	print_arg(args);
	va_end(args);
}

int		main()
{
	variatic("test", 10);
	return (0);
}
