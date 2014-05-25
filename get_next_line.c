/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguignar <rguignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 01:08:12 by rguignar          #+#    #+#             */
/*   Updated: 2014/05/25 16:57:10 by rguignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"
#define BUFF_SIZE 4242

int					ft_alloc(char **line, unsigned int size)
{
	*line = (*line == NULL) ? (char *)malloc(size) : (char *)realloc(*line, size);
	return ((*line == NULL) ? 0 : 1);
}

int					fill_til_nl(int *y, int r, char *line, char buf[BUFF_SIZE])
{
	int				i;

	i = 0;
	while (i < r && buf[i] != '\n')
	{
		line[*y] = buf[i];
		(*y)++;
		i++;
	}
	return ((buf[i] == '\n') ? 1 : 0);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE];
	int				ret;
	static	int		offset = 0;
	int				stop;
	int				y;

	y = 0;
	stop = 0;
	*line = NULL;
	lseek(fd, offset, SEEK_SET);
	while ((ret = read(fd, buf, BUFF_SIZE)) && !stop)
	{	
		ft_alloc(line, sizeof (**line) * (ret + ft_strlen(*line)));
		stop = fill_til_nl(&y, ret, *line, buf);
	}
	if (*line)
		(*line)[y] = '\0';
	offset += y + 1;
	return (stop);
}
