/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 13:56:53 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 11:25:03 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern pid_t	g_child_pid;

void	ft_fork(t_infos *infos, char *path, int flag)
{
	pid_t	fork_val;
	int		ret;

	fork_val = fork();
	if (fork_val == 0)
	{
		if (flag == 0)
		{
			if ((ret = execve(search_path(path, infos->args, infos),
							infos->args, NULL)) == -1)
				error_exec(infos, path);
		}
		if ((ret = execve(path, infos->args, infos->tbl_linklist)) == -1)
			error_exec(infos, path);
	}
	if (fork_val > 0)
	{
		g_child_pid = fork_val;
		wait(&ret);
		signal_error(ret, infos->args);
		g_child_pid = 0;
		init_and_relaunch_get_line(infos);
	}
}

void	check_executable(t_infos *infos, char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
		{
			create_linkedlist_in_tbl(infos);
			ft_fork(infos, path, 1);
		}
		else
		{
			ft_putstr_fd_2(2, "minishell: permission denied", path, "\n", NULL);
			init_and_relaunch_get_line(infos);
		}
	}
	else
	{
		ft_putstr_fd_2(2, "minishell: ", path, ": no such file or directory\n"
				, NULL);
		init_and_relaunch_get_line(infos);
	}
}

void	launch(t_infos **infos)
{
	if (ft_check_builtins(*infos) == 1)
		init_and_relaunch_get_line(*infos);
	if (((*infos)->bin = found_bin_path(*infos, (*infos)->args[0], 0)))
		check_executable(*infos, (*infos)->bin);
	if (ft_strchr((*infos)->args[0], '/') != NULL)
		check_executable(*infos, (*infos)->args[0]);
	else
	{
		ft_putstr_fd_2(2, "minishell: command not found: ", (*infos)->args[0],
				"\n", NULL);
		init_and_relaunch_get_line(*infos);
	}
}

void	get_line(t_infos *infos)
{
	char	*line;

	line = NULL;
	if (infos->args == NULL)
	{
		if (count_node_list(infos->liste) == 0)
			add_main_var(infos);
		print_prompt(infos->liste);
		while ((get_next_line(0, &line)) <= 0)
			ft_exit(infos);
		infos->args = ft_split_line(line);
		get_line(infos);
	}
	else if (infos->args != NULL)
	{
		if (count_double_tbl(infos->args) == 0)
			init_and_relaunch_get_line(infos);
		else
			launch(&infos);
	}
}
