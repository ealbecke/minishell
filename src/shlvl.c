/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 15:24:07 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/28 09:39:01 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shlvl(t_infos *infos)
{
	int		shlvl;
	char	*result_itoa;
	char	*ret;

	ret = query_env("SHLVL", infos->liste, 1);
	if (ret != NULL)
	{
		shlvl = ft_atoi(ret);
		shlvl++;
	}
	else
	{
		creat_var_env("SHLVL", "1", &infos);
		return ;
	}
	result_itoa = ft_itoa(shlvl);
	modify_env_value("SHLVL", result_itoa, &infos);
	free(result_itoa);
}
