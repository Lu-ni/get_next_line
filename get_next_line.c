/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:15 by lnicolli          #+#    #+#             */
/*   Updated: 2023/10/31 20:44:38 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int check_return(char *str, int start, int end, int *inl)
{
	int i;

	i = start;
	while (i < end)
	{
		if (str[i] == '\n')
		{
			*inl = i;
			return (i);
		}
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static t_utils u;
	char          *line;
	int            inl;
	char          *tmp;
	int            endtmp;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (!u.buffer)
	{
		u.buffer = malloc(BUFFER_SIZE + 1);
		u.end = read(fd, u.buffer, BUFFER_SIZE);
		if (u.end < 0)
			return (NULL);
		u.buffer[u.end] = '\0';
	}
	while (1)
	{
		if (check_return(u.buffer, u.start, u.end, &inl))
		{
			line = malloc(sizeof(char) * (inl - u.start + 1));
			if (!line)
			{
				free(u.buffer);
				return (line);
			}
			ft_memcpy(line, &u.buffer[u.start], inl - u.start);
			line[inl - u.start] = '\0';
			u.start = inl + 1;
			return (line);
		}
		else
		{
			tmp = malloc(BUFFER_SIZE + 1);
			if (!tmp)
			{
				free(u.buffer);
				return (NULL);
			}
			endtmp = read(fd, tmp, BUFFER_SIZE);
			tmp[endtmp] = '\0';
			u.buffer = ft_strjoin(&u.buffer[u.start], tmp, u.buffer);
			u.end = u.end + endtmp - u.start;
			u.start = 0;
			if (!endtmp)
			{
				free(u.buffer);
				return (NULL);
			}
		}
	}
}
int main()
{
	int fd = open("txt.txt", O_RDONLY);
	if (fd == -1)
		return 1;

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line:\"%s\"\n", line);
		free(line);
	}

	close(fd);
	return 0;
}
