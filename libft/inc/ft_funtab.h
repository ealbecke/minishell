/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funtab.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:42:19 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:42:20 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNTAB_H
# define FT_FUNTAB_H

typedef char	*(*t_funtab)(t_options *, va_list);

t_funtab		g_funtab[] =
{
	ft_di_arg,
	ft_s_arg,
	ft_s_arg,
	ft_di_arg,
	ft_di_arg,
	ft_di_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_oux_arg,
	ft_c_arg,
	ft_c_arg,
	ft_p_arg,
	ft_oux_arg,
	ft_oux_arg
};

#endif
