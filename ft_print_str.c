#include "ft_printf.h"

static t_data	*aux_parse(t_data *data, char *str, int width, int len_str)
{
	if (data->printed + width <= INT_MAX)
	{
		if (data->dash)
		{
			data = ft_put_str(str, len_str, data);
			data = ft_put_space(width - len_str, data);
		}
		else
		{
			data = ft_put_space(width - len_str, data);
			data = ft_put_str(str, len_str, data);
		}
	}
	else
		data->error = 1;
	return (data);
}

static t_data	*parse_str(t_data *data, int width, int precision)
{
	char	*var;
	int		len_str;

	var = (char *)va_arg(data->args, char *);
	len_str = ft_strlen(var);
	if (precision == -1)
		data = aux_parse(data, var, width, len_str);
	else
	{
		if (precision <= len_str)
			len_str = precision;
		data = data = aux_parse(data, var, width, len_str);		
	}
	return (data);
}

t_data			*ft_print_str(t_data *data)
{
	int		width;
	int		precision;

	width = 0;
	precision = -1;
	if (data->star_w)
		width = ft_star_pop(&data);
	else if (data->width)
		width = ft_atoi(data->width);
	if (data->star_p)
		precision = ft_star_pop(&data);
	else if (data->precision)
		precision = ft_atoi(data->precision);
	data = parse_str(data, width, precision);
	return (data);
}
