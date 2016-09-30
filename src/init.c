/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 18:34:52 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 10:47:46 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_liste		*put_env_linkedlist(char **env, t_liste *list, int i)
{
	char	**split_env;
	t_liste	*node;
	t_liste	*tmp;

	while (env[++i])
	{
		split_env = ft_strsplit(env[i], '=');
		node = (t_liste *)malloc(sizeof(t_liste));
		node->key = ft_strdup(split_env[0]);
		node->value = ft_strdup(split_env[1]);
		node->next = NULL;
		if (list == NULL)
			list = node;
		else
		{
			tmp = list;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
			tmp = NULL;
		}
		free_double_array(split_env);
	}
	return (list);
}

void		init_env(t_infos **infos, char **env)
{
	*infos = (t_infos *)malloc(sizeof(t_infos));
	(*infos)->liste = NULL;
	(*infos)->args = NULL;
	(*infos)->bin = NULL;
	(*infos)->tbl_linklist = NULL;
	(*infos)->e = 0;
	(*infos)->n = 0;
	(*infos)->i = 0;
	(*infos)->u = 0;
	(*infos)->liste = put_env_linkedlist(env, (*infos)->liste, -1);
}

void		init_and_relaunch_get_line(t_infos *infos)
{
	free_double_array(infos->args);
	infos->args = NULL;
	if (infos->bin != NULL)
	{
		free(infos->bin);
		infos->bin = NULL;
	}
	free_double_array(infos->tbl_linklist);
	infos->tbl_linklist = NULL;
	(infos)->e = 0;
	(infos)->n = 0;
	(infos)->i = 0;
	(infos)->u = 0;
	get_line(infos);
}
