/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <komatsu@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:53:50 by skomatsu          #+#    #+#             */
/*   Updated: 2024/06/04 16:08:28 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		while (needle[n] != '\0' && haystack[h + n] == needle[n] && (h
				+ n) < len)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
			{
				return ((char *)haystack + h);
			}
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + h);
		h++;
	}
	return (NULL);
}
