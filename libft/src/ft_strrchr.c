/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:13 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:13:14 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *k;

	k = NULL;
	while (*s)
	{
		if (*s == (char)c)
			k = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (k);
}
