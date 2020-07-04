/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:29:10 by matascon          #+#    #+#             */
/*   Updated: 2020/07/02 13:04:15 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*stc_zero_str(t_data *data)
{
	data->str = NULL;
	data->printed = 0;
	data->alternative_read = 0;
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
	n_char = data->printed;
	va_end(data->args);
	free(data);
	return (n_char);
}

int		main()
{
	int i;

	i = ft_printf("<%*c fuck up>\n", 5, 'a');
	printf("<%i>\n", i);
	i = printf("<%10.5i fuck up>\n", 5);
	printf("<%i>\n", i);
    return (0);
}
