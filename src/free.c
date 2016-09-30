/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 15:06:26 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/27 18:44:16 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_liste *liste)
{
	t_liste		*tmp;

	while (liste != NULL)
	{
		free(liste->key);
		liste->key = NULL;
		free(liste->value);
		liste->value = NULL;
		tmp = liste->next;
		free(liste);
		liste = tmp;
	}
	liste = NULL;
}

void	free_double_array(char **tbl)
{
	int		i;

	i = 0;
	if (tbl)
	{
		while (tbl[i])
		{
			free(tbl[i]);
			i++;
		}
		free(tbl);
	}
}
