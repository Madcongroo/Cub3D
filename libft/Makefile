# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 12:13:34 by bproton           #+#    #+#              #
#    Updated: 2024/10/09 02:41:56 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS =	ft_strlen.c \
	    ft_memmove.c \
	    ft_memcpy.c \
	    ft_strlcpy.c \
	    ft_strlcat.c \
	    ft_isalpha.c \
	    ft_isdigit.c \
	    ft_isalnum.c \
	    ft_isascii.c \
	    ft_isprint.c \
	    ft_memset.c \
	    ft_bzero.c \
	    ft_toupper.c \
	    ft_tolower.c \
		ft_strchr.c \
	    ft_strrchr.c \
	    ft_strncmp.c \
		ft_strcmp.c \
	    ft_memchr.c \
	    ft_memcmp.c \
	    ft_strnstr.c \
	    ft_atoi.c \
	    ft_calloc.c \
	    ft_strdup.c \
	    ft_substr.c \
	    ft_strjoin.c \
	    ft_strtrim.c \
	    ft_split.c \
	    ft_itoa.c \
	    ft_strmapi.c \
	    ft_striteri.c \
	    ft_putchar_fd.c \
	    ft_putstr_fd.c \
	    ft_putendl_fd.c \
	    ft_putnbr_fd.c

BSRCS = ft_lstnew.c \
	    ft_lstadd_front.c \
	    ft_lstsize.c \
	    ft_lstlast.c \
	    ft_lstadd_back.c \
	    ft_lstdelone.c \
	    ft_lstclear.c \
	    ft_lstiter.c \
	    ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(NAME) $(BOBJS)
	$(AR) $(NAME) $(BOBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re