/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:53 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:39:53 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_length;

	if (ft_strlen(s) < start || !s)
		return (NULL);
	s_length = ft_strlen((char *)s + start);
	if (len > s_length)
		len = s_length;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s + start, len + 1);
	return (ptr);
}
