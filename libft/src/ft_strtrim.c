/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:38 by ealbecke          #+#    #+#             */
/*   Updated: 2016/08/07 11:23:45 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	n;
	char			*str;

	if (!s)
		return (NULL);
	i = 1;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s && s[i])
		i++;
	i--;
	while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	if (!(str = (char *)malloc(sizeof(*str) * (++i + 1))))
		return (NULL);
	n = -1;
	while (++n < i)
		str[n] = s[n];
	str[n] = '\0';
	return (str);
}
