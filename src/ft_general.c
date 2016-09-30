/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 12:33:00 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 10:45:14 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			count_occurence(char *str, char occurence)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == occurence)
			nb++;
		i++;
	}
	return (nb);
}

char		**exist_path(t_infos *infos)
{
	char	*path;
	char	**split_path;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if ((path = query_env("PATH", infos->liste, 1)) == NULL)
		return (NULL);
	while (path[i])
	{
		if (path[i] == ':')
			x++;
		i++;
	}
	if (i == x)
		return (NULL);
	split_path = ft_strsplit(path, ':');
	return (split_path);
}

int			count_node_list(t_liste *liste)
{
	int		i;
	t_liste	*current;

	i = 0;
	current = liste;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void		create_one_elem(char *key, char *value, t_infos **infos)
{
	(*infos)->liste = (t_liste *)malloc(sizeof(t_liste));
	(*infos)->liste->key = ft_strdup(key);
	(*infos)->liste->value = ft_strdup(value);
	(*infos)->liste->next = NULL;
}

void		push_second_elem(char *key, char *value, t_infos **infos)
{
	t_liste		*current;
	t_liste		*node;

	current = (*infos)->liste;
	node = (t_liste *)malloc(sizeof(t_liste));
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	current->next = node;
}
