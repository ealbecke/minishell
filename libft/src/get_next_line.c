/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:14:10 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:14:21 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** For more information on the fonctions
** see the header get_next_line.h
*/
#include "get_next_line.h"
#include "libft.h"

static char	*ft_gnlc(t_lineup **sline, char const *str, int const fd)
{
	t_lineup	*tline;
	t_lineup	*pline;

	tline = *sline;
	pline = NULL;
	while (tline)
	{
		if (tline->fd == fd)
		{
			(str ? ft_strdel(&tline->oversave) : 0);
			(str ? tline->oversave = (char *)str : '\0');
			return (tline->oversave);
		}
		pline = tline;
		tline = tline->next;
	}
	if (!(tline = (t_lineup *)malloc(sizeof(t_lineup))))
		return (NULL);
	tline->fd = fd;
	tline->oversave = ft_strnew(1);
	tline->next = NULL;
	(pline ? pline->next = tline : NULL);
	*sline = (*sline ? *sline : tline);
	return (tline->oversave);
}

static int	ft_gnlfreer(t_lineup **lfree, int fd)
{
	t_lineup	*tfree;
	t_lineup	*pfree;

	if (!lfree)
		return (END);
	tfree = *lfree;
	pfree = NULL;
	while (tfree)
	{
		if (tfree->fd == fd)
		{
			free(tfree->oversave);
			if (pfree)
				pfree->next = tfree->next;
			else
				*lfree = tfree->next;
			free(tfree);
			return (SUCCES);
		}
		pfree = tfree;
		tfree = tfree->next;
	}
	return (END);
}

static char	*ft_gnlchrl(char **str)
{
	char	*ptr;
	int		cut;

	if (!str || !*str)
		return (NULL);
	cut = ft_strclen(*str, SEARCH);
	if (!(**str + cut))
	{
		*str = ft_strnew(1);
		return (NULL);
	}
	ptr = *str + cut + 1;
	*str = ft_strsub(*str, 0, cut);
	return (ft_strsub(ptr, 0, ft_strlen(ptr)));
}

static int	ft_gnlnext(t_lineup **sline, int const fd)
{
	char	*buf;
	char	*nbuf;
	char	*eobuf;
	int		check;

	buf = ft_strnew(BUFF_SIZE + 1);
	nbuf = NULL;
	check = 1;
	while (!nbuf && check)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		check = read(fd, buf, BUFF_SIZE);
		if (check == ERROR)
			return (ERROR);
		nbuf = ft_strchr(buf, SEARCH);
		ft_gnlc(sline, ft_strjoin(ft_gnlc(sline, NULL, fd), buf), fd);
	}
	if (!check && *ft_gnlc(sline, NULL, fd))
	{
		eobuf = ft_strdup(ft_gnlc(sline, NULL, fd));
		eobuf[ft_strlen(eobuf)] = '\n';
		ft_gnlc(sline, eobuf, fd);
	}
	free(buf);
	return (check);
}

int			get_next_line(int const fd, char **line)
{
	static t_lineup		*sline = NULL;
	char				*tbuf;
	char				*ebuf;
	int					check;

	if (fd <= -1 || BUFF_SIZE < 1 || !line)
		return (ERROR);
	check = (sline ? 1 : 0);
	if (!(tbuf = ft_strchr(ft_gnlc(&sline, NULL, fd), SEARCH)))
		if ((check = ft_gnlnext(&sline, fd)) == ERROR)
			return (ERROR);
	ebuf = ft_gnlc(&sline, NULL, fd);
	ft_gnlc(&sline, ft_gnlchrl(&ebuf), fd);
	*line = ebuf;
	if (!check && !*ft_gnlc(&sline, NULL, fd) && !**line && !tbuf)
	{
		if (ft_gnlfreer(&sline, fd) == ERROR)
			return (ERROR);
		return (END);
	}
	return (SUCCES);
}
