# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/16 21:39:26 by tegordon          #+#    #+#              #
#    Updated: 2019/08/02 23:13:45 by tegordon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
FILES = ft_bzero.c ft_memalloc.c ft_strnew.c ft_strjoin.c make_string.c \
ft_strcatend.c ft_strcpyend.c ft_strjoinfree2ndptrnull.c \
ft_strjoinfree1stptr.c ft_memcpy.c ft_strcat.c ft_strjoinfree2ndptr.c \
ft_strlen.c ft_memset.c ft_strrev.c ft_atoi.c

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -c $(FILES)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

