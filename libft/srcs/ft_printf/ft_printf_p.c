/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:03:47 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/10 18:15:54 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(int fd, unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
	{
		len += write(fd, "(nil)", 5);
		return (len);
	}
	len += ft_printf_0x();
	len += ft_printf_nbr(fd, n, BASE_16_LOW);
	return (len);
}
