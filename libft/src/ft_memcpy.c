/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:05:19 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:05:23 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*strdst;
	char	*strsrc;

	if (!src || !dst)
		return (NULL);
	i = 0;
	strsrc = (void *)src;
	strdst = dst;
	while (n--)
	{
		strdst[i] = strsrc[i];
		i++;
	}
	dst = strdst;
	return (dst);
}
