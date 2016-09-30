/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:10:10 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:10:12 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_strflag(const char *str, const char **sflags)
{
	unsigned int		pos;

	pos = 0;
	while (str && sflags && sflags[pos] && ft_strcmp(str, sflags[pos]))
		pos++;
	if (!sflags || !sflags[pos])
		return (0);
	return (pos);
}
