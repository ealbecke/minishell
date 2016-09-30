/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:07:29 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:07:31 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft.h"

int					ft_next_flag(const char *str, char **new_str, char c)
{
	int					len;

	len = ft_strclen(str, c);
	if (!(*new_str = ft_strsub(str, 0, len)))
		return (FT_ERROR);
	return (len);
}

int					ft_conv_flag(const char *src, char **dst, va_list ap,
							int *sc)
{
	int					len;
	unsigned int		ldst;
	char				*sflag;
	char				*tmp_str;

	len = ft_flag(src, &sflag, ap, sc);
	ldst = ft_strlen(*dst);
	*sc = (*sc ? *sc : (int)ft_strlen(sflag));
	tmp_str = ft_strnew(ldst + *sc);
	ft_memcpy(tmp_str, *dst, ldst);
	ft_memcpy(tmp_str + ldst, sflag, *sc);
	*sc += (int)ldst;
	free(*dst);
	*dst = (sflag ? tmp_str : NULL);
	free(sflag);
	return (len);
}
