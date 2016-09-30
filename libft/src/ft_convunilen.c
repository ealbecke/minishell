/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convunilen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:01:41 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:19:07 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

unsigned int		ft_convunilen(wchar_t wcc)
{
	if (wcc < FTL_B7 && wcc >= 0)
		return (1);
	else if (wcc < FTL_B11 && wcc >= 0)
		return (2);
	else if (wcc < FTL_B16 && wcc >= 0)
		return (3);
	else if (wcc <= (FTL_B16 - 1) + FTL_B20 && wcc >= 0)
		return (4);
	return (0);
}
