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

static int		check_end_flag(char c)
{
	char	*check;
	int		i;

	check = ft_strdup("cspdiuxX\0");
	i = -1;
	while (check[++i] != '\0')
	{
		if (c == check[i])
			return (0);
	}
	return (1);
}

static t_flags	*find_out_flags(char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (check_end_flag(str[i]))
	{
		i++;
	}
	return (flags);
}

void			ft_flags_time(char *str, t_flags *flags)
{
	flags = lst_zero(flags);
	flags = find_out_flags(str, flags);
}
