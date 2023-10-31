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

int  check_return(char *str, int start, int end)
{
	int i;

	i = start;
	while (i < end)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static	t_utils u;
	char	*line;
	
	// init the static if first call
	if (!u.buffer)
		u.buffer = malloc(BUFFER_SIZE + 1);
	// when it-s init
	// maybe do a big while around this if else.
	if (check_return(u.buffer, u.start, u.end))
	{
		//malloc line and return it
	}
	else
	{
		//append new read to actual data and check again for \n
			//new malloc of size buffer then str join of data and new buffer
				//end += read (fd, u.temp, bs);
				//u.buffer = ft_strjoin(u.buffer, u.temp) - start;
				//start = 0;
	}

	//read(fd, u.buffer , BUFFER_SIZE);

	return (line);
}
int main(void)
{
	get_next_line(1);	
}
