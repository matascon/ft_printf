/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:37:05 by matascon          #+#    #+#             */
/*   Updated: 2020/07/02 13:09:55 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*stc_zero_flags(t_flags *flags)
{
	flags->dash = '\0';
	flags->zero = '\0';
	flags->dot = '\0';
	flags->star = '\0';
	flags->type = '\0';
	flags->chr_read = 0;
	flags->left = NULL;
	flags->right = NULL;
	return (flags);
}

static t_flags	*fill_left(char c, t_flags *flags)
{
	char	*aux;

	aux = (char *)malloc(2);
	if (!aux)
		return (NULL);
	aux[0] = c;
	aux[1] = '\0';
	if (flags->left == NULL)
		flags->left = ft_strdup(aux);
	else
		ft_strjoin(flags->left, aux);
	free(aux);
	return (flags);
}

static t_flags	*fill_right(char c, t_flags *flags)
{
	char	*aux;

	aux = (char *)malloc(2);
	if (!aux)
		return (NULL);
	aux[0] = c;
	aux[1] = '\0';
	if (flags->right == NULL)
		flags->right = ft_strdup(aux);
	else
		ft_strjoin(flags->right, aux);
	free(aux);
	return (flags);
}

static t_flags	*fill_stc(char *str, t_flags *flags)
{
	int i;

	i = -1;
	while (!(ft_strchr(TYPES, str[++i])))
	{
		if (str[i] == '-')
		{
			flags->dash = str[i];
			if (str[i + 1] == '0')
				str++;
		}
		else if (str[i] == '0')
			flags->zero = str[i];
		else if (ft_strchr(NUMBERS, str[i]) && flags->dot == '\0')
			flags = fill_left(str[i], flags);
		else if (str[i] == '.')
			flags->dot = str[i];
		else if (ft_strchr(NUMBERS, str[i]) && flags->dot != '\0')
			flags = fill_right(str[i], flags);
	}
	flags->type = str[i];
	return (flags);
}

int				ft_flag_time(char *str, t_flags **flags)
{
	int	i;

	i = 0;
	(*flags)->chr_read = 1;
	if (str[i] == '%')
		return (((*flags)->chr_read = 1));
	while (ft_strchr(FLAGS, str[i]) || ft_strchr(NUMBERS, str[i]))
		i++;
	if (ft_strchr(TYPES, str[i]))
	{
		(*flags) = stc_zero_flags(*flags);
		(*flags)->chr_read = i;
		(*flags) = fill_stc(str, *flags);
		return (-1);
	}
	return (((*flags)->chr_read = 0));
}
