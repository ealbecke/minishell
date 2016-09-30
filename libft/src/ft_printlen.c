/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:06:10 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:06:14 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_printlen(const char *str)
{
	if (str && ft_isprint(*str))
		return (ft_printlen(str + 1) + 1);
	return (0);
}
