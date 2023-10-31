/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:34 by lnicolli          #+#    #+#             */
/*   Updated: 2023/10/31 17:09:13 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/_types/_size_t.h>

#define BUFFER_SIZE 42
typedef struct s_utlils{
	char *buffer;
	int  start;
	int  end;

} t_utils;
#endif
