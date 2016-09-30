/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asciilen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:59:54 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:00:00 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_asciilen(const char *str)
{
	if (str && ft_isascii(*str))
		return (ft_asciilen(str + 1) + 1);
	return (0);
}
