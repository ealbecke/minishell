/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:04:34 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:04:37 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tnew;
	t_list	*tlst;

	if (!lst || !f || !*f)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	tnew = new;
	tlst = lst->next;
	while (tlst)
	{
		if (!(tnew->next = f(tlst)))
			return (NULL);
		tnew = tnew->next;
		tlst = tlst->next;
	}
	return (new);
}
