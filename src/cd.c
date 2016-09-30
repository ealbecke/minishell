/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 10:02:25 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 13:52:06 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_var_env(t_infos *infos, t_liste *liste)
{
	char *value;

	value = NULL;
	modify_env_value("OLDPWD", query_env("PWD", liste, 1), &infos);
	modify_env_value("_", query_env("PWD", liste, 1), &infos);
	value = getcwd(NULL, 0);
	modify_env_value("PWD", value, &infos);
	free(value);
}

void	ft_cd_change_dir(t_infos *info, t_liste *liste)
{
	struct stat		stat;

	if (ft_strcmp(info->args[1], "-") == 0)
		cd_go_before(info);
	else if (info->args[1][0] == '~')
		tilde(info, info->args[1]);
	else if (access(info->args[1], F_OK) == 0)
	{
		lstat(info->args[1], &stat);
		if (!S_ISDIR(stat.st_mode) && !S_ISLNK(stat.st_mode))
			ft_putstr_fd_2(2, "not a directory: ", info->args[1], "\n", NULL);
		else if (access(info->args[1], X_OK) == 0)
		{
			if (chdir(info->args[1]) == 0)
				change_var_env(info, liste);
		}
		else
			ft_putstr_fd_2(2, "permission denied: ", info->args[1], "\n", NULL);
	}
	else
	{
		ft_putstr_fd_2(2, "no file or directory: ", info->args[1], "\n", NULL);
		init_and_relaunch_get_line(info);
	}
}

void	ft_cd_go_home(t_infos *infos)
{
	modify_env_value("OLDPWD", query_env("PWD", infos->liste, 1), &infos);
	modify_env_value("_", query_env("PWD", infos->liste, 1), &infos);
	modify_env_value("PWD", query_env("HOME", infos->liste, 1), &infos);
	if (chdir(query_env("HOME", infos->liste, 1)) < 0)
		return ;
}

void	replace_occurence(char *occurence, char *path, char **split_av)
{
	int		i;
	int		len;
	int		nb;
	char	*tmp;

	nb = 0;
	i = 0;
	len = 0;
	nb = ft_strlen(occurence);
	i = ft_strlen(split_av[1]);
	len = ft_strlen(path);
	tmp = ft_strsub(occurence, i, len - i);
	occurence = NULL;
	occurence = ft_strdup(split_av[2]);
	occurence = ft_strjoin(occurence, tmp);
	free(tmp);
	tmp = NULL;
	len = 0;
	len = ft_strlen(path);
	tmp = ft_strsub(path, 0, len - nb);
	tmp = ft_strjoin(tmp, occurence);
	free(occurence);
	ft_putstr_fd_2(2, "cd: no such file or directory: ", tmp, "\n", NULL);
	free(tmp);
}

void	ft_replace_cd_path(t_infos *infos)
{
	char	*current_path;
	char	*occurence;

	current_path = query_env("PWD", infos->liste, 1);
	occurence = ft_strstr(current_path, infos->args[1]);
	if (occurence != NULL)
		replace_occurence(occurence, current_path, infos->args);
	else
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putstr_fd(infos->args[1], 2);
		ft_putstr_fd("\n", 2);
	}
}
