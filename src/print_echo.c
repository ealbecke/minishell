/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 11:37:34 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 10:48:42 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_is_str_all_upper(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(str);
	while (str[i])
	{
		if ((str[i] < 'A') || (str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_str_all_lower(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(str);
	while (str[i])
	{
		if ((str[i] < 'a') || (str[i] > 'z'))
			return (0);
		i++;
	}
	return (1);
}

char		*check_up_low(t_infos *infos, char *str)
{
	if (str[0] > 'a' && str[0] < 'z')
	{
		if (ft_is_str_all_lower(str) == 0)
		{
			if (count_double_tbl(infos->args) == 1)
				ft_printf("\n");
			init_and_relaunch_get_line(infos);
		}
		return (ft_convert_maj(str));
	}
	else if (str[0] > 'A' && str[0] < 'Z')
	{
		if (ft_is_str_all_upper(str) == 0)
		{
			if (count_double_tbl(infos->args) == 1)
				ft_printf("\n");
			init_and_relaunch_get_line(infos);
		}
		return (str);
	}
	else
		return (str);
	return (NULL);
}

void		check_var_env(t_infos *infos, char *av)
{
	char	*str;
	char	*ret;

	str = ft_strsub(av, 1, (ft_strlen(av) - 1));
	str = check_up_low(infos, str);
	ret = query_env(str, infos->liste, 1);
	if (ret != NULL)
		ft_printf("%s ", ret);
	free(str);
}

void		print_value(t_infos *infos, char **av, int begin)
{
	char	*str;

	(void)av;
	str = check_quote_args(infos, begin);
	if (str && str[0] == '$')
	{
		if (ft_strlen(str) == 1 && str[0] == '$')
			ft_printf("$ ");
		else if (ft_strlen(str) == 2 && str[1] == '$')
			ft_printf("23180 ");
		else
			check_var_env(infos, str);
	}
	str = NULL;
}
