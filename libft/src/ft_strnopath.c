/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnopath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:01 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:13:03 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnopath(char *over_path)
{
	char				*end_path;

	if ((end_path = ft_strrchr(over_path, '/')))
		return (end_path + 1);
	else
		return (over_path);
}
