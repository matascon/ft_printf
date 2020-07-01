/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:38:54 by matascon          #+#    #+#             */
/*   Updated: 2020/06/29 10:47:30 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ef_number_str(char *s, char c)
{
	int	n_str;
	int	check;
	int i;

	n_str = 0;
	check = 0;
	i = -1;
	if (s[0] == '\0')
		return (0);
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			check = 0;
		else if (check++ == 0)
			n_str++;
	}
	return (n_str);
}

static char	**ef_free_ptr(char **ptr, int i)
{
	while (--i >= 0)
		free(ptr[i]);
	free(ptr);
	return (ptr);
}

static char	**ef_pass_values(char **ptr, char *s, char c, int n_str)
{
	int	i;
	int j;
	int	k;

	i = -1;
	j = 0;
	while (j < n_str)
	{
		if (s[++i] != c)
		{
			k = 0;
			while (s[i] != c && s[i] != '\0')
				ptr[j][k++] = s[i++];
			ptr[j][k] = '\0';
			j++;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

static char	**ef_set_ptr(char **ptr, char *s, char c, int n_str)
{
	int	i;
	int	j;
	int size;

	i = -1;
	j = 0;
	while (j < n_str)
	{
		if (s[++i] != c)
		{
			size = 0;
			while (s[i + size] != c && s[i + size] != '\0')
				size++;
			ptr[j] = (char *)malloc(size + 1);
			if (!ptr[j])
				return (ef_free_ptr(ptr, j));
			i += size;
			j++;
		}
	}
	ptr = ef_pass_values(ptr, s, c, n_str);
	return (ptr);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		n_str;

	n_str = ef_number_str((char *)s, c);
	ptr = (char **)malloc(sizeof(char *) * (n_str + 1));
	if (!ptr)
		return (NULL);
	ptr = ef_set_ptr(ptr, (char *)s, c, n_str);
	return (ptr);
}
