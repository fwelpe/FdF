# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 13:53:44 by cdenys-a          #+#    #+#              #
#    Updated: 2019/02/11 19:03:35 by cdenys-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = *.c
OBJS = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c ${SRCS} -I.
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

so:
	gcc -shared -o libft.so -fPIC ft_*.c -I.

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette ft_* libft.h
