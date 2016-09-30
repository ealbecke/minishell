/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_sprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:07:19 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:07:26 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft.h"

int					ft_sprintf(char *str, const char *format, ...)
{
	static int			end_n = 0;
	va_list				ap;
	char				*now_str;
	t_main				count;

	ft_stcmainclr(&count);
	va_start(ap, format);
	while (format && format[count.n])
	{
		*str = (count.n ? *str : '\0');
		count.sc = 0;
		count.n += ft_next_flag(format + count.n, &now_str, FT_BEG_FLAG);
		if (format[count.n] == FT_BEG_FLAG)
			count.n += ft_conv_flag(format + count.n + 1, &now_str, ap,
					&count.sc) + 1;
		if (!now_str)
			return ((end_n = FT_ERROR));
		count.tot_size += (count.sc ? count.sc : (count.sc =
				(int)ft_strlen(now_str)));
		ft_memcat(str, now_str, count);
		free(now_str);
	}
	va_end(ap);
	return ((end_n = (end_n < 0 ? end_n : count.tot_size)));
}

void				ft_memcat(char *dst, const char *cat, t_main cnt)
{
	ft_memcpy(dst + cnt.tot_size - cnt.sc, cat, cnt.sc);
	dst[cnt.tot_size] = '\0';
}
