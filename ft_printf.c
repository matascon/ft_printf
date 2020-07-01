/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:29:10 by matascon          #+#    #+#             */
/*   Updated: 2020/07/01 12:57:29 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		count;

	va_start(args, format);
	str = ft_strdup(format);
	if (!str)
		return (0);
	count = ft_control_base(str, args);
	va_end(args);
	return (count);
}

int		main()
{
	ft_printf("Hola %05 %% %\n");
    return (0);
}
