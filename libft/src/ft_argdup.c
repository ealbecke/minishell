/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 16:59:21 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 16:59:28 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_argdup(char **arg)
{
	char				**narg;
	unsigned int		i;

	if ((narg = (char **)malloc(sizeof(char *) * (ft_arglen(arg) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_arglen(arg))
	{
		narg[i] = ft_strdup(arg[i]);
		i++;
	}
	narg[i] = NULL;
	return (narg);
}
