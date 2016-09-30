/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:01:59 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/26 17:43:10 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(t_liste *list)
{
	char	*user;
	char	*pwd;

	if ((user = query_env("USER", list, 1)) != NULL)
		ft_printf("\033[36m%s\033[m", user);
	else
		ft_printf("\033[36mPrompt\033[m");
	ft_printf(" - ");
	if ((pwd = query_env("PWD", list, 1)) != NULL)
		ft_printf("\033[34m%s\033[m >", pwd);
	else
		ft_printf("\033[34m > \033[m");
}

void	print_list(t_liste *head)
{
	t_liste *current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%s", current->key);
		ft_printf("=");
		ft_printf("%s\n", current->value);
		current = current->next;
	}
}
