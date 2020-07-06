/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:13:57 by matascon          #+#    #+#             */
/*   Updated: 2020/07/06 11:02:47 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*aux_parse_str(t_data *data, char *str, int width, int len_str)
{
	if ((unsigned int)(data->printed + width) <= (unsigned int)INT_MAX \
	|| (unsigned int)(data->printed + len_str) <= (unsigned int)INT_MAX)
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
	int		length;

	var = va_arg(data->args, char *);
	length = 0;
	while (var[length] != '\0')
		length++;
	if (precision == -1)
		data = aux_parse_str(data, var, width, length);
	else
	{
		if (precision <= length)
			length = precision;
		data = aux_parse_str(data, var, width, length);
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
