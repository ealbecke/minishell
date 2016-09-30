/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:06:18 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:06:19 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <wchar.h>
#include <inttypes.h>

char				*ft_s_arg(t_options *stc, va_list ap)
{
	if ((stc->cast & FT_L) || stc->type == FT_WCS)
		return (ft_wcs_conv(stc, va_arg(ap, wchar_t *)));
	return (ft_str_conv(stc, va_arg(ap, char *)));
}

char				*ft_c_arg(t_options *stc, va_list ap)
{
	if ((stc->cast & FT_L) || stc->type == FT_WIC)
		return (ft_wi_conv(stc, va_arg(ap, wint_t)));
	return (ft_char_conv(stc, va_arg(ap, int)));
}

char				*ft_di_arg(t_options *stc, va_list ap)
{
	if (stc->cast & FT_LL)
		return (ft_ldi_conv(stc, va_arg(ap, long long)));
	if ((stc->cast & FT_L) || stc->type == FT_D)
		return (ft_ldi_conv(stc, va_arg(ap, long)));
	if (stc->cast & FT_J)
		return (ft_ldi_conv(stc, va_arg(ap, intmax_t)));
	if (stc->cast & FT_Z)
		return (ft_ldi_conv(stc, va_arg(ap, size_t)));
	if (stc->cast & FT_H)
		return (ft_sdi_conv(stc, va_arg(ap, int)));
	if (stc->cast & FT_HH)
		return (ft_cdi_conv(stc, va_arg(ap, int)));
	return (ft_di_conv(stc, va_arg(ap, int)));
}

char				*ft_oux_arg(t_options *stc, va_list ap)
{
	if (stc->cast & FT_LL)
		return (ft_oux_conv(stc, va_arg(ap, unsigned long long)));
	if ((stc->cast & FT_L) || stc->type == FT_O || stc->type == FT_U)
		return (ft_oux_conv(stc, va_arg(ap, unsigned long)));
	if (stc->cast & FT_J)
		return (ft_oux_conv(stc, va_arg(ap, uintmax_t)));
	if (stc->cast & FT_Z)
		return (ft_oux_conv(stc, va_arg(ap, size_t)));
	if (stc->cast == FT_H)
		return (ft_oux_conv(stc, (unsigned short)va_arg(ap, unsigned int)));
	if (stc->cast == FT_HH)
		return (ft_oux_conv(stc, (unsigned char)va_arg(ap, unsigned int)));
	return (ft_oux_conv(stc, va_arg(ap, unsigned int)));
}

char				*ft_p_arg(t_options *stc, va_list ap)
{
	stc->fl |= FT_SHARP;
	return (ft_oux_conv(stc, (unsigned long)va_arg(ap, void *)));
}
