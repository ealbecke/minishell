/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:25 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:17:37 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s1 && s2 && (s1[++i - 1] || i - 1 == -1))
	{
		if (!s2[j])
			return ((char *)(s1 + (i - j)));
		else if (s1[i] == s2[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
	}
	return (NULL);
}
