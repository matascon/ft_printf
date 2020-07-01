/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:37:05 by matascon          #+#    #+#             */
/*   Updated: 2020/07/01 13:27:11 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*lst_zero(t_flags *flags)
{
	flags->dash = '\0';
	flags->zero = '\0';
	flags->left = NULL;
	flags->dot = '\0';
	flags->right = NULL;
	flags->star = '\0';
	flags->type = '\0';
	flags->chr_read = 0;
	return (flags);
}

static t_flags	*fill_lst(char *s, t_flags *flags)
{
	
	return (flags);
}

int		ft_flag_time(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	str++;
	if (str[i] == '%')
		return (1);
	while (ft_strchr(FLAGS, str[i]) || ft_strchr(NUMBERS, str[i]))
		i++;
	if (ft_strchr(TYPES, str[i]))
	{
		flags = lst_zero(flags);
		flags = fill(str, flags);
		return (-1);
	}
	return (0);
}
