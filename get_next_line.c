/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:15 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/06 18:08:03 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int get_data(t_utils *u)
{
	char   *tmp;
	ssize_t end;

	while (!ft_strchr(u->buffer, '\n') || u->eol)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (1);
		end = read(u->fd, tmp, BUFFER_SIZE);
		if (end < 0)
		{
			free(tmp);
			return (1);
		}
		if (end == 0)
		{
			u->eol = 1;
			free(tmp);
			return (0);
		}
		if (end < BUFFER_SIZE)
			u->eol = 1;

		tmp[end] = '\0';
		u->buffer = ft_strjoin(u, tmp);
		if (!u->buffer)
			return (1);
		free(tmp);
	}
	return (0);
}

char *get_next_line(int fd)
{
	static t_utils u;
	char          *line;
	char          *next_nl;

	line = (char *) 0;
	u.fd = fd;
	if (BUFFER_SIZE < 1 || BUFFER_SIZE > SIZE_T_MAX || u.state == ERROR_STATE)
		return (NULL);
	if (u.state == 0)
	{
		u.buffer = malloc(BUFFER_SIZE + 1);
		u.end = read(fd, u.buffer, BUFFER_SIZE);
		if (u.end < 1)
		{
			u.state = ERROR_STATE;
			free(u.buffer);
			return (char *) 0;
		}
		u.buffer[u.end] = '\0';
		u.bufferstart = u.buffer;
		u.state = INIT_DONE;
	}

	if (get_data(&u))
	{
		u.state = ERROR_STATE;
		return (char *) 0;
	}
	next_nl = ft_strchr(u.buffer, '\n');
	if (next_nl)
	{
		line = ft_substr(u.buffer, 0, next_nl - u.buffer + 1);
		u.buffer = next_nl + 1;
	}
	else if (u.eol && u.state != ALL_DONE)
	{
		line = ft_substr(u.buffer, 0, ft_strlen(u.buffer));
		u.state = ALL_DONE;
		free(u.bufferstart);
	}
	return line;
}
