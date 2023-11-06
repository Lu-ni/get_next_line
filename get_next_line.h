/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:34 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/06 15:47:10 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <sys/types.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
#define INIT_DONE 1
#define READ_DONE 2
#define ERROR_STATE 3
#define ALL_DONE 4

typedef struct s_utlils
{
	char *buffer;
	char *bufferstart;
	int  state;
	size_t start;
	ssize_t end;
	int     fd;

} t_utils;
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char *get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
