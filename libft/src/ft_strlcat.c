/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:10:55 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:11:01 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*d;
	char	*source;
	size_t	len;
	size_t	dst_len;

	d = dest;
	source = (char *)src;
	len = size;
	while (len-- && *d)
		d++;
	dst_len = d - dest;
	len = size - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(source));
	while (*source != '\0')
	{
		if (len != 1)
		{
			*d++ = *source;
			len--;
		}
		source++;
	}
	*d = '\0';
	return (dst_len + (source - src));
}
