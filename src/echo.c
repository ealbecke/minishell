/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:33:51 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 10:44:21 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			count_hyphen(char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (av[i] && av[i][0] == '-' && !av[i][1])
		return (-1);
	while (av[i] && av[i][0] == '-')
	{
		j++;
		i++;
	}
	return (j);
}

int			inspect_args(t_infos *infos, char *str)
{
	int		i;
	int		e;
	int		n;

	i = 1;
	e = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == 'e')
			e = 1;
		else if (str[i] == 'n')
			n = 1;
		else if ((str[i] != 'n') || (str[i] != 'e'))
			break ;
		i++;
	}
	if (i < (int)ft_strlen(str))
		return (0);
	else
	{
		infos->e = e;
		infos->n = n;
		return (1);
	}
}

int			match_option(t_infos *infos, char **av, int end)
{
	int		i;

	i = 1;
	if (end == 1 && (inspect_args(infos, av[i]) == 1))
		return (2);
	else if (end == 1 && (inspect_args(infos, av[i]) == 0))
		return (1);
	while (i <= end)
	{
		if (inspect_args(infos, av[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

void		check_options(t_infos *infos, int nb_args)
{
	int		hyphen;
	int		end;

	hyphen = count_hyphen(infos->args);
	if (hyphen == 0)
	{
		print_value(infos, infos->args, 1);
	}
	else
	{
		end = match_option(infos, infos->args, hyphen);
		if (nb_args == (hyphen + 1))
			return ;
		print_value(infos, infos->args, end);
	}
}

void		ft_echo(t_infos *infos)
{
	int		nb_args;

	nb_args = count_double_tbl(infos->args);
	if (nb_args == 1)
		ft_printf("\n");
	else
		check_options(infos, nb_args);
	if (infos->n == 0 && nb_args > 1)
		ft_printf("\n");
}
