/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:56:28 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 11:57:40 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*query_env(char *key, t_liste *list, int flag)
{
	t_liste		*current;

	current = list;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			if (flag == 0)
				return (current->key);
			else if (flag == 1)
				return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}

void		creat_var_env(char *key, char *value, t_infos **infos)
{
	t_liste		*current;
	t_liste		*previous;
	t_liste		*node;

	previous = NULL;
	current = (*infos)->liste;
	if (current == NULL)
	{
		node = (t_liste *)malloc(sizeof(t_liste));
		node->key = ft_strdup(key);
		node->value = ft_strdup(value);
		node->next = NULL;
		current = node;
		return ;
	}
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	node = (t_liste *)malloc(sizeof(t_liste));
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = current;
	previous != NULL ? previous->next = node : NULL;
}

void		modify_env_value(char *key, char *value, t_infos **infos)
{
	t_liste		*current;

	current = (*infos)->liste;
	while (current && current != NULL)
	{
		if (ft_strcmp(key, current->key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
	creat_var_env(key, value, infos);
}

void		free_current(t_liste *current)
{
	free(current->key);
	free(current->value);
	free(current);
}

void		delete_env_value(char *key, t_infos **infos)
{
	t_liste		*current;
	t_liste		*previous;

	current = (*infos)->liste;
	previous = NULL;
	while (current != NULL)
	{
		if ((ft_strcmp(key, current->key) == 0))
		{
			if (previous == NULL)
			{
				(*infos)->liste = current->next;
				free_current(current);
			}
			else
			{
				previous->next = current->next;
				free_current(current);
			}
			return ;
		}
		previous = current;
		current = current->next;
	}
}
