/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:10 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:39:11 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_length;
	char	*ptr;

	s_length = 0;
	while (s[s_length])
		s_length++;
	ptr = (char *)malloc(s_length + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, s_length + 1);
	return (ptr);
}
