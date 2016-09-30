/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:01:02 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:01:06 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_basesize(unsigned int n, unsigned int base)
{
	if (!base)
		return (0);
	if (n >= base)
		return (ft_basesize(n / base, base) + 1);
	return (1);
}
