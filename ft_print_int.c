/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 08:20:14 by matascon          #+#    #+#             */
/*   Updated: 2020/07/06 11:20:27 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*join_precision(int	n_zeros, char *str)
{
	char	*new_str;
	char	*aux_free;
	int		i;

	new_str = ft_strdup("");
	i = -1;
	while (++i < n_zeros)
	{
		aux_free = new_str;
		new_str = ft_strjoin(new_str, "0");
		free(aux_free);
	}
	aux_free = new_str;
	new_str = ft_strjoin(new_str, str);
	free(aux_free);
	free(str);
	return (new_str);
}

static t_data	*aux_parse_int(t_data *data, char *str, int width, int len_str)
{
	if ((unsigned int)(data->printed + width) <= (unsigned int)INT_MAX || \
	(unsigned int)(data->printed + len_str <= (unsigned int)INT_MAX))
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
		data->error = -1;
	return (data);
}

static t_data	*parse_int(t_data *data, int width, int precision)
{
	int		var;
	char	*str;
	int		length;

	var = (int)va_arg(data->args, int);
	str = ft_itoa(var);
	while (str[length] != '\0')
		length++;
	str = join_precision(precision - length, str);
	length = 0;
	while (str[length] != '\0')
		length++;
	data = aux_parse_int(data, str, width, length);
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
	data = parse_int(data, width, precision);
	return (data);
}
