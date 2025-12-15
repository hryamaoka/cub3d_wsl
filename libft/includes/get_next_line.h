/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:44:31 by skomatsu          #+#    #+#             */
/*   Updated: 2024/11/23 16:25:26 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef LINE_SIZE
#  define LINE_SIZE 44442
# endif

# ifndef EOF
#  define EOF -1
# endif

# define READ_ERROR -2

typedef struct s_line
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_line;

int			ft_getc(int fd);
int			ft_putc(t_line *line, char c);
char		*get_next_line(int fd);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
