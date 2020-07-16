/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:23:34 by matascon          #+#    #+#             */
/*   Updated: 2020/07/16 11:23:36 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_str_upper(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
	return (str);
}

static t_data	*aux_parse_hex(t_data *data, char *str, int width, int len_str)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX || \
	(unsigned)(data->printed + len_str) <= (unsigned)INT_MAX)
	{
		if (data->dash)
		{
			data = ft_put_str(str, len_str, data);
			data = ft_put_space(width - len_str, data);
		}
		else
		{
			if (data->dot || !(data->zero))
				data = ft_put_space(width - len_str, data);
			else if (data->zero)
				data = ft_put_zero(width - len_str, data);
			data = ft_put_str(str, len_str, data);
		}
	}
	else
		data->error = 1;
	return (data);
}

static t_data	*parse_hex(t_data *data, int width, int precision)
{
	unsigned	var;
	char		*str;
	int			length;

	var = va_arg(data->args, unsigned);
	str = ft_itoa_base(var, "0123456789abcdef");
	if (data->dot && precision == 0 && var == 0)
		str = ft_strdup("");
	else
	{
		length = 0;
		while (str[length] != '\0')
			length++;
		str = ft_join_precision(precision - length, str);
	}
	length = 0;
	while (str[length] != '\0')
		length++;
	if (data->type == 'X')
		str = ft_str_upper(str);
	data = aux_parse_hex(data, str, width, length);
	return (data);
}

t_data			*ft_print_hex(t_data *data)
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
	data = parse_hex(data, width, precision);
	return (data);
}
