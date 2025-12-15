/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:06:46 by skomatsu          #+#    #+#             */
/*   Updated: 2024/11/05 17:09:08 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_0x(void)
{
	return (write(1, "0x", 2));
}

int	ft_printf_nbr(int fd, unsigned long n, const char *s)
{
	unsigned int	base;
	unsigned long	e;
	int				len;

	base = ft_strlen(s);
	if (base < 2 || !s)
		return (-1);
	e = 1;
	len = 0;
	while (n / e >= base)
		e *= base;
	while (e > 0)
	{
		len += ft_printf_char(fd, s[n / e % base]);
		e /= base;
	}
	return (len);
}
