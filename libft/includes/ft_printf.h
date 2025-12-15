/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:15:42 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/20 19:19:05 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define PRINT_FD STDOUT_FILENO
# define BASE_10 "0123456789"
# define BASE_16_UP "0123456789ABCDEF"
# define BASE_16_LOW "0123456789abcdef"

int	ft_printf(char const *fmt, ...);
int	ft_checktype(int fd, char const *c, va_list *ap);
int	ft_printf_char(int fd, int c);
int	ft_printf_str(int fd, char *str);
int	ft_printf_int(int fd, int i);
int	ft_printf_0x(void);
int	ft_printf_nbr(int fd, unsigned long n, const char *s);
int	ft_printf_p(int fd, unsigned long n);

#endif
