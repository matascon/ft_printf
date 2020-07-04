#include "ft_printf.h"

static t_data	*parse_char(t_data *data, int width)
{
	char	var;
	int		i;

	var = (char)va_arg(data->args, int);
	i = -1;
	width = width - 1;
	if (data->dash)
	{
		ft_putchar_fd(var, 1);
		(data->printed)++;
		while (++i < width)
		{
			ft_putchar_fd(' ', 1);
			(data->printed)++;
		}
	}
	else
	{
		while (++i < width)
		{
			ft_putchar_fd(' ', 1);
			(data->printed)++;
		}
		ft_putchar_fd(var, 1);
		(data->printed)++;
	}
	return (data);
}

t_data		*ft_print_char(t_data *data)
{
	int		width;
	int		precision;

	width = 0;
	precision = 0;
	if (data->star_w)
		width = ft_star_pop(&data);
	else if (data->width)
		width = ft_atoi(data->width);
	data = parse_char(data, width);
	return (data);
}
