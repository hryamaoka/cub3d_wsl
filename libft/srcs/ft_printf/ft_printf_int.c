/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:07:15 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/14 07:21:24 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int fd, int args)
{
	char	*str;
	int		len;

	str = ft_itoa(args);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	write(fd, str, len);
	free(str);
	return (len);
}
