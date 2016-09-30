/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:59:40 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 16:59:45 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char				**ft_argnew(unsigned int n)
{
	char				**arg;
	unsigned int		i;

	if ((arg = (char **)malloc(sizeof(char *) + (n + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		arg[i] = NULL;
		i++;
	}
	return (arg);
}
