/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:13:57 by matascon          #+#    #+#             */
/*   Updated: 2020/07/16 10:35:15 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*aux_parse_str(t_data *data, char *str, int width, int len_str)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX \
	|| (unsigned)(data->printed + len_str) <= (unsigned)INT_MAX)
	{
		if (data->dash)
		{
			data = ft_put_str(str, len_str, data);
			data = ft_put_space(width - len_str, data);
		}
		else
		{
			if (data->zero)
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

static t_data	*parse_str(t_data *data, int width, int precision)
{
	char	*var;
	char	*str;
	int		length;

	var = va_arg(data->args, char *);
	length = 0;
	if (!var)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(var);
	while (str[length] != '\0')
		length++;
	if (precision < length && data->dot && precision >= 0)
		length = precision;
	data = aux_parse_str(data, str, width, length);
	free(str);
	return (data);
}

t_data			*ft_print_str(t_data *data)
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
	data = parse_str(data, width, precision);
	return (data);
}
