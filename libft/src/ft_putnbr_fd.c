/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:08:55 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:08:57 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putmint(int n, int fd)
{
	if (n != -2147483648)
		return (0);
	write(fd, "2147483648", 10);
	return (1);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (ft_putmint(n, fd))
			return ;
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	n %= 10;
	c = (char)n + '0';
	write(fd, &c, 1);
}
