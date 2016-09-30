/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:58:54 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/28 11:41:59 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_args(t_infos **infos)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while ((*infos)->args[0][i])
	{
		if ((*infos)->args[0][i] == '/')
			ret = 1;
		i++;
	}
	if (ret == 1)
		ft_putstr_fd_2(2, "minishell: no such file or directory: ",
				(*infos)->args[0], "\n", NULL);
	else
		ft_putstr_fd_2(2, "minishell: command not found: ",
				(*infos)->args[0], "\n", NULL);
}

void	error_exec(t_infos *infos, char *path)
{
	struct stat		stat;

	if (access(path, F_OK) == 0)
	{
		lstat(path, &stat);
		if (!S_ISDIR(stat.st_mode))
		{
			ft_putstr_fd_2(2, "env: ", path, ": No such file or directory\n",
					NULL);
			init_and_relaunch_get_line(infos);
		}
	}
	ft_putstr_fd_2(2, "minishell: permission denid", path, "\n", NULL);
	init_and_relaunch_get_line(infos);
}
