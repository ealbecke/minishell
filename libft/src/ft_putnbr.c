/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:08:50 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:08:51 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putmint(int n)
{
	if (n != -2147483648)
		return (0);
	write(1, "2147483648", 10);
	return (1);
}

void		ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		if (ft_putmint(n))
			return ;
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	n %= 10;
	c = (char)n + '0';
	write(1, &c, 1);
}
