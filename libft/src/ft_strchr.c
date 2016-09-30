/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:09:19 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:09:20 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s && !*s && c == 0)
		return ((char *)s);
	else if (!s || !*s)
		return (NULL);
	if (*s == (char)c)
		return ((char *)s);
	return (ft_strchr(s + 1, c));
}
