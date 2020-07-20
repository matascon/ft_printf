/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:29:10 by matascon          #+#    #+#             */
/*   Updated: 2020/07/13 11:10:35 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*stc_zero_str(t_data *data)
{
	data->str = NULL;
	data->printed = 0;
	data->alternative_reader = 0;
	data->error = 0;
	return (data);
}

int				ft_printf(const char *format, ...)
{
	t_data	*data;
	int		n_char;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	va_start(data->args, format);
	data = stc_zero_str(data);
	data->str = ft_strdup(format);
	if (!(data->str))
		return (-1);
	data = ft_control_base(data);
	if (data->error)
		data->printed = -1;
	n_char = data->printed;
	free(data->str);
	va_end(data->args);
	free(data);
	return (n_char);
}
