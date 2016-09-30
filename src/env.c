/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:49:29 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 11:16:10 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			inspect_args_env(t_infos *infos, char *str)
{
	if (count_hiphen_option(infos, str))
		return (1);
	else
	{
		ft_putstr_fd_2(2, "usage: env [-i] [-u name]\n", NULL);
		init_and_relaunch_get_line(infos);
	}
	return (0);
}

int			match_option_env(t_infos *infos, char **av, int end)
{
	int		i;

	i = 1;
	if (end == 1 && (inspect_args_env(infos, av[i]) == 1))
		return (2);
	else if (end == 1 && (inspect_args_env(infos, av[i]) == 0))
		return (1);
	while (i <= end)
	{
		if (inspect_args_env(infos, av[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

void		ft_check_env(t_infos *infos, char **av)
{
	char	*path;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (ft_strcmp(av[1], "./minishell") == 0)
		path = ft_strdup("./minishell");
	else
		path = ft_strdup(found_bin_path(infos, av[1], 0));
	len = ft_strlen(path);
	if (ft_strcmp(av[1], "cd") == 0)
		return ;
	if (len > 0)
	{
		free(infos->args[0]);
		infos->args[0] = NULL;
		infos->args[0] = ft_strdup(path);
		free(infos->args[1]);
		infos->args[1] = NULL;
		check_exec_env(infos, path, 1);
	}
	else
		ft_putstr_fd_2(2, "env: ", av[1],
				": No such file or directory\n", NULL);
}

void		check_options_env(t_infos *infos, int nb_args)
{
	int		hyphen;
	int		end;

	end = 0;
	hyphen = count_hyphen(infos->args);
	if (hyphen == 0 && nb_args > 2)
		ft_putstr_fd_2(2, "env: ", infos->args[2],
				": No such file or directory\n", NULL);
	else if (hyphen == 0 && nb_args == 2)
		ft_check_env(infos, infos->args);
	else if (hyphen > 0)
	{
		end = match_option_env(infos, infos->args, hyphen);
		if (nb_args == (hyphen + 1) && !infos->i)
			ft_putstr_fd_2(2, "env: option requires an argument -- u\n", NULL);
		else if (nb_args - hyphen > 2)
			ft_putstr_fd_2(2, "env: ", infos->args[nb_args - hyphen],
					": No such file or directory\n", NULL);
		else
			print_env(infos, hyphen);
	}
}

void		ft_env(t_infos *infos)
{
	int		nb_args;

	modify_env_value("_", "env", &infos);
	nb_args = count_double_tbl(infos->args);
	if (nb_args == 1)
		print_list(infos->liste);
	else
		check_options_env(infos, nb_args);
}
