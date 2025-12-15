/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:08:12 by skomatsu          #+#    #+#             */
/*   Updated: 2024/10/20 17:31:09 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(int fd, char *src)
{
	if (!src)
		return (write(fd, "(null)", 6));
	return (write(fd, src, ft_strlen(src)));
}
