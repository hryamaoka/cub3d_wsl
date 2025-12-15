/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <komatsu@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:14:47 by skomatsu          #+#    #+#             */
/*   Updated: 2024/06/04 16:01:03 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*t;
	size_t	len;
	int		i;

	len = ft_strlen(src);
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		t[i] = src[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
