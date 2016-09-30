/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 11:46:54 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 10:50:20 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*ft_strtrim_quote(char *s)
{
	unsigned int	i;
	unsigned int	n;
	char			*str;

	if (!s)
		return (NULL);
	i = 1;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == 39 || *s == 34)
		s++;
	while (s[i])
		i++;
	i--;
	while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' ||
				s[i] == 39 || s[i] == 34))
		i--;
	if (!(str = (char *)malloc(sizeof(char *) * (++i + 1))))
		return (NULL);
	n = -1;
	while (++n < i)
		str[n] = s[n];
	str[n] = '\0';
	return (str);
}
