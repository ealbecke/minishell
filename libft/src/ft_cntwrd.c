/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:01:35 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:01:38 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_cntwrd(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str && *str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str)
			i++;
		while (*str && *str != ' ' && *str != '\t' && *str != '\n')
			str++;
	}
	return (i);
}
