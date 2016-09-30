/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:08:46 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:08:47 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int					ft_puterr(const char *s1, const char *s2, const char *issu)
{
	if (s1 && s2 && issu)
		ft_dprintf(FTL_OUT_ERR, "%s: [%s] %s\n", s1, s2, issu);
	else if (s1 && issu)
		ft_dprintf(FTL_OUT_ERR, "%s: %s\n", s1, issu);
	else if (issu)
		ft_dprintf(FTL_OUT_ERR, "%s\n", issu);
	return (FTL_ERROR);
}
