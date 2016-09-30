/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:43:01 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 10:44:51 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		check_exec_env(t_infos *infos, char *path, int flag)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			ft_fork(infos, path, flag);
		else
		{
			ft_putstr_fd_2(2, "minishell: Permission denied", path, "\n", NULL);
			init_and_relaunch_get_line(infos);
		}
	}
	else
	{
		ft_putstr_fd_2(2, "minishell: no such file or directory",
				path, "\n", NULL);
		init_and_relaunch_get_line(infos);
	}
}

int			count_hiphen_option(t_infos *infos, char *str)
{
	int		count;
	int		i;
	int		u;

	i = 0;
	u = 0;
	count = 1;
	while (str[count])
	{
		if (str[count] == 'i')
			i = 1;
		else if (str[count] == 'u')
			u = 1;
		else if ((str[count] != 'u') || (str[count] != 'i'))
			break ;
		count++;
	}
	if (count >= (int)ft_strlen(str))
	{
		infos->i = i;
		infos->u = u;
		return (1);
	}
	return (0);
}

void		print_env_u(t_infos *infos, char **av, int hyphen)
{
	int			nb_args;
	t_liste		*current;

	nb_args = count_double_tbl(av);
	if ((nb_args - hyphen) > 2)
		ft_putstr_fd_2(2, "env: ", infos->args[nb_args - hyphen],
				": No such file or directory\n", NULL);
	if (nb_args == (hyphen + 1))
	{
		ft_putstr_fd_2(2, "env: option requires an argument -- \n", NULL);
	}
	current = infos->liste;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, av[nb_args - 1]) != 0)
		{
			ft_printf("%s", current->key);
			ft_printf("=");
			ft_printf("%s\n", current->value);
			current = current->next;
		}
		else
			current = current->next;
	}
}

void		print_env_i(t_infos *infos, char **av)
{
	int		nb_args;
	int		i;
	int		j;
	char	**tbl;

	i = 2;
	j = 0;
	tbl = NULL;
	nb_args = count_double_tbl(av);
	if (nb_args == 2)
		return ;
	tbl = (char **)malloc(sizeof(char **) * (nb_args - 1));
	while (infos->args[i])
	{
		tbl[j] = ft_strdup(av[i]);
		j++;
		i++;
	}
	tbl[j] = NULL;
	free_double_array(av);
	infos->args = tbl;
	ft_fork(infos, tbl[0], 0);
}

void		print_env(t_infos *infos, int hyphen)
{
	if (infos->i)
		print_env_i(infos, infos->args);
	else if (infos->u)
		print_env_u(infos, infos->args, hyphen);
	else
		return ;
}
