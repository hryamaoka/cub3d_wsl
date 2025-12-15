/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:44:06 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/20 19:01:14 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char	buf [BUFFER_SIZE];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (n++, READ_ERROR);
		bufp = buf;
	}
	n --;
	if (n >= 0)
		return (*bufp ++);
	return (n++, EOF);
}

int	ft_putc(t_line *line, char c)
{
	char	*new_str;
	int		new_capa;

	if (!line->capa)
	{
		line->capa = LINE_SIZE;
		line->str = (char *)malloc(sizeof(char) * (line->capa + 1));
		if (!line->str)
			return (-1);
		line->str[0] = '\0';
	}
	if (line->capa <= line->len +1)
	{
		new_capa = line->len * 2;
		new_str = (char *)malloc(sizeof(char) * (new_capa + 1));
		if (!new_str)
			return (-1);
		ft_memcpy(new_str, line->str, line->len);
		free(line->str);
		line->str = new_str;
		line->capa = new_capa;
	}
	line->str[line->len++] = c;
	line->str[line->len] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	char	c;
	t_line	line;

	line.str = NULL;
	line.len = 0;
	line.capa = 0;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
			return (free(line.str), NULL);
		if (c == EOF)
			break ;
		if (ft_putc (&line, c) == -1)
			return (free (line.str), NULL);
		if (c == '\n')
			break ;
	}
	if (line.len > 0 && (ft_putc(&line, '\0') == 0))
		return (free(line.str), NULL);
	return (line.str);
}
