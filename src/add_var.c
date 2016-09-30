/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:11:41 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 11:15:59 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <unistd.h>

void	add_main_var(t_infos *infos)
{
	char		*path;
	char		*line;
	int			fd;

	fd = 0;
	path = NULL;
	if ((fd = open("/etc/paths", O_RDONLY)) > -1)
	{
		while (get_next_line(fd, &line) == 1)
		{
			if (path == NULL)
				path = ft_strdup(line);
			else
				path = ft_strjoin(ft_strjoin(path, ":"), line);
		}
		close(fd);
		create_one_elem("PATH", path, &infos);
		push_second_elem("_", "env", &infos);
		creat_var_env("OLDPWD", getcwd(NULL, 0), &infos);
		creat_var_env("SHLVL", "1", &infos);
		creat_var_env("PWD", getcwd(NULL, 0), &infos);
		free(path);
	}
}

char	*search_path(char *path, char **av, t_infos *infos)
{
	(void)infos;
	if ((ft_strcmp(av[0], "env") == 0) || (ft_strcmp(av[0], "setenv") == 0) ||
			(ft_strcmp(av[0], "unsetenv") == 0) ||
			(ft_strcmp(av[0], "echo") == 0) || (ft_strcmp(av[0], "exit") == 0)
			|| (ft_strcmp(av[0], "./minishell") == 0))
		return (path);
	else
		return (found_bin_path(infos, infos->args[0], 0));
}
