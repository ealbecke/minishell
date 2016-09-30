/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:04:03 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:04:05 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ltr;

	if (!alst || !*alst)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ltr = (*alst)->next;
	free(*alst);
	(*alst)->next = ltr;
	*alst = NULL;
}
