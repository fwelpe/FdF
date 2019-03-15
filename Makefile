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
CC = gcc
LFT = libft/libft.a
LMLX = minilibx_macos/libmlx.a
SRCS = cam.c colours.c draw.c free_any.c ft_atoi_base.c ft_itoa_base.c \
image.c keyboard.c main.c mouse.c path.c points_for_work.c prepare_points.c \
prepares.c read.c scale.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LFT) $(LMLX)
	$(CC) $(OBJS) $(LFT) $(LMLX) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $^

$(LFT):
	make -C libft/

$(LMLX):
	make -C minilibx_macos/

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm $(OBJS)

fclean:
	make -C libft/ fclean
	make -C minilibx_macos/ clean
	rm $(OBJS)
	rm $(NAME)

re: fclean all
