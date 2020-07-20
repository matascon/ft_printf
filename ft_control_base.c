/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:37:46 by matascon          #+#    #+#             */
/*   Updated: 2020/07/15 08:35:08 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*free_data_strs(t_data *data)
{
	if (data->width)
		free(data->width);
	if (data->precision)
		free(data->precision);
	return (data);
}

static t_data	*stc_zero_flags(t_data *data)
{
	data->space = 0;
	data->dash = '\0';
	data->zero = '\0';
	data->dot = '\0';
	data->star_w = '\0';
	data->star_p = '\0';
	data->type = '\0';
	data->width = NULL;
	data->precision = NULL;
	return (data);
}

t_data			*ft_control_base(t_data *data)
{
	int		i;

	i = -1;
	while (data->str[++i] != '\0' && data && \
	data->printed < INT_MAX && !(data->error))
	{
		data = stc_zero_flags(data);
		if (data->str[i] == '%')
		{
			if (ft_flag_time((data->str + i), &data) == -1)
				data = ft_print_time(data);
			i += data->alternative_reader;
			data = free_data_strs(data);
		}
		if (!(data->type) && data->str[i] != '\0')
		{
			ft_putchar_fd(data->str[i], 1);
			(data->printed)++;
		}
	}
	return (data);
}
