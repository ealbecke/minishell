/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:12:15 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/26 17:47:04 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_child_pid;

void	ft_signal(int sig)
{
	if (sig == SIGINT)
		ft_printf("\n");
}

int		main(int ac, char **av, char **env)
{
	t_infos	*infos;

	signal(SIGINT, ft_signal);
	if (ac > 1)
	{
		ft_putstr_fd_2(2, "Usage: ", av[0], "\n", NULL);
		return (0);
	}
	infos = NULL;
	init_env(&infos, env);
	if (ft_strcmp(av[0], "./minishell") == 0)
		ft_shlvl(infos);
	get_line(infos);
	return (0);
}
