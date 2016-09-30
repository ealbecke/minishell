/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:16:24 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/28 11:45:57 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** You can define the size of: BUFF_SIZE
** Size of buffer to read() fonction in get_next_line.c
*/
# define BUFF_SIZE 8

# define SEARCH '\n'
# define ERROR -1
# define SUCCES 1
# define END 0

# include "libft.h"

/*
** Includes for fonction read()
** ----------------------------
*/
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
** Include for fonctions malloc() and free()
** -----------------------------------------
*/
# include <stdlib.h>

typedef struct	s_lineup
{
	int				fd;
	char			*oversave;
	struct s_lineup	*next;
}				t_lineup;

int				get_next_line(int const fd, char **line);

#endif
