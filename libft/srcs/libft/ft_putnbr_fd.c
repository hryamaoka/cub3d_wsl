/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <komatsu@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 02:03:56 by skomatsu          #+#    #+#             */
/*   Updated: 2024/06/11 20:58:00 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digit_of_int(int n)
{
	long long	lln;
	size_t		digit;

	if (!n)
		return (1);
	lln = n;
	digit = 0;
	if (lln < 0)
		lln = -lln;
	while (0 < lln)
	{
		lln /= 10;
		digit++;
	}
	return (digit);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	lln;
	size_t		len;
	char		str[12];

	if (!n)
		return (ft_putchar_fd('0', fd));
	len = get_digit_of_int(n);
	lln = n;
	if (n < 0)
	{
		lln = -lln;
		len++;
	}
	str[len--] = '\0';
	while (0 < lln)
	{
		str[len--] = (lln % 10) + '0';
		lln /= 10;
	}
	if (n < 0)
		str[len] = '-';
	ft_putstr_fd(str, fd);
}
