/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_di_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:06:35 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:06:40 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char				*ft_di_conv(t_options *stc, int num)
{
	char				*end_str;
	unsigned int		tmp_accu;

	tmp_accu = stc->accu;
	if (!(end_str = ft_di_size(stc, num)))
		return (NULL);
	if (!(stc->fl & FT_LESS) && (!(stc->fl & FT_ZERO) || (stc->ck & FT_ACCU)))
		ft_memset(end_str, ' ', stc->area);
	if (num < 0)
	{
		num = -num;
		ft_strcat(end_str, "-");
	}
	else if ((stc->fl & FT_MORE))
		ft_strcat(end_str, "+");
	else if ((stc->fl & FT_SPACE))
		ft_strcat(end_str, " ");
	if (!(stc->fl & FT_LESS) && (stc->fl & FT_ZERO) && !(stc->ck & FT_ACCU))
		ft_memset(end_str + ft_strlen(end_str), '0', stc->area);
	ft_memset(end_str + ft_strlen(end_str), '0', stc->accu);
	if (!(!num && (stc->ck & FT_ACCU) && tmp_accu == 0))
		ft_strcat(end_str, (num >= 0 ? ft_itoa(num) : ft_itoa(num) + 1));
	if ((stc->fl & FT_LESS))
		ft_memset(end_str + ft_strlen(end_str), ' ', stc->area);
	return (end_str);
}

char				*ft_ldi_conv(t_options *stc, long long int num)
{
	char				*end_str;
	unsigned int		tmp_accu;

	tmp_accu = stc->accu;
	if (!(end_str = ft_ldi_size(stc, num)))
		return (NULL);
	if (!(stc->fl & FT_LESS) && (!(stc->fl & FT_ZERO) || (stc->ck & FT_ACCU)))
		ft_memset(end_str, ' ', stc->area);
	if (num < 0)
	{
		num = -num;
		ft_strcat(end_str, "-");
	}
	else if ((stc->fl & FT_MORE))
		ft_strcat(end_str, "+");
	else if ((stc->fl & FT_SPACE))
		ft_strcat(end_str, " ");
	if (!(stc->fl & FT_LESS) && (stc->fl & FT_ZERO) && !(stc->ck & FT_ACCU))
		ft_memset(end_str + ft_strlen(end_str), '0', stc->area);
	ft_memset(end_str + ft_strlen(end_str), '0', stc->accu);
	if (!(!num && (stc->ck & FT_ACCU) && tmp_accu == 0))
		ft_strcat(end_str, (num >= 0 ? ft_litoa(num) : ft_litoa(num) + 1));
	if ((stc->fl & FT_LESS))
		ft_memset(end_str + ft_strlen(end_str), ' ', stc->area);
	return (end_str);
}

char				*ft_sdi_conv(t_options *stc, short num)
{
	char				*end_str;
	unsigned int		tmp_accu;

	tmp_accu = stc->accu;
	if (!(end_str = ft_di_size(stc, num)))
		return (NULL);
	if (!(stc->fl & FT_LESS) && (!(stc->fl & FT_ZERO) || (stc->ck & FT_ACCU)))
		ft_memset(end_str, ' ', stc->area);
	if (num < 0)
	{
		num = -num;
		ft_strcat(end_str, "-");
	}
	else if ((stc->fl & FT_MORE))
		ft_strcat(end_str, "+");
	else if ((stc->fl & FT_SPACE))
		ft_strcat(end_str, " ");
	if (!(stc->fl & FT_LESS) && (stc->fl & FT_ZERO) && !(stc->ck & FT_ACCU))
		ft_memset(end_str + ft_strlen(end_str), '0', stc->area);
	ft_memset(end_str + ft_strlen(end_str), '0', stc->accu);
	if (!(!num && (stc->ck & FT_ACCU) && tmp_accu == 0))
		ft_strcat(end_str, (num >= 0 ? ft_itoa(num) : ft_itoa(num) + 1));
	if ((stc->fl & FT_LESS))
		ft_memset(end_str + ft_strlen(end_str), ' ', stc->area);
	return (end_str);
}

char				*ft_cdi_conv(t_options *stc, char num)
{
	char				*end_str;
	unsigned int		tmp_accu;

	tmp_accu = stc->accu;
	if (!(end_str = ft_di_size(stc, num)))
		return (NULL);
	if (!(stc->fl & FT_LESS) && (!(stc->fl & FT_ZERO) || (stc->ck & FT_ACCU)))
		ft_memset(end_str, ' ', stc->area);
	if (num < 0)
	{
		num = -num;
		ft_strcat(end_str, "-");
	}
	else if ((stc->fl & FT_MORE))
		ft_strcat(end_str, "+");
	else if ((stc->fl & FT_SPACE))
		ft_strcat(end_str, " ");
	if (!(stc->fl & FT_LESS) && (stc->fl & FT_ZERO) && !(stc->ck & FT_ACCU))
		ft_memset(end_str + ft_strlen(end_str), '0', stc->area);
	ft_memset(end_str + ft_strlen(end_str), '0', stc->accu);
	if (!(!num && (stc->ck & FT_ACCU) && tmp_accu == 0))
		ft_strcat(end_str, (num >= 0 ? ft_itoa(num) : ft_itoa(num) + 1));
	if ((stc->fl & FT_LESS))
		ft_memset(end_str + ft_strlen(end_str), ' ', stc->area);
	return (end_str);
}
