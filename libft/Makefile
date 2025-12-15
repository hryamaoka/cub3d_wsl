# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 20:03:35 by skomatsu          #+#    #+#              #
#    Updated: 2025/03/27 20:49:05 by skomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a
CC =    cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = ./srcs
INC_DIR = ./includes

LIB_DIR = $(SRCS_DIR)/libft
GNL_DIR = $(SRCS_DIR)/get_next_line
PRNTF_DIR = $(SRCS_DIR)/ft_printf

LIBS	= $(addprefix $(LIB_DIR)/, \
	ft_isalpha.c    \
	ft_isdigit.c    \
	ft_isalnum.c    \
	ft_isascii.c    \
	ft_isprint.c    \
	ft_strlen.c     \
	ft_memset.c     \
	ft_bzero.c      \
	ft_memcpy.c     \
	ft_memmove.c    \
	ft_strlcpy.c    \
	ft_strlcat.c    \
	ft_calloc.c     \
	ft_strdup.c     \
	ft_toupper.c    \
	ft_tolower.c    \
	ft_strchr.c     \
	ft_strncmp.c    \
	ft_memchr.c     \
	ft_memcmp.c     \
	ft_strnstr.c    \
	ft_atoi.c       \
	ft_long_atoi.c  \
	ft_strrchr.c    \
	ft_substr.c     \
	ft_strjoin.c    \
	ft_strtrim.c    \
	ft_split.c      \
	ft_itoa.c       \
	ft_strmapi.c    \
	ft_striteri.c   \
	ft_putchar_fd.c \
	ft_putstr_fd.c  \
	ft_putendl_fd.c \
	ft_putnbr_fd.c  \
	ft_lstadd_back.c    \
	ft_lstadd_front.c   \
	ft_lstclear.c       \
	ft_lstdelone.c      \
	ft_lstiter.c        \
	ft_lstlast.c        \
	ft_lstmap.c         \
	ft_lstnew.c         \
	ft_lstsize.c        \
	) \

GNL	= $(addprefix $(GNL_DIR)/, \
	get_next_line.c	\
	get_next_line_utils.c	\
	) \

PRNTF	= $(addprefix $(PRNTF_DIR)/, \
	ft_printf.c \
	ft_printf_char.c \
	ft_printf_str.c \
	ft_printf_int.c \
	ft_printf_p.c \
	ft_printf_nbr.c	\
	)	\

SRCS	= $(LIBS) $(GNL) $(PRNTF)

OBJS =	$(SRCS:.c=.o)            

all:	$(NAME)

$(NAME):$(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
