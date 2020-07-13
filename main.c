#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	int 	i;

	printf("\n00000000000000000000000000000000000000000000000\n\n");
	i = ft_printf("%c\n", '\0');
	printf("%i\n", i);
	i = printf("%c\n", '\0');
	printf("%i\n", i);
	printf("\n11111111111111111111111111111111111111111111111\n\n");
	i = ft_printf("%c\n", '\0');
	printf("%i\n", i);
	i = printf("%c\n", '\0');
	printf("%i\n", i);
	printf("\n22222222222222222222222222222222222222222222222\n\n");
	i = ft_printf("%5c\n", '\0');
	printf("%i\n", i);
	i = printf("%5c\n", '\0');
	printf("%i\n", i);
	printf("\n33333333333333333333333333333333333333333333333\n\n");
	i = ft_printf("%-5c\n", '\0');
	printf("%i\n", i);
	i = printf("%-5c\n", '\0');
	printf("%i\n", i);
	printf("\n44444444444444444444444444444444444444444444444\n\n");
	i = ft_printf("%1$\n");
	printf("%i\n", i);
	i = printf("%1$\n");
	printf("%i\n", i);
	printf("\n55555555555555555555555555555555555555555555555\n\n");
	i = ft_printf("%0\n");
	printf("%i\n", i);
	i = printf("%0\n");
	printf("%i\n", i);
	printf("\n66666666666666666666666666666666666666666666666\n\n");
	i = ft_printf("% \n");
	printf("%i\n", i);
	i = printf("% \n");
	printf("%i\n", i);
	printf("\n77777777777777777777777777777777777777777777777\n\n");
	i = ft_printf("%#\n");
	printf("%i\n", i);
	i = printf("%#\n");
	printf("%i\n", i);
	printf("\n88888888888888888888888888888888888888888888888\n\n");
	i = ft_printf("%-\n");
	printf("%i\n", i);
	i = printf("%-\n");
	printf("%i\n", i);
	printf("\n99999999999999999999999999999999999999999999999\n\n");
	i = ft_printf("%+\n");
	printf("%i\n", i);
	i = printf("%+\n");
	printf("%i\n", i);
	printf("\n10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10\n\n");
	i = ft_printf("%23");
	printf("%i\n", i);
	i = printf("%23");
	printf("%i\n", i);
	printf("\n11 11 11 11 11 11 11 11 11 11 11 11 11 11 11 11\n\n");
	i = ft_printf("%.");
	printf("%i\n", i);
	i = printf("%.");
	printf("%i\n", i);
	printf("\n12 12 12 12 12 12 12 12 12 12 12 12 12 12 12 12\n\n");
	i = ft_printf("Mateo Tascon %10s xd\n", "Gomez");
	printf("%i\n", i);
	i = printf("Mateo Tascon %10s xd\n", "Gomez");
	printf("%i\n", i);
	printf("\n13 13 13 13 13 13 13 13 13 13 13 13 13 13 13 13\n\n");
	i = ft_printf("Mateo Tascon %-10s xd\n", "Gomez");
	printf("%i\n", i);
	i = printf("Mateo Tascon %-10s xd\n", "Gomez");
	printf("%i\n", i);
	printf("\n14 14 14 14 14 14 14 14 14 14 14 14 14 14 14 14\n\n");
	i = ft_printf("\033\n");
	printf("%i\n", i);
	i = printf("\033\n");
	printf("%i\n", i);
	printf("\n15 15 15 15 15 15 15 15 15 15 15 15 15 15 15 15\n\n");
	i = ft_printf("\033\n");
	printf("%i\n", i);
	i = printf("\033\n");
	printf("%i\n", i);
	printf("\n16 16 16 16 16 16 16 16 16 16 16 16 16 16 16 16\n\n");
	ft_printf("\033[1;31m|-----| LE NOTRE |-----|\033[0m\n");
	printf("\033[1;32m|-----| LE VRAI |-----|\033[0m\n");
	printf("\n17 17 17 17 17 17 17 17 17 17 17 17 17 17 17 17\n\n");
	i = ft_printf("%-05c xd\n", 0);
	printf("%i\n", i);
	i = printf("%-05c xd\n", 0);
	printf("%i\n", i);
	printf("\n18 18 18 18 18 18 18 18 18 18 18 18 18 18 18 18\n\n");
	printf("{%d}\n", printf("\033[1;32mTest 2 => \033[0m|%05.c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 2 => \033[0m|%05.c|", 'a'));

	printf("{%d}\n", printf("\033[1;32mTest 3 => \033[0m|%c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 3 => \033[0m|%c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 11 => \033[0m|%c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 11 => \033[0m|%c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 12 => \033[0m|%-c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 12 => \033[0m|%-c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 13 => \033[0m|%15c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 13 => \033[0m|%15c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 14 => \033[0m|%-15c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 14 => \033[0m|%-15c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 15 => \033[0m|%.2c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 15 => \033[0m|%.2c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 16 => \033[0m|% c|", 0));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 16 => \033[0m|% c|", 0));

	printf("{%d}\n", printf("\033[1;32mTest 17 => \033[0m|%c|", "coucou"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 17 => \033[0m|%c|", "coucou"));

	printf("{%d}\n", printf("\033[1;32mTest 18 => \033[0m|%05.c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 18 => \033[0m|%05.c|", 'a'));

	printf("{%d}\n", printf("\033[1;32mTest 19 => \033[0m|%015c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 19 => \033[0m|%015c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 20 => \033[0m|%-015c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 20 => \033[0m|%-015c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 21 => \033[0m|%-0c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 21 => \033[0m|%-0c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 22 => \033[0m|%.12c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 22 => \033[0m|%.12c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 23 => \033[0m|%.0c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 23 => \033[0m|%.0c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 24 => \033[0m|%-12.3c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 24 => \033[0m|%-12.3c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 25 => \033[0m|%-3.1c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 25 => \033[0m|%-3.1c|", 'a'));

	printf("{%d}\n", printf("\033[1;32mTest 26 => \033[0m|%12.1c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 26 => \033[0m|%12.1c|", 'a'));

	printf("{%d}\n", printf("\033[1;32mTest 27 => \033[0m|%3.1c|", '4'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 27 => \033[0m|%3.1c|", '4'));

	printf("{%d}\n", printf("\033[1;32mTest 28 => \033[0m|%-c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 28 => \033[0m|%-c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 29 => \033[0m|%3c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 29 => \033[0m|%3c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 30 => \033[0m|%-3c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 30 => \033[0m|%-3c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 31 => \033[0m|%.2c|", 'a'));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 31 => \033[0m|%.2c|", 'a'));

	printf("{%d}\n", printf("\033[1;32mTest 32 => \033[0m|%5.5c|", "N"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 32 => \033[0m|%5.5c|", "N"));

	printf("{%d}\n", printf("\033[1;32mTest 33 => \033[0m|%7.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 33 => \033[0m|%7.5c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 34 => \033[0m|%.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 34 => \033[0m|%.5c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 35 => \033[0m|%.15c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 35 => \033[0m|%.15c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 36 => \033[0m|%15c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 36 => \033[0m|%15c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 37 => \033[0m|%5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 37 => \033[0m|%5c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 38 => \033[0m|%-5.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 38 => \033[0m|%-5.5c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 39 => \033[0m|%-15.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 39 => \033[0m|%-15.5c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 40 => \033[0m|%-.5c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 40 => \033[0m|%-.5c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 41 => \033[0m|%-15c|", "Number 42"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 41 => \033[0m|%-15c|", "Number 42"));

	printf("{%d}\n", printf("\033[1;32mTest 42 => \033[0m|%c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 42 => \033[0m|%c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 43 => \033[0m|%-c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 43 => \033[0m|%-c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 44 => \033[0m|%5.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 44 => \033[0m|%5.5c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 45 => \033[0m|%15.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 45 => \033[0m|%15.5c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 46 => \033[0m|%.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 46 => \033[0m|%.5c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 47 => \033[0m|%15c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 47 => \033[0m|%15c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 48 => \033[0m|%-5.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 48 => \033[0m|%-5.5c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 49 => \033[0m|%-15.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 49 => \033[0m|%-15.5c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 50 => \033[0m|%-.5c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 50 => \033[0m|%-.5c|", NULL));

	printf("{%d}\n", printf("\033[1;32mTest 51 => \033[0m|%-15c|", NULL));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 51 => \033[0m|%-15c|", NULL));
	
	printf("{%d}\n", printf("\033[1;32mTest 52 => \033[0m|%15c|", "bonjour"));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 52 => \033[0m|%15c|", "bonjour"));
	return (0);
}