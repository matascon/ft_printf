/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:18 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:39:19 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_length;
	ssize_t	src_length;

	dest_length = 0;
	while (dest[dest_length])
		dest_length++;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (dest_length >= n)
		return (src_length + n);
	n = n - dest_length;
	ft_strlcpy(dest + dest_length, src, n);
	return (dest_length + src_length);
}
