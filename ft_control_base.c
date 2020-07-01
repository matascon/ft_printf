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

int			ft_control_base(char *str, va_list args)
{
	int		count;
	int		check_flag;
	t_flags	flags;

	count = -1;
	check_flag = 0;
	while (str[++count] != '\0')
	{
		if (str[count] == '%')
		{
			check_flag = ft_flag_time((str + count), &flags);
			if (check_flag == -1)
				count += 0;
			count += check_flag;
		}
		ft_putchar_fd(str[count], 1);
	}
	return (count);
}
