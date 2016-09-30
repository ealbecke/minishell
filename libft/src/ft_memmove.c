/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:05:40 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:05:44 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*strdst;
	char	*strsrc;

	if (!dst || !src)
		return (NULL);
	i = 0;
	strsrc = (void *)src;
	strdst = dst;
	while (n--)
	{
		if (strsrc < strdst)
			strdst[n] = strsrc[n];
		else
			strdst[i] = strsrc[i];
		i++;
	}
	dst = strdst;
	return (dst);
}
