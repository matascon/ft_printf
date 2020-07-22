/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:37:05 by matascon          #+#    #+#             */
/*   Updated: 2020/07/22 11:42:07 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*print_void_argument(t_data *data)
{
	if (data->zero && !(data->dot) && !(data->dash))
	{
		if (data->width)
			data = ft_put_zero(ft_atoi(data->width) - 1, data);
		else if (data->star_w)
			data = ft_put_zero(ft_star_pop(&data) - 1, data);
	}
	else
	{
		if (data->width)
			data = ft_put_space(ft_atoi(data->width) - 1, data);
		else if (data->star_w)
			data = ft_put_space(ft_star_pop(&data) - 1, data);
	}
	return (data);
}

static char		*fill_nbr_arg(char *str, char c)
{
	char	*aux;
	char	*aux_free;

	aux = (char *)malloc(2);
	if (!aux)
		return (NULL);
	aux[0] = c;
	aux[1] = '\0';
	if (str == NULL)
		str = ft_strdup(aux);
	else
	{
		aux_free = str;
		str = ft_strjoin(str, aux);
		free(aux_free);
	}
	free(aux);
	return (str);
}

static t_data	*fill_flags(t_data *data, char *str, int i)
{
	if (str[i] == ' ')
		data->space = 1;
	else if (str[i] == '-')
		data->dash = str[i];
	else if (str[i] == '0' && !(ft_strchr(NUMBERS, str[i - 1])) \
	&& !(ft_strchr(TYPES, str[i + 1])) && !(data->dot))
		data->zero = str[i];
	else if (str[i] == '*' && data->dot == '\0')
		data->star_w = '*';
	else if (ft_strchr(NUMBERS, str[i]) && data->dot == '\0')
		data->width = fill_nbr_arg(data->width, str[i]);
	else if (str[i] == '.' && str[i + 1] != ' ')
		data->dot = str[i];
	else if (str[i] == '*' && data->dot != '\0')
		data->star_p = '*';
	else if (ft_strchr(NUMBERS, str[i]) && data->dot != '\0')
		data->precision = fill_nbr_arg(data->precision, str[i]);
	return (data);
}

int				ft_flag_time(char *str, t_data **data)
{
	int	i;

	i = 1;
	while ((ft_strchr(FLAGS, str[i]) || ft_strchr(NUMBERS, str[i])) && str[i])
		*data = fill_flags(*data, str, i++);
	(*data)->alternative_reader = i;
	if (ft_strchr(TYPES, str[i]) && str[i] != '\0')
	{
		(*data)->type = str[i];
		return (-1);
	}
	if ((*data)->star_w || (*data)->width)
		*data = print_void_argument(*data);
	return ((*data)->alternative_reader);
}
