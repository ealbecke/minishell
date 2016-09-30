/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 13:16:43 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/16 13:55:35 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_error(int ret, char **av)
{
	if (WIFSIGNALED(ret))
	{
		if (WTERMSIG(ret) == SIGSEGV)
		{
			ft_putstr("minishell: segmentation fault  ");
			ft_putendl(av[0]);
		}
		else if (WTERMSIG(ret) == SIGFPE)
		{
			ft_putstr("minishell: floating point exception  ");
			ft_putendl(av[0]);
		}
		else if (WTERMSIG(ret) == SIGBUS)
		{
			ft_putstr("minishell: bus error  ");
			ft_putendl(av[0]);
		}
	}
}
