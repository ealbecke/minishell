/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_funcflag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:06:55 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:06:58 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char				*ft_di_size(t_options *stc, int n)
{
	unsigned int		lenum;
	unsigned int		len;
	unsigned int		tmp;
	t_boolean			sig;

	if (!stc)
		return (NULL);
	sig = (n < 0 || (stc->fl & FT_SPACE) || (stc->fl & FT_MORE) ? T_ : F_);
	lenum = ft_lnumlen(n) - (n < 0) - (!n && (stc->ck & FT_ACCU) &&
			stc->accu == 0);
	tmp = (stc->accu > lenum ? stc->accu : lenum);
	len = (stc->area > tmp + sig ? stc->area : tmp + sig);
	stc->area = (stc->area > tmp + sig ? stc->area - (tmp + sig) : 0);
	stc->accu = (stc->accu > lenum ? stc->accu - lenum : 0);
	return (ft_strnew(len));
}

char				*ft_ldi_size(t_options *stc, long long int n)
{
	unsigned int		lenum;
	unsigned int		len;
	unsigned int		tmp;
	t_boolean			sig;

	if (!stc)
		return (NULL);
	sig = (n < 0 || (stc->fl & FT_SPACE) || (stc->fl & FT_MORE) ? T_ : F_);
	lenum = ft_lnumlen(n) - (n < 0) - (!n && (stc->ck & FT_ACCU) &&
			stc->accu == 0);
	tmp = (stc->accu > lenum ? stc->accu : lenum);
	len = (stc->area > tmp + sig ? stc->area : tmp + sig);
	stc->area = (stc->area > tmp + sig ? stc->area - (tmp + sig) : 0);
	stc->accu = (stc->accu > lenum ? stc->accu - lenum : 0);
	return (ft_strnew(len));
}

char				*ft_sdi_size(t_options *stc, short n)
{
	unsigned int		lenum;
	unsigned int		len;
	unsigned int		tmp;
	t_boolean			sig;

	if (!stc)
		return (NULL);
	sig = (n < 0 || (stc->fl & FT_SPACE) || (stc->fl & FT_MORE) ? T_ : F_);
	lenum = ft_numlen((int)n) - (n < 0) - (!n && (stc->ck & FT_ACCU) &&
			stc->accu == 0);
	tmp = (stc->accu > lenum ? stc->accu : lenum);
	len = (stc->area > tmp + sig ? stc->area : tmp + sig);
	stc->area = (stc->area > tmp + sig ? stc->area - (tmp + sig) : 0);
	stc->accu = (stc->accu > lenum ? stc->accu - lenum : 0);
	return (ft_strnew(len));
}

char				*ft_cdi_size(t_options *stc, char n)
{
	unsigned int		lenum;
	unsigned int		len;
	unsigned int		tmp;
	t_boolean			sig;

	if (!stc)
		return (NULL);
	sig = (n < 0 || (stc->fl & FT_SPACE) || (stc->fl & FT_MORE) ? T_ : F_);
	lenum = ft_numlen((int)n) - (n < 0) - (!n && (stc->ck & FT_ACCU) &&
			stc->accu == 0);
	tmp = (stc->accu > lenum ? stc->accu : lenum);
	len = (stc->area > tmp + sig ? stc->area : tmp + sig);
	stc->area = (stc->area > tmp + sig ? stc->area - (tmp + sig) : 0);
	stc->accu = (stc->accu > lenum ? stc->accu - lenum : 0);
	return (ft_strnew(len));
}

char				*ft_oux_size(t_options *stc, unsigned long long n, char *bs)
{
	unsigned int		lenum;
	unsigned int		len;
	unsigned int		tmp;
	unsigned int		sig;

	if (!stc)
		return (NULL);
	lenum = ft_lbasesize(n, ft_strlen(bs)) - (!n && (((stc->ck & FT_ACCU) &&
			stc->accu == 0)));
	sig = ((stc->fl & FT_SHARP) && (stc->type == FT_S_O || stc->type == FT_O)
			&& (n || stc->accu) ? 1 : 0);
	sig = ((stc->fl & FT_SHARP) && (((stc->type == FT_S_X || stc->type == FT_X)
			&& n) || stc->type == FT_S_P) ? 2 : sig);
	tmp = (stc->accu > lenum ? stc->accu : lenum);
	len = (stc->area > tmp + sig ? stc->area : tmp + sig);
	stc->area = (stc->area > tmp + sig ? stc->area - (tmp + sig) : 0);
	stc->accu = (stc->accu > lenum ? stc->accu - lenum : 0);
	if (stc->accu && sig == 1)
	{
		stc->accu--;
		(stc->area ? stc->area++ : 0);
		sig = 0;
	}
	return (ft_strnew(len));
}
