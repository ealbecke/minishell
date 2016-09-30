/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnumlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:58:12 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:18:35 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_alnumlen(const char *str)
{
	if (str && ft_isalnum(*str))
		return (ft_alnumlen(str + 1) + 1);
	return (0);
}
