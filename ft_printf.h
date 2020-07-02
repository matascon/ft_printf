/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:29:06 by matascon          #+#    #+#             */
/*   Updated: 2020/07/02 12:15:27 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef PARAMETERS_FOR_FLAGS
#  define FLAGS "-0.*\0"
#  define TYPES "cspdiuxX\0"
#  define NUMBERS "1234567890\0"
# endif

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	char	dash;
	char	zero;
	char	*left;
	char	dot;
	char	*right;
	char	star;
	char	type;
	int		chr_read;
}				t_flags;

typedef struct	s_str
{
	char	*str;
	int		count;
}				t_str;

t_str			*ft_control_base(t_str *result, va_list args);
int				ft_flag_time(char *str, t_flags **flags);

#endif
