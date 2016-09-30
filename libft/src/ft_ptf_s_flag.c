/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_s_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:07:12 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:07:14 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include "libft.h"

char				*ft_str_conv(t_options *stc, char *str)
{
	char				*end_str;
	unsigned int		len_str;

	len_str = ft_strlen(str);
	if (!str)
		len_str = ft_strlen(FT_NULL);
	if (stc->accu < len_str && stc->ck & FT_ACCU)
		len_str = stc->accu;
	if (!(end_str = ft_strnew((stc->area > len_str ? stc->area : len_str))))
		return (NULL);
	if (!(stc->fl & FT_LESS) && len_str < stc->area)
		ft_memset(end_str, ((stc->fl & FT_ZERO) ? '0' : ' '),
				stc->area - len_str);
	ft_strncat(end_str, (str ? str : FT_NULL), len_str);
	if ((stc->fl & FT_LESS) && len_str < stc->area)
		ft_memset(end_str + len_str, ' ', stc->area - len_str);
	return (end_str);
}

char				*ft_wcs_conv(t_options *stc, wchar_t *wcs)
{
	char				*end_str;
	char				*tmp_str;
	unsigned int		lstr;
	int					tmp_len;

	if (!(lstr = ft_wcsconv_len(stc, wcs)) ||
			!(end_str = ft_strnew((lstr < stc->area ? stc->area : lstr))))
		return (NULL);
	if ((stc->ck & FT_ACCU) && (stc->accu == 0 ||
			stc->accu < ft_convunilen(*wcs)))
		lstr--;
	if (!(stc->fl & FT_LESS) && lstr < stc->area)
		ft_memset(end_str, ((stc->fl & FT_ZERO) ? '0' : ' '), stc->area - lstr);
	tmp_len = (int)lstr;
	while (wcs && *wcs && (tmp_str = ft_wcconvuni(*wcs)) &&
			(((tmp_len -= ft_convunilen(*wcs)) >= 0 && (stc->ck & FT_ACCU &&
			stc->accu != 0)) || !(stc->ck & FT_ACCU)))
	{
		ft_strcat(end_str, tmp_str);
		wcs++;
	}
	(!wcs && !FT_NOACCU(stc) ? ft_strncat(end_str, FT_NULL, lstr) : "");
	if ((stc->fl & FT_LESS) && lstr < stc->area)
		ft_memset(end_str + lstr, ' ', stc->area - lstr);
	return (end_str);
}

unsigned int		ft_wcsconv_len(t_options *stc, wchar_t *wcs)
{
	unsigned int		len_wcs;
	unsigned int		p_len_wcs;

	len_wcs = 0;
	p_len_wcs = 0;
	if ((wcs && !*wcs) || ((stc->ck & FT_ACCU) && (stc->accu == 0 ||
			stc->accu < ft_convunilen(*wcs))))
		return (1);
	while (wcs && *wcs && ((len_wcs + p_len_wcs <= stc->accu &&
			stc->ck & FT_ACCU) || !(stc->ck & FT_ACCU)))
	{
		if (((p_len_wcs = ft_convunilen(*wcs)) + len_wcs <= stc->accu &&
					(stc->ck & FT_ACCU)) || !(stc->ck & FT_ACCU))
			len_wcs += p_len_wcs;
		if (!p_len_wcs)
			return (0);
		wcs++;
	}
	if (!wcs)
		len_wcs = ft_strlen(FT_NULL);
	return (len_wcs);
}
