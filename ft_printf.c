/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:29:10 by matascon          #+#    #+#             */
/*   Updated: 2020/07/02 13:04:15 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_str	*stc_zero_str(t_str *result)
{
	result->str = NULL;
	result->count = 0;
	return (result);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	t_str	*result;

	va_start(args, format);
	result = stc_zero_str(result);
	result->str = ft_strdup(format);
	if (!(result->str))
		return (0);
	result = ft_control_base(result, args);
	va_end(args);
	return (result->count);
}

int		main()
{
	int i;

	i = ft_printf("M %05d\n");
	printf("\n%i\n", i);
	//printf("\n\n Hola %-05i end\n", 64);
    return (0);
}
