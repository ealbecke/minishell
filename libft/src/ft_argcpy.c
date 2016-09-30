/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:58:48 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 16:58:52 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_argcpy(char **dst, char **src)
{
	unsigned int		i;

	i = 0;
	while (dst && src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
