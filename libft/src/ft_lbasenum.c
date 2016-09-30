/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lbasenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:03:05 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:03:07 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_lbasenum(unsigned long long n, const char *base)
{
	char				*str;
	unsigned int		b;
	unsigned int		i;

	if (!base || !(b = ft_strlen(base)))
		return (NULL);
	if (b == 1)
		return (ft_strdup(base));
	i = ft_lbasesize(n, b);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (n >= b)
	{
		str[--i] = base[n % b];
		n /= b;
	}
	*str = base[n % b];
	return (str);
}
