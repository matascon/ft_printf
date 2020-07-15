/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:22:32 by matascon          #+#    #+#             */
/*   Updated: 2020/07/15 09:40:35 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*aux_parse_u(t_data *data, char *str, int width, int len_str)
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

static t_data	*parse_unsigned(t_data *data, int width, int precision)
{
	unsigned		var;
	char			*str;
	int				length;

	var = va_arg(data->args, unsigned);
	str = ft_itoa_base(var, "0123456789");
	if (data->dot && precision < 1 && str[0] == '0')
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
	data = aux_parse_u(data, str, width, length);
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
	data = parse_unsigned(data, width, precision);
	return (data);
}
