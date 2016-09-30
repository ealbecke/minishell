/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:04:41 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:04:44 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	char	*ctt;
	char	*cpy;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	if (!content || !content_size)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	ctt = (void *)content;
	new->content_size = content_size;
	cpy = (char *)malloc(sizeof(*cpy) * content_size);
	while (content_size--)
		cpy[content_size] = ctt[content_size];
	new->content = cpy;
	return (new);
}
