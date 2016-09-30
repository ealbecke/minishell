/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:02:51 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/27 14:06:34 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_linkedlist_in_tbl(t_infos *infos)
{
	int			i;
	t_liste		*current;
	char		*chaine_1;

	i = 0;
	current = infos->liste;
	chaine_1 = NULL;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	if (!(infos->tbl_linklist = (char **)malloc(sizeof(char **) * (i + 1))))
		exit(EXIT_FAILURE);
	current = infos->liste;
	i = 0;
	while (current != NULL)
	{
		chaine_1 = ft_strjoin(current->key, "=");
		infos->tbl_linklist[i] = ft_strjoin(chaine_1, current->value);
		free(chaine_1);
		i++;
		current = current->next;
	}
	infos->tbl_linklist[i] = NULL;
}
