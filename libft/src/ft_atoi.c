/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:00:04 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:00:08 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	unsigned int		i;
	int					base;
	long				tot;

	i = 0;
	base = 1;
	tot = 0;
	while (str && (*str == ' ' || (9 <= *str && *str <= 13)))
		str++;
	if (str && (*str == '-' || *str == '+'))
		i++;
	if (str && (i += ft_digitlen(str + i)) > 11)
		return (FTL_ERR);
	while (str && i-- > (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			tot -= (str[i] - '0') * base;
		else
			tot += (str[i] - '0') * base;
		base *= 10;
	}
	return ((tot < FTL_B31 && tot >= FTL_INTMIN ? (int)tot : FTL_ERR));
}
