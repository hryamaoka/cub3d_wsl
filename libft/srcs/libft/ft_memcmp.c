/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <komatsu@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:33:01 by skomatsu          #+#    #+#             */
/*   Updated: 2024/05/09 06:56:48 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	char str1[] = "Hello";
	char str2[] = "Hello";
	char str3[] = "World";
	char str4[] = "hello";

	// 同じ文字列の比較
	int res = memcmp(str1, str2, sizeof(str1));
	printf("memcmp(\"Hello\", \"Hello\"): %d\n", res);

	// 異なる文字列の比較
	res = memcmp(str1, str3, sizeof(str1));
	printf("memcmp(\"Hello\", \"World\"): %d\n", res);

	// 大文字小文字の違いのテスト
	res = memcmp(str1, str4, sizeof(str1));
	printf("memcmp(\"Hello\", \"hello\"): %d\n", res);

	// 部分的な比較
	res = memcmp(str1, str3, 3);
	printf("memcmp(\"Hello\", \"World\", 3): %d\n", res);

	return (0);
}
*/
