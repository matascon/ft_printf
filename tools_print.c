/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 09:23:57 by matascon          #+#    #+#             */
/*   Updated: 2020/07/13 10:02:38 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_star_pop(t_data **data)
{
	int	x;

	x = va_arg((*data)->args, int);
	return (x);
}

char	*ft_join_precision(int n_zeros, char *str)
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

t_data	*ft_put_space(int num_spaces, t_data *data)
{
	int	i;

	i = -1;
	while (++i < num_spaces)
	{
		ft_putchar_fd(' ', 1);
		(data->printed)++;
	}
	return (data);
}

t_data	*ft_put_zero(int num_spaces, t_data *data)
{
	int	i;

	i = -1;
	while (++i < num_spaces)
	{
		ft_putchar_fd('0', 1);
		(data->printed)++;
	}
	return (data);
}

t_data	*ft_put_str(char *str, int length, t_data *data)
{
	int	i;

	i = -1;
	while (++i < length)
	{
		ft_putchar_fd(str[i], 1);
		(data->printed)++;
	}
	return (data);
}
