/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:08:13 by matascon          #+#    #+#             */
/*   Updated: 2020/07/06 12:39:55 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ef_number_digit(unsigned int n)
{
	if (n < 10)
		return (1);
	else
		return (1 + ef_number_digit(n / 10));
}

static char	*ef_become_str(char *ptr, unsigned int n, int n_digit)
{
	int	i;

	i = n_digit - 1;
	while (n >= 10)
	{
		ptr[i--] = (n % 10) + 48;
		n /= 10;
	}
	ptr[i] = (n % 10) + 48;
	ptr[n_digit] = '\0';
	return (ptr);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char	*ptr;
	int		n_digit;

	n_digit = ef_number_digit(n);
	ptr = (char *)malloc(n_digit + 1);
	if (!ptr)
		return (NULL);
	ptr = ef_become_str(ptr, n, n_digit);
	return (ptr);
}
