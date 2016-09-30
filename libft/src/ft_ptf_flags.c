/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:06:50 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:06:53 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft.h"
#include "ft_funtab.h"

int					ft_flag(const char *str, char **sflag, va_list ap, int *sc)
{
	int					len;
	t_options			mod;

	ft_stcoptclr(&mod);
	len = -1;
	while (str[++len] && !(mod.ck & FT_CHECK_FLAG) &&
			!(mod.type = ft_charflag(str[len], FT_TYPES)))
	{
		mod.ck |= FT_CHECK_FLAG;
		ft_simple_flag(str[len], &mod);
		len += ft_area_flag(str + len, &mod, ap);
		len += ft_accu_flag(str + len, &mod, ap);
		len += ft_cast_flag(str + len, &mod);
	}
	if (mod.type)
		*sflag = g_funtab[mod.type](&mod, ap);
	else if ((mod.ck & FT_CHECK_FLAG))
		*sflag = (str[len - 1] ? ft_char_conv(&mod, str[len - 1]) :
				ft_strsub(str + len - 1, 0, 1));
	else
		*sflag = (str[len] ? ft_char_conv(&mod, str[len]) :
				ft_strsub(str + len, 0, 1));
	*sc = mod.sc;
	return (len + (mod.type ? 1 : 0));
}

void				ft_simple_flag(char c, t_options *stc)
{
	t_flags				p_fl;

	if ((p_fl = ft_charflag(c, FT_FLAGS)))
	{
		stc->ck &= ~FT_CHECK_FLAG;
		stc->fl |= 1 << (p_fl - 1);
	}
}

unsigned int		ft_area_flag(const char *sarea, t_options *stc, va_list ap)
{
	if (sarea && stc && (('1' <= *sarea && *sarea <= '9') || *sarea == FT_STAR))
	{
		if (ft_isdigit(*sarea))
			stc->area = ft_atoi(sarea);
		else
			stc->area = va_arg(ap, int);
		stc->ck |= FT_AREA;
		stc->ck &= ~FT_CHECK_FLAG;
		if (*sarea == FT_STAR && (int)stc->area < 0)
		{
			stc->area = (int)(-stc->area);
			stc->fl |= FT_LESS;
		}
		if (stc->area >= FTL_B31)
			stc->area = 0;
		return (ft_digitlen(sarea + !(*sarea == FT_STAR)));
	}
	return (0);
}

unsigned int		ft_accu_flag(const char *saccu, t_options *stc, va_list ap)
{
	if (saccu && stc && *saccu == '.')
	{
		stc->ck |= FT_ACCU;
		stc->ck &= ~FT_CHECK_FLAG;
		saccu++;
		if (ft_isdigit(*saccu) || *saccu == FT_STAR)
		{
			if (ft_isdigit(*saccu))
				stc->accu = ft_atoi(saccu);
			else
				stc->accu = va_arg(ap, int);
			if ((int)stc->accu < 0)
			{
				stc->accu = 0;
				stc->ck &= ~FT_ACCU;
			}
			return (ft_digitlen(saccu) + (*saccu == FT_STAR));
		}
		stc->accu = 0;
	}
	return (0);
}

unsigned int		ft_cast_flag(const char *scast, t_options *stc)
{
	unsigned int		p_cast;

	if (scast && stc && (p_cast = ft_charflag(*scast, FT_CAST_FLAG)))
	{
		stc->ck |= FT_CAST;
		stc->ck &= ~FT_CHECK_FLAG;
		if (p_cast == FT_L && (stc->cast & FT_L))
			stc->cast |= FT_LL;
		else if (p_cast == FT_H && (stc->cast & FT_H))
		{
			stc->cast |= FT_HH;
			stc->cast &= ~FT_H;
		}
		else if (p_cast == FT_H && (stc->cast & FT_HH))
		{
			stc->cast |= FT_H;
			stc->cast &= ~FT_HH;
		}
		else
			stc->cast |= FTL_BIT_N(p_cast);
	}
	return (0);
}
