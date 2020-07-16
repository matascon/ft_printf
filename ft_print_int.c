/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:20:14 by matascon          #+#    #+#             */
/*   Updated: 2020/07/16 10:33:12 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*analyze_precision(t_data *data, char *str, int prcs, int var)
{
	int	length;

	if (data->dot && prcs == 0 && var == 0)
		str = ft_strdup("");
	else
	{
		length = 0;
		while (str[length] != '\0')
			length++;
		str = ft_join_precision(prcs - length, str);
	}
	return (str);
}

static t_data	*zero_flag(t_data *data, char *str, int var, int width)
{
	int len_str;

	len_str = 0;
	while (str[len_str] != '\0')
		len_str++;
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX || \
	(unsigned)(data->printed + len_str + data->space) <= (unsigned)INT_MAX)
	{
		data = ft_put_space(data->space, data);
		if (var < 0)
		{
			data = ft_put_str("-", 1, data);
			width--;
		}
		data = ft_put_zero(width - len_str - data->space, data);
		data = ft_put_str(str, len_str, data);
	}
	else
		data->error = 1;
	return (data);
}

static t_data	*no_zero_flag(t_data *data, char *str, int width, int len_str)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX || \
	(unsigned)(data->printed + len_str + data->space) <= (unsigned)INT_MAX)
	{
		data = ft_put_space(data->space, data);
		if (data->dash && !(data->space))
		{
			data = ft_put_str(str, len_str, data);
			data = ft_put_space(width - len_str, data);
		}
		else
		{
			data = ft_put_space(width - len_str - data->space, data);
			data = ft_put_str(str, len_str, data);
		}
	}
	else
		data->error = 1;
	return (data);
}

static t_data	*parse_int(t_data *data, int width, int precision)
{
	int		var;
	char	*str;
	int		length;

	var = va_arg(data->args, int);
	if (var < 0)
		data->space = 0;
	str = ft_itoa_base((long)var, "0123456789");
	str = analyze_precision(data, str, precision, var);
	if (data->zero && !(data->precision) && !(data->dash))
		data = zero_flag(data, str, var, width);
	else
	{
		if (var < 0)
			str = ft_strsjoin("-", str, 0, 1);
		length = 0;
		while (str[length] != '\0')
			length++;
		data = no_zero_flag(data, str, width, length);
	}
	return (data);
}

t_data			*ft_print_int(t_data *data)
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
	data = parse_int(data, width, precision);
	return (data);
}
