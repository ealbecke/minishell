/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcconvuni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:14:01 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:14:02 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <wchar.h>

char				*ft_wcconvuni(wchar_t wcc)
{
	char				*str;
	char				mask;
	unsigned int		size;
	unsigned int		i;

	if (!(size = ft_convunilen(wcc)) ||
			!(str = (char *)ft_strnew(size + 1)))
		return (NULL);
	i = size;
	mask = 0;
	if (size > 1)
		mask = FTL_B7;
	while (--i > 0)
	{
		str[i] = (wcc & FTL_6B) + FTL_B7;
		str[0] |= mask;
		mask = mask >> 1;
		wcc = wcc >> 6;
	}
	*str = wcc + mask;
	return (str);
}
