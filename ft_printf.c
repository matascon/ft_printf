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
	count = ft_print(str, args);
	va_end(args);
	return (0);
}

int		main()
{
	ft_printf("This is %d a %test\n");
    return (0);
}
