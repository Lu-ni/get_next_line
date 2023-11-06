/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:15 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/06 16:01:54 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int read_all(t_utils *u)
{
	char 		*tmp;
	int endtmp;

	while (u->state == INIT_DONE)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return 1;
		endtmp = read(u->fd, tmp, BUFFER_SIZE);
		if (endtmp < 1)
		{
			free(tmp);
			u->state = READ_DONE;
		}
		else
		{
			tmp[endtmp] = '\0';
			u->buffer = ft_strjoin(u->buffer, tmp);
			free(tmp);
			if (!u->buffer)
				return 1;
		}
	}
	return 0;
}

char *get_next_line(int fd)
{
	//init
	static t_utils u;
	char          *line;
	char 		*next_nl;

	line = (char *)0;
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
		}
		u.buffer[u.end] = '\0';
		u.state = INIT_DONE;
	}	
	
	//read all
	if (u.state == INIT_DONE &&	read_all(&u))
	{
		u.state = ERROR_STATE;
		free(u.bufferstart);
		return (char *) 0;
	}
	//return line
	if (u.state == READ_DONE)
	{
		next_nl = ft_strchr(u.buffer, '\n');
		if (next_nl)
		{
			line = ft_substr(u.buffer, 0, next_nl - u.buffer + 1);	
			u.buffer = next_nl + 1;
		}
		else
		{
			line = ft_substr(u.buffer, 0, ft_strlen(u.buffer));	
			free(u.bufferstart);
			u.state = ALL_DONE;
		}
	}
	return (line);
}
