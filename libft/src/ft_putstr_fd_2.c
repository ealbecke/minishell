/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 11:37:31 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/28 11:38:18 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd_2(int fd, ...)
{
	int		i;
	char	*str;
	va_list	ap;

	va_start(ap, fd);
	str = va_arg(ap, char*);
	while (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			write(fd, &(str[i]), 1);
			i++;
		}
		str = va_arg(ap, char*);
	}
	va_end(ap);
}
