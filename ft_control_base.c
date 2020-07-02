/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:37:46 by matascon          #+#    #+#             */
/*   Updated: 2020/07/02 13:03:48 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*ft_control_base(t_str *result, va_list args)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	while (result->str[result->count] != '\0')
	{
		if (result->str[result->count] == '%')
		{
			if (ft_flag_time((result->str + result->count + 1), &flags) == -1)
			{
				printf("%c %s %c\n", flags->zero, flags->left, flags->type);
			}
			result->count += flags->chr_read;
		}
		ft_putchar_fd(result->str[result->count], 1);
		(result->count)++;
	}
	return (result);
}
