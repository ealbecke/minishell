/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:04:59 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:05:01 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*strsrc;
	unsigned char	*strdst;
	unsigned int	i;

	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	i = 0;
	while (n-- && dst && src)
	{
		strdst[i] = strsrc[i];
		if (strsrc[i] == (unsigned char)c)
		{
			dst = (void *)strdst;
			return ((void *)strdst + i + 1);
		}
		i++;
	}
	return (NULL);
}
