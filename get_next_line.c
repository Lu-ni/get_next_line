/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:15 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/02 17:57:53 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <limits.h>

#include <stdio.h>

int check_return(char *str, size_t start, size_t end, size_t *inl)
{
	size_t i;

	i = start;
	if (!*str)
		return (0);
	while (i < end)
	{
		if (str[i] == '\n')
		{
			*inl = i;
			return (1);
		}
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static t_utils u;
	char          *line;
	size_t         inl;
	char          *tmp;
	size_t         endtmp;

	if (BUFFER_SIZE < 1 || BUFFER_SIZE > SIZE_T_MAX || u.state == ERROR_STATE)
		return (NULL);
	if (u.state == 0)
	{
		u.buffer = malloc(BUFFER_SIZE + 1);
		u.end = read(fd, u.buffer, BUFFER_SIZE);
		if (u.end < 1)
		{
			free(u.buffer);
			u.state = ERROR_STATE;
			return (NULL);
		}
		u.buffer[u.end] = '\0';
		u.state = INIT_DONE;
	}
	while (u.state == INIT_DONE || u.state == EOL_STATE)
	{
		if (u.state == EOL_STATE || check_return(u.buffer, u.start, u.end, &inl))
		{
			line = malloc(sizeof(char) * (inl - u.start + 1));
			if (!line)
			{
				free(u.buffer);
				u.state = ERROR_STATE;
				return (line);
			}
			ft_memcpy(line, &u.buffer[u.start], inl - u.start + 1);
			line[inl - u.start + 1] = '\0';
			u.start = inl + 1;
			if (u.state == EOL_STATE)
				u.state = FINISHED_STATE;
			return (line);
		}
		else
		{
			tmp = malloc(BUFFER_SIZE + 1);
			if (!tmp)
			{
				free(u.buffer);
				u.state = ERROR_STATE;
				return (NULL);
			}
			endtmp = read(fd, tmp, BUFFER_SIZE);
			if (endtmp < 1) //not finish
			{
				free(tmp);
				u.state = EOL_STATE;
				inl = u.end + 1;
			}
			else
			{
				tmp[endtmp] = '\0';
				u.buffer = ft_strjoin(&u.buffer[u.start], tmp, u.buffer);
				if (!u.buffer)
				{
					return (NULL);
				}
				// printf("buff:%s?\n", u.buffer);
				u.end = u.end + endtmp - u.start;
				u.start = 0;
			}
		}
	}
	free(u.buffer);
	return (char *) 0;
}
