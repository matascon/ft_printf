/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:22:32 by matascon          #+#    #+#             */
/*   Updated: 2020/07/21 09:15:29 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*aux_parse_unsg(t_data *data, char *str, int width, int len_str)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX || \
	(unsigned)(data->printed + len_str <= (unsigned)INT_MAX))
	{
		if (data->dash)
		{
			data = ft_put_str(str, len_str, data);
			data = ft_put_space(width - len_str, data);
		}
		else
		{
			if (data->zero && !(data->dot))
				data = ft_put_zero(width - len_str, data);
			else
				data = ft_put_space(width - len_str, data);
			data = ft_put_str(str, len_str, data);
		}
	}
	else
		data->error = 1;
	return (data);
}

static t_data	*parse_unsigned(t_data *data, int width, int precision)
{
	unsigned		var;
	char			*str;
	int				length;

	var = va_arg(data->args, unsigned);
	if (data->dot && precision < 1 && var == 0)
		str = ft_strdup("");
	else
	{
		str = ft_itoa_base(var, "0123456789");
		length = 0;
		while (str[length] != '\0')
			length++;
		str = ft_join_precision(precision - length, str);
	}
	length = 0;
	while (str[length] != '\0')
		length++;
	data = aux_parse_unsg(data, str, width, length);
	free(str);
	return (data);
}

t_data			*ft_print_unsigned(t_data *data)
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
	data = parse_unsigned(data, width, precision);
	return (data);
}
