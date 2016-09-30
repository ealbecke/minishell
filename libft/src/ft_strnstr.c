/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:05 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:13:06 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	while (n-- && (s1[++i]))
	{
		if (s1[i] == s2[j])
			j++;
		else
		{
			i -= j;
			n += j;
			j = 0;
		}
		if (!s2[j])
			return ((char *)(s1 + (i - j + 1)));
	}
	return (NULL);
}
