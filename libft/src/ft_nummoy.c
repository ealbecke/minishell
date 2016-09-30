/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nummoy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:06:01 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:06:03 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_nummoy(int *num, unsigned int n)
{
	long long int		tot;
	unsigned int		i;

	i = 0;
	tot = 0;
	while (num && i < n)
	{
		tot += num[i];
		i++;
	}
	if (n)
		tot /= n;
	return (tot);
}
