/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:29:10 by matascon          #+#    #+#             */
/*   Updated: 2020/07/07 12:20:16 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*stc_zero_str(t_data *data)
{
	data->str = NULL;
	data->printed = 0;
	data->alternative_reader = 0;
	data->error = 0;
	return (data);
}

int				ft_printf(const char *format, ...)
{
	t_data	*data;
	int		n_char;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	va_start(data->args, format);
	data = stc_zero_str(data);
	data->str = ft_strdup(format);
	if (!(data->str))
		return (-1);
	data = ft_control_base(data);
	n_char = data->printed;
	va_end(data->args);
	free(data);
	return (n_char);
}

int		main()
{
	int 	i;
	int		*j;

	j = i;
	i = ft_printf("<%-8s> <%c%s>\n", "Mateo", 'T', "ascon");
	ft_printf("<%i>\n", i);
	i = printf("<%-8s> <%c%s>\n", "Mateo", 'T', "ascon");
	ft_printf("<%i>\n", i);
	ft_printf("\n****************************************\n\n");
	i = ft_printf("<%u>\n", (unsigned)INT_MAX * 2);
	ft_printf("<%i>\n", i);
	i = printf("<%u>\n", (unsigned)INT_MAX * 2);
	ft_printf("<%i>\n", i);
	ft_printf("\n****************************************\n\n");
	i = ft_printf("<%-10s>\n", NULL);
	ft_printf("<%i>\n", i);
	i = printf("<%-10s>\n", NULL);
	ft_printf("<%u>\n", i);
	ft_printf("\n****************************************\n\n");
	i = ft_printf("<%20p>\n", j);
	ft_printf("<%i>\n", i);
	i = printf("<%20p>\n", j);
	ft_printf("<%i>\n", i);
	i = ft_printf("<%20p>\n", NULL);
	ft_printf("<%i>\n", i);
	i = printf("<%20p>\n", NULL);
	ft_printf("<%i>\n", i);
	ft_printf("\n****************************************\n\n");
	i = ft_printf("<%x>\n", 246);
	ft_printf("<%i>\n", i);
	i = printf("<%x>\n", 246);
	ft_printf("<%i>\n", i);
	i = ft_printf("<%X>\n", 246);
	ft_printf("<%i>\n", i);
	i = printf("<%X>\n", 246);
	ft_printf("<%i>\n", i);
	i = ft_printf("<%x>\n", 673855);
	ft_printf("<%i>\n", i);
	i = printf("<%x>\n", 673855);
	ft_printf("<%i>\n", i);
	i = ft_printf("<%X>\n", 673855);
	ft_printf("<%i>\n", i);
	i = printf("<%X>\n", 673855);
	ft_printf("<%i>\n", i);
	i = ft_printf("<%5.0x>\n", 0);
	ft_printf("<%i>\n", i);
	i = printf("<%5.0x>\n", 0);
	ft_printf("<%i>\n", i);
    return (0);
}
