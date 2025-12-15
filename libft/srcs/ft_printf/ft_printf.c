/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:52:59 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/17 00:20:50 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(int fd, char const *c, va_list *ap)
{
	char	buf[2];

	buf[0] = '%';
	buf[1] = *c;
	if (*c == 'c')
		return (ft_printf_char(fd, va_arg(*ap, int)));
	else if (*c == 's')
		return (ft_printf_str(fd, va_arg(*ap, char *)));
	else if (*c == 'p')
		return (ft_printf_p(fd, (unsigned long)va_arg(*ap, void *)));
	else if (*c == 'd' || *c == 'i')
		return (ft_printf_int(fd, va_arg(*ap, int)));
	else if (*c == 'u')
		return (ft_printf_nbr(fd, va_arg(*ap, unsigned int), BASE_10));
	else if (*c == 'x')
		return (ft_printf_nbr(fd, va_arg(*ap, unsigned int), BASE_16_LOW));
	else if (*c == 'X')
		return (ft_printf_nbr(fd, va_arg(*ap, unsigned int), BASE_16_UP));
	else if (*c == '%')
		return (write(fd, "%", 1));
	else if (*c == '\0')
		return (write(fd, "%", 1));
	else
		return (write(fd, buf, 2));
}

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	int		len;
	ssize_t	tmp;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		tmp = 0;
		if (*fmt == '%')
		{
			fmt++;
			tmp += ft_checktype(STDOUT_FILENO, fmt, &ap);
		}
		else
			tmp += write(STDOUT_FILENO, fmt, 1);
		if (tmp == -1)
			return (-1);
		len += tmp;
		fmt++;
	}
	va_end(ap);
	return (len);
}
