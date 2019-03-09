# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwlpe <fwlpe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 18:13:37 by fwlpe             #+#    #+#              #
#    Updated: 2019/03/09 18:59:32 by fwlpe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

all: $(NAME)

$(NAME):
	make -C libft/
	cp libft/libft.a .
	make -C minilibx_macos/
	cp minilibx_macos/libmlx.a .
	gcc *.c *.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean

fclean:
	make -C libft/ fclean
	make -C minilibx_macos/ clean
	rm -f $(NAME)

re: fclean all
