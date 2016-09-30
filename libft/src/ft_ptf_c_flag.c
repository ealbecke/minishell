/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_c_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:06:25 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:06:27 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include "libft.h"

char				*ft_char_conv(t_options *stc, unsigned int c)
{
	char				*end_str;

	if (!(end_str = ft_strnew(stc->area ? stc->area : 1)))
		return (NULL);
	if (stc->area)
	{
		if (!(stc->fl & FT_LESS))
			ft_memset(end_str, ((stc->fl & FT_ZERO) ? '0' : ' '),
					stc->area - 1);
		end_str[ft_strlen(end_str)] = (char)c;
		if ((stc->fl & FT_LESS))
			ft_memset(end_str + 1, ' ', stc->area - 1);
		stc->sc = stc->area;
	}
	else
	{
		*end_str = (char)c;
		stc->sc = 1;
	}
	return (end_str);
}

char				*ft_wi_conv(t_options *stc, wchar_t wic)
{
	char				*end_str;
	unsigned int		len_str;

	if (!(len_str = ft_convunilen(wic)) ||
			!(end_str = ft_strnew((len_str < stc->area ? stc->area : len_str))))
		return (NULL);
	stc->sc = (len_str < stc->area ? stc->area : len_str);
	if (!(stc->fl & FT_LESS) && len_str < stc->area)
		ft_memset(end_str, ((stc->fl & FT_ZERO) ? '0' : ' '),
				stc->area - len_str);
	if (!wic)
		end_str[len_str - 1] = 0;
	else
		ft_strcat(end_str, ft_wcconvuni(wic));
	if ((stc->fl & FT_LESS) && len_str < stc->area)
		ft_memset(end_str + len_str, ' ', stc->area - len_str);
	return (end_str);
}
