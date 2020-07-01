/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:39:50 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:46:29 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ef_check_set(char c, char *set)
{
	size_t	set_length;
	size_t	i;

	set_length = ft_strlen(set);
	i = 0;
	while (i <= set_length)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	start = 0;
	end = 0;
	while (s1[end])
		end++;
	while (ef_check_set(s1[start], (char *)set))
		start++;
	while (ef_check_set(s1[end], (char *)set) && end >= 0)
		end--;
	if (end < start)
	{
		return (ft_strdup(""));
	}
	ptr = (char *)malloc(end - start + 2);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, end - start + 2);
	return (ptr);
}
