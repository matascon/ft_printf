#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
    va_list args;
	char	*str;
	int		i;
	double		j;

	va_start(args, format);
	str = ft_strdup(format);
	i = va_arg(args, int);
	j = va_arg(args, double);
	printf("%s\n%i\n%.2lf", str, i, j);
	printf("\n");
	va_end(args);
	return (0);
}

int		main()
{
	int 	i;
	double	j;

	i = 1;
	j = 3.14;
	ft_printf("This is a test", i, j);
    return (0);
}
