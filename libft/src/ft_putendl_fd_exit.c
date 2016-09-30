/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:08:40 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:08:42 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd_exit(char const *s, int fd, int exit_code)
{
	while (s && *s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
	exit(exit_code);
}
