/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:13:18 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 12:05:07 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len_c_stop(const char *str, int start, char c_stop)
{
	size_t		counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[start] && (str[start] != c_stop))
	{
		start++;
		counter++;
	}
	return (counter);
}

static int			ft_split_count(char *str, char c)
{
	int		count_word;
	int		counter;

	counter = 0;
	count_word = 0;
	while (str[counter])
	{
		while (str[counter] && str[counter] != c)
			counter++;
		while (str[counter] && str[counter] == c)
			counter++;
		count_word++;
	}
	return (count_word);
}

char				**ft_strsplit(char const *s, char c)
{
	int				count_word;
	int				i;
	unsigned int	counter;
	char			**array_s;
	char			*str;

	str = (char *)s;
	if (!str || *str == 0)
		return (NULL);
	count_word = ft_split_count(str, c);
	array_s = (char**)ft_memalloc(sizeof(char*) * (count_word + 1));
	i = 0;
	counter = 0;
	while (i < count_word)
	{
		while ((str[counter] == (char)c) && str[counter])
			counter++;
		array_s[i] = ft_strsub(str, counter, ft_len_c_stop(str, counter, c));
		while ((str[counter] != (char)c) && str[counter])
			counter++;
		i++;
	}
	array_s[i] = 0;
	return (array_s);
}
