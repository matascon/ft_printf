/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 08:22:42 by matascon          #+#    #+#             */
/*   Updated: 2020/07/07 12:23:45 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*aux_parse_pointer(t_data *data, int width, char *str, int len)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX \
	|| (unsigned)(data->printed + len) <= (unsigned)INT_MAX)
	{
		if (data->dash)
		{
			data = ft_put_str(str, len, data);
			data = ft_put_space(width - len, data);
		}
		else
		{
			data = ft_put_space(width - len, data);
			data = ft_put_str(str, len, data);
		}
	}
	else
		data->error = 1;
	return (data);
}

static t_data	*parse_pointer(t_data *data, int width)
{
	unsigned long	var;
	char			*str;
	int				length_str;

	var = va_arg(data->args, unsigned long);
	str = ft_itoa_base(var, "0123456789abcdef");
	str = ft_strjoin("0x", str);
	length_str = 0;
	while (str[length_str] != '\0')
		length_str++;
	data = aux_parse_pointer(data, width, str, length_str);
	return (data);
}

t_data			*ft_print_pointer(t_data *data)
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
	data = parse_pointer(data, width);
	return (data);
}
