/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 16:24:51 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/27 12:07:39 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_line(char *line_gnl)
{
	int		i;
	char	**split_line;
	char	*line;

	line = ft_strtrim(line_gnl);
	free(line_gnl);
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	split_line = ft_strsplit(line, ' ');
	free(line);
	return (split_line);
}
