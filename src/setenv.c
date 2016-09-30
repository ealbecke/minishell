/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 12:25:04 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/29 14:30:30 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv_second(char **av)
{
	char	*ret;
	char	*str;

	ret = ft_strchr(av[1], '=');
	str = ft_strsub(ret, 2, ft_strlen(ret) - 2);
	ft_putstr_fd_2(2, "minishell: ", str, " not found\n", NULL);
	free(str);
}

void	ft_setenv(t_infos *infos)
{
	char	**split;
	int		nb_elem;

	if ((count_double_tbl(infos->args) <= 1) ||
			(ft_strchr(infos->args[1], '=') == NULL))
		return ;
	if (count_occurence(infos->args[1], '=') > 2)
		return (ft_setenv_second(infos->args));
	split = ft_strsplit(infos->args[1], '=');
	if (query_env(split[0], infos->liste, 0) == NULL)
	{
		nb_elem = count_node_list(infos->liste);
		if (nb_elem == 0)
			create_one_elem(split[0], split[1], &infos);
		else if (nb_elem == 1)
			push_second_elem(split[0], split[1], &infos);
		else
			creat_var_env(split[0], split[1], &infos);
	}
	else
		modify_env_value(split[0], split[1], &infos);
	free_double_array(split);
}
