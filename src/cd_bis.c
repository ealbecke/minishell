/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:04:51 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 10:42:07 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_error_args(int nb_args, t_infos *infos)
{
	if (nb_args > 3)
	{
		ft_putstr_fd("cd: too many arguments", 2);
		ft_putstr_fd("\n", 2);
	}
	else if (nb_args == 3)
		ft_replace_cd_path(infos);
}

void	tilde(t_infos *infos, char *arg)
{
	char	*home;
	char	*tmp;

	home = NULL;
	tmp = NULL;
	if (ft_strlen(arg) == 1)
		ft_cd_go_home(infos);
	else if (arg[1] != '/')
	{
		ft_putstr_fd_2(2, "Usage: ~ [Valid path]\n", NULL);
		init_and_relaunch_get_line(infos);
	}
	else
	{
		home = query_env("HOME", infos->liste, 1);
		tmp = ft_strsub(arg, 1, ft_strlen(arg) - 1);
		free(arg);
		arg = NULL;
		infos->args[1] = ft_strjoin(home, tmp);
		free(tmp);
		ft_cd_change_dir(infos, infos->liste);
	}
}

void	cd_go_before(t_infos *infos)
{
	char	*value;

	if (chdir(query_env("_", infos->liste, 1)) == 0)
	{
		modify_env_value("OLDPWD", query_env("PWD", infos->liste, 1), &infos);
		modify_env_value("_", query_env("PWD", infos->liste, 1), &infos);
		value = getcwd(NULL, 0);
		modify_env_value("PWD", value, &infos);
		free(value);
		value = NULL;
	}
}
