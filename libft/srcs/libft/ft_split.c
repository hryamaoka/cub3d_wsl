/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:35:46 by skomatsu          #+#    #+#             */
/*   Updated: 2024/09/11 22:36:48 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *str, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		str++;
	}
	return (count);
}

size_t	get_next_substr_len(const char **str, char c)
{
	size_t		len;
	const char	*start;

	len = 0;
	while (**str && **str == c)
		(*str)++;
	start = *str;
	while (**str && **str != c)
	{
		(*str)++;
		len++;
	}
	if (*str > start)
		return (len);
	return (0);
}

void	contents_free(char **result, size_t n)
{
	while (n--)
	{
		free(result[n]);
		result[n] = NULL;
	}
	free(result);
	result = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		len = get_next_substr_len(&s, c);
		if (!len)
			continue ;
		result[i] = ft_substr(s - len, 0, len);
		if (!result[i++])
		{
			contents_free(result, i);
			return (NULL);
		}
	}
	result[i] = NULL;
	return (result);
}
