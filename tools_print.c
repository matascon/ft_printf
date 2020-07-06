/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 09:23:57 by matascon          #+#    #+#             */
/*   Updated: 2020/07/06 11:15:25 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_star_pop(t_data **data)
{
	int	x;

	x = va_arg((*data)->args, int);
	return (x);
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
