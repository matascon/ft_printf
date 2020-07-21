/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 08:22:42 by matascon          #+#    #+#             */
/*   Updated: 2020/07/21 10:02:44 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*zero_flag(t_data *data, int width, char *str, int len)
{
	if ((unsigned)(data->printed + width + 2) <= (unsigned)INT_MAX \
	|| (unsigned)(data->printed + len + 2) <= (unsigned)INT_MAX)
	{
		data = ft_put_str("0x\0", 2, data);
		data = ft_put_zero(width - len - 2, data);
		data = ft_put_str(str, len, data);
	}
	else
		data->error = 1;
	free(str);
	return (data);
}

static t_data	*no_zero_flag(t_data *data, int width, char *str, int len)
{
	if ((unsigned)(data->printed + width + 2) <= (unsigned)INT_MAX \
	|| (unsigned)(data->printed + len + 2) <= (unsigned)INT_MAX)
	{
		if (data->dash)
		{
			data = ft_put_str("0x\0", 2, data);
			data = ft_put_str(str, len, data);
			data = ft_put_space(width - len - 2, data);
		}
		else
		{
			data = ft_put_space(width - len - 2, data);
			data = ft_put_str("0x\0", 2, data);
			data = ft_put_str(str, len, data);
		}
	}
	else
		data->error = 1;
	free(str);
	return (data);
}

static t_data	*parse_pointer(t_data *data, int width, int precision)
{
	unsigned long	var;
	char			*str;
	int				length_str;

	var = va_arg(data->args, unsigned long);
	str = ft_itoa_base(var, "0123456789abcdef\0");
	length_str = 0;
	while (str[length_str] != '\0')
		length_str++;
	if (data->zero && !(data->dot) && !(data->dash))
		data = zero_flag(data, width, str, length_str);
	else
	{
		if (precision < length_str && data->dot && var == 0)
			length_str = precision;
		else if (precision > length_str)
		{
			str = ft_join_precision(precision - length_str, str);
			length_str = 0;
			while (str[length_str] != '\0')
				length_str++;
		}
		data = no_zero_flag(data, width, str, length_str);
	}
	return (data);
}

t_data			*ft_print_pointer(t_data *data)
{
	int		width;
	int		precision;

	width = 0;
	precision = 0;
	if (data->star_w)
		width = ft_star_pop(&data);
	else if (data->width)
		width = ft_atoi(data->width);
	if (data->star_p)
		precision = ft_star_pop(&data);
	else if (data->precision)
		precision = ft_atoi(data->precision);
	if (width < 0)
	{
		data->dash = '-';
		width *= -1;
	}
	data = parse_pointer(data, width, precision);
	return (data);
}
