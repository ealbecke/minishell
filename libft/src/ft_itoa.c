/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:02:58 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:03:00 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_numint(int n)
{
	char	*str;

	if (n != FTL_INTMIN)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * 12);
	ft_strcpy(str, "-2147483648");
	return (str);
}

static char	*ft_numdup(int n, int *pow)
{
	char	*str;

	if (n < 0)
	{
		*pow += 1;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		*pow += 1;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (*pow + 1))))
		return (NULL);
	str[*pow] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int				pow;
	char			*str;

	pow = 1;
	if ((str = ft_numint(n)))
		return (str);
	if (!(str = ft_numdup(n, &pow)))
		return (NULL);
	if (!n)
	{
		*str = '0';
		return (str);
	}
	if (n < 0)
	{
		*str = '-';
		n = -n;
	}
	while (pow-- >= 0 && n)
	{
		str[pow] = (char)((n % 10) + '0');
		n /= 10;
	}
	return (str);
}
