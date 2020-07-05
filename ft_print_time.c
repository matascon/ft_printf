#include "ft_printf.h"

int		ft_star_pop(t_data **data)
{
	int	x;

	x = va_arg((*data)->args, int);
	return (x);
}

t_data	*ft_put_space(int num_spaces, t_data *data)
{
	int	i;

	i = -1;
	while (++i < num_spaces)
	{
		ft_putchar_fd(' ', 1);
		(data->printed)++;
	}
	return (data);
}

t_data	*ft_put_str(char *str, int length, t_data *data)
{
	int	i;

	i = -1;
	while (++i < length)
	{
		ft_putchar_fd(str[i], 1);
		(data->printed)++;
	}
	return (data);
}

t_data	*ft_print_time(t_data *data)
{
	if (data->type == 'c')
		data = ft_print_char(data);
	else if (data->type == 's')
		data = ft_print_str(data);
	return (data);
}
