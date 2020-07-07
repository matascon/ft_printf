/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:13:45 by matascon          #+#    #+#             */
/*   Updated: 2020/07/07 12:24:39 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*parse_char(t_data *data, int width)
{
	char	var;

	var = (char)va_arg(data->args, int);
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX)
	{
		if (data->dash)
		{
			ft_putchar_fd(var, 1);
			(data->printed)++;
			data = ft_put_space(width - 1, data);
		}
		else
		{
			data = ft_put_space(width - 1, data);
			ft_putchar_fd(var, 1);
			(data->printed)++;
		}
	}
	else
		data->error = 1;
	return (data);
}

t_data			*ft_print_char(t_data *data)
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
	data = parse_char(data, width);
	return (data);
}
