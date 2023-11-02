/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:34 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/02 17:57:55 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <sys/_types/_size_t.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif
#define INIT_DONE 1
#define ERROR_STATE 2
#define FINISHED_STATE 3
#define EOL_STATE 4
typedef struct s_utlils
{
	char *buffer;
	size_t   start;
	size_t   end;
	int   state;

} t_utils;
void *ft_memcpy(void *dst, const void *src, size_t n);
char *ft_strjoin(char *s1, char *s2, char *starts1);
char *get_next_line(int fd);
#endif
