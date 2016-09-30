/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_oux_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:07:01 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:07:03 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char				*ft_oux_conv(t_options *stc, unsigned long long x)
{
	char				*sbase;
	char				*e_str;
	unsigned int		tmp_accu;

	tmp_accu = stc->accu;
	sbase = ft_str_base(stc->type);
	if (!(e_str = ft_oux_size(stc, x, sbase)))
		return (NULL);
	if (!(stc->fl & FT_LESS) && (!(stc->fl & FT_ZERO) || (stc->ck & FT_ACCU)))
		ft_memset(e_str, ' ', stc->area);
	ft_strcat(e_str, ft_flag_base(stc, x));
	if (!(stc->fl & FT_LESS) && (stc->fl & FT_ZERO) && !(stc->ck & FT_ACCU))
		ft_memset(e_str + ft_strlen(e_str), '0', stc->area);
	ft_memset(e_str + ft_strlen(e_str), '0', stc->accu);
	if (!(!x && (stc->ck & FT_ACCU) && tmp_accu == 0) && !(!x &&
			(stc->fl & FT_SHARP) && !tmp_accu &&
			(stc->type == FT_S_O || stc->type == FT_O)))
		ft_strcat(e_str, ft_lbasenum(x, sbase));
	if ((stc->fl & FT_LESS))
		ft_memset(e_str + ft_strlen(e_str), ' ', stc->area);
	return (e_str);
}

char				*ft_str_base(unsigned int type)
{
	char				*str;

	str = NULL;
	str = (type == FT_S_O || type == FT_O ? FTL_STR_OCT : str);
	str = (type == FT_S_U || type == FT_U ? FTL_STR_DEC : str);
	str = (type == FT_S_X || type == FT_S_P ? FT_STR_S_HEX : str);
	str = (type == FT_X ? FTL_STR_HEX : str);
	str = (type == FT_S_B || type == FT_B ? FTL_STR_BIN : str);
	return (str);
}

char				*ft_flag_base(t_options *stc, unsigned long long x)
{
	if (stc->type == FT_S_P || (stc->fl & FT_SHARP))
	{
		if (stc->type == FT_S_O || stc->type == FT_O)
			return (FT_FL_OCT);
		if (stc->type == FT_S_P || ((stc->type == FT_S_X || stc->type == FT_X)
				&& x))
			return ((stc->type == FT_X ? FT_FL_HEX : FT_FL_S_HEX));
		if (stc->type == FT_S_B || stc->type == FT_B)
			return ((stc->type == FT_S_B ? FT_FL_S_BIN : FT_FL_BIN));
	}
	return ("");
}
