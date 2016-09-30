/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:01:28 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:01:31 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_charflag(char c, const char *flags)
{
	unsigned int		pos;

	if (!flags || (pos = ft_strclen(flags, c)) == ft_strlen(flags))
		return (0);
	return (pos + 1);
}
