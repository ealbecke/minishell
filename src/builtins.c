/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:49:23 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 10:43:30 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_infos *infos)
{
	if (infos)
	{
		if (infos->bin)
			free(infos->bin);
		if (infos->liste)
			free_list(infos->liste);
		if (infos->args)
			free_double_array(infos->args);
		if (infos->tbl_linklist)
			free_double_array(infos->tbl_linklist);
		free(infos);
	}
	exit(EXIT_SUCCESS);
}

void	ft_unsetenv(t_infos *infos)
{
	int		i;

	i = 1;
	if (count_double_tbl(infos->args) == 1)
	{
		ft_putstr_fd("unsetenv: not enough arguments\n", 2);
		return ;
	}
	while (infos->args[i])
	{
		if ((ft_strcmp("-", infos->args[i]) != 0)
				&& query_env(infos->args[i], infos->liste, 0) != NULL)
			delete_env_value(infos->args[i], &infos);
		i++;
	}
}

void	ft_cd(t_infos *infos)
{
	int		nb_args;

	nb_args = 0;
	while (infos->args[nb_args])
		nb_args++;
	if (nb_args >= 3)
		ft_cd_error_args(nb_args, infos);
	else if (nb_args == 1)
		ft_cd_go_home(infos);
	else
		ft_cd_change_dir(infos, infos->liste);
}

int		ft_check_builtins(t_infos *infos)
{
	if (ft_strcmp(infos->args[0], "cd") == 0)
		ft_cd(infos);
	else if (ft_strcmp(infos->args[0], "env") == 0)
		ft_env(infos);
	else if (ft_strcmp(infos->args[0], "setenv") == 0)
		ft_setenv(infos);
	else if (ft_strcmp(infos->args[0], "unsetenv") == 0)
		ft_unsetenv(infos);
	else if (ft_strcmp(infos->args[0], "echo") == 0)
		ft_echo(infos);
	else if (ft_strcmp(infos->args[0], "exit") == 0)
		ft_exit(infos);
	else
		return (0);
	return (1);
}
