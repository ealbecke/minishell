/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:09 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:13:10 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strpath(const char *origin, char *file)
{
	char				*end_path;
	size_t				size_origin;

	size_origin = ft_strlen(origin);
	end_path = ft_strnew(size_origin + ft_strlen(file) + 1);
	ft_strcpy(end_path, origin);
	end_path[size_origin] = '/';
	ft_strcat(end_path, file);
	return (end_path);
}
