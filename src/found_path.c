/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:18:58 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 11:27:01 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*fnd_bin_path(DIR *dir, char **split_path, char *path, int i)
{
	char			*str_1;
	char			*str_2;

	str_1 = NULL;
	str_2 = NULL;
	closedir(dir);
	str_1 = ft_strjoin(split_path[i], "/");
	free_double_array(split_path);
	str_2 = ft_strjoin(str_1, path);
	free(str_1);
	return (str_2);
}

char			*found_bin_path(t_infos *infos, char *path, int i)
{
	char			**split_path;
	DIR				*dir;
	struct dirent	*r_dir;

	split_path = NULL;
	if ((split_path = exist_path(infos)) == NULL)
		return (NULL);
	while (split_path[i])
	{
		if ((dir = opendir(split_path[i])) == NULL)
			return (NULL);
		while (dir && (r_dir = readdir(dir)))
		{
			if (ft_strequ(r_dir->d_name, path))
				return (fnd_bin_path(dir, split_path, path, i));
		}
		closedir(dir);
		i++;
	}
	free_double_array(split_path);
	return (NULL);
}
