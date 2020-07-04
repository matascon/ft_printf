#include "ft_printf.h"

int		ft_star_pop(t_data **data)
{
	int	x;

	x = va_arg((*data)->args, int);
	return (x);
}

t_data	*ft_print_time(t_data *data)
{
	if (data->type == 'c')
		data = ft_print_char(data);
	return (data);
}
