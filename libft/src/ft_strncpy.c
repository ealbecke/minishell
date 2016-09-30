/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:12:41 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:12:44 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (n-- && dst && src)
	{
		if (!src[j])
			dst[i] = '\0';
		else
		{
			dst[i] = src[j];
			j++;
		}
		i++;
	}
	return (dst);
}
