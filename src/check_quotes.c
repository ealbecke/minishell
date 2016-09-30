/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:35:02 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 11:54:19 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			count_quote(t_infos *infos, int i)
{
	int		nb_quote;
	int		j;

	nb_quote = 0;
	j = 0;
	while (infos->args[i])
	{
		while (infos->args[i][j])
		{
			if ((infos->args[i][j] == 39) || (infos->args[i][j] == 34))
				nb_quote++;
			j++;
		}
		j = 0;
		i++;
	}
	return (nb_quote);
}

void		ft_no_quote(t_infos *infos, int tmp)
{
	while (infos->args[tmp])
	{
		if (infos->args[tmp][0] == '$')
			check_var_env(infos, infos->args[tmp]);
		else
			ft_printf("%s ", infos->args[tmp]);
		tmp++;
	}
}

void		ft_quote(t_infos *infos, int i)
{
	char	*str;

	str = NULL;
	while (infos->args[i])
	{
		str = ft_strtrim_quote(infos->args[i]);
		if (str[0] == '$')
			check_var_env(infos, str);
		else
			ft_printf("%s ", str);
		i++;
		free(str);
		str = NULL;
	}
}

char		*check_quote_args(t_infos *infos, int i)
{
	int		tmp;
	int		nb_quote;

	tmp = i;
	nb_quote = count_quote(infos, i);
	i = tmp;
	if (nb_quote == 0)
		ft_no_quote(infos, tmp);
	if (nb_quote % 2 != 0)
	{
		ft_putstr_fd_2(2, "ERROR with quotes", "\n", NULL);
		init_and_relaunch_get_line(infos);
	}
	else if (nb_quote > 0)
		ft_quote(infos, i);
	return (NULL);
}
