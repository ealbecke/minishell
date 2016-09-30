/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:18:18 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/26 15:04:32 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	int		n;
	int		v;

	if (!size)
		return (NULL);
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	n = (int)size;
	v = 0;
	while (v < n)
	{
		str[v] = '\0';
		v++;
	}
	return ((void*)str);
}
