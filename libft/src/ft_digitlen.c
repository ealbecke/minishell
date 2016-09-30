/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:01:54 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:01:57 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_digitlen(const char *str)
{
	if (str && ft_isdigit(*str))
		return (ft_digitlen(str + 1) + 1);
	return (0);
}
