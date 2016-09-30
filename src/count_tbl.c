/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:38:55 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/26 14:05:19 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_double_tbl(char **tbl)
{
	int		count;

	count = 0;
	if (tbl == NULL)
		return (0);
	while (tbl[count])
		count++;
	return (count);
}
