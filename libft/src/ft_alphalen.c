/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphalen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:58:28 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 16:58:41 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_alphalen(const char *str)
{
	if (str && ft_isalpha(*str))
		return (ft_alphalen(str + 1) + 1);
	return (0);
}
