/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:06:30 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:06:32 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_stcoptclr(t_options *stc)
{
	stc->ck = 0;
	stc->fl = 0;
	stc->area = 0;
	stc->accu = 0;
	stc->cast = 0;
	stc->type = 0;
	stc->sc = 0;
}

void				ft_stcmainclr(t_main *stc)
{
	stc->n = 0;
	stc->tot_size = 0;
}
