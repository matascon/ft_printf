/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:37:05 by matascon          #+#    #+#             */
/*   Updated: 2020/07/15 10:49:19 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	check_flags(char c, t_data *data)
{
	if (c == '*' && !(data->dot) && (data->width || data->star_w))
		return (1);
	else if (c == '*' && data->dot && (data->precision || data->star_p))
		return (1);
	else if (c == '-' && (data->zero || data->dot || data->width \
	|| data->precision || data->star_w || data->star_p))
		return (1);
	else if (c == '.' && data->dot)
		return (1);
	else if (c == '0' && (data->dot || data->star_w || data->star_p))
		return (1);
	return (0);
}*/

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
	&& !(ft_strchr(TYPES, str[i + 1])))
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
	while ((ft_strchr(FLAGS, str[i]) || ft_strchr(NUMBERS, str[i])) \
	&& str[i])
		*data = fill_flags(*data, str, i++);
	(*data)->alternative_reader = i;
	if (ft_strchr(TYPES, str[i]) && str[i] != '\0')
	{
		(*data)->type = str[i];
		return (-1);
	}
	if (ft_isprint(str[i]))
		((*data)->alternative_reader)++;
	return ((*data)->alternative_reader);
}
