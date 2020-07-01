/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:37:46 by matascon          #+#    #+#             */
/*   Updated: 2020/07/01 12:59:39 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print(char *str, va_list args)
{
	int		count;
	t_flags	flags;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '%')
		{
			ft_flags_time((str + count), &flags);
		}
		ft_putchar_fd(str[count], 1);
		count++;
	}
	return (count);
}
