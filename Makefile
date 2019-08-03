# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tegordon <tegordonstudent.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 14:45:38 by tegordon          #+#    #+#              #
#    Updated: 2019/07/23 16:21:27 by tegordon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c parse_all_flags.c handle_percent.c \
cut_right.c pad_left.c pad_right.c so_buff_mgmt.c \
print_csdi.c print_null.c print_pouxb.c nbrconvsn.c
TESTFILE = abcd

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
		make -C libft
		$(CC) $(CFLAGS) -c $(FILES) -I libft
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	rm -f $(TESTFILE)

re: fclean all

test: re
	$(CC) $(CFLAGS) main.c -o $(TESTFILE) -L. -Llibft -lft -lftprintf -I libft
	./$(TESTFILE)

debug: fclean
	make -C libft
	$(CC) $(CFLAGS) -c $(FILES) -I libft -g
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	$(CC) $(CFLAGS) main.c -o $(TESTFILE) -L. -Llibft -lft -lftprintf -I libft -g
	./$(TESTFILE) | cat -e

.PHONY: clean fclean all re
