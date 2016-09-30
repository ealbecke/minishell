/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lbasesize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:03:10 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:03:13 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_lbasesize(unsigned long long n, unsigned int base)
{
	if (!base)
		return (0);
	if (n >= base)
		return (ft_lbasesize(n / base, base) + 1);
	return (1);
}
