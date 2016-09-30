/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_vdprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:07:46 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:07:48 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

int					ft_vdprintf(int fd, const char *format, va_list ap)
{
	static int			end_n = 0;
	char				*now_str;
	t_main				count;

	ft_stcmainclr(&count);
	while (format && format[count.n])
	{
		count.sc = 0;
		count.n += ft_next_flag(format + count.n, &now_str, FT_BEG_FLAG);
		if (format[count.n] == FT_BEG_FLAG)
			count.n += ft_conv_flag(format + count.n + 1, &now_str, ap,
					&count.sc) + 1;
		if (!now_str)
			return ((end_n = FT_ERROR));
		count.tot_size += (count.sc ? count.sc : (count.sc =
				(int)ft_strlen(now_str)));
		write(fd, now_str, count.sc);
		free(now_str);
	}
	return ((end_n = (end_n < 0 ? end_n : count.tot_size)));
}
