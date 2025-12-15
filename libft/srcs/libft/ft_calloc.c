/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <komatsu@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:14:30 by skomatsu          #+#    #+#             */
/*   Updated: 2024/06/11 21:10:10 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	total;

	if (count == 0 || size == 0)
	{
		dst = malloc(0);
		return (dst);
	}
	total = count * size;
	if (total / count != size)
		return (NULL);
	dst = malloc(total);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, total);
	return (dst);
}
