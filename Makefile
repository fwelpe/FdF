# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 18:13:37 by fwlpe             #+#    #+#              #
#    Updated: 2019/03/18 13:56:30 by cdenys-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
LFT = libft/libft.a
LMLX = minilibx_macos/libmlx.a
SRCS = cam.c colours.c draw.c free_any.c ft_atoi_base.c ft_itoa_base.c \
image.c keyboard.c main.c mouse.c path.c points_for_work.c prepare_points.c \
prepares.c read.c scale.c
OBJ_DIR = objects/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS) $(LFT) $(LMLX)
	$(CC) $(OBJS) $(LFT) $(LMLX) -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR) || true
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
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re: fclean all
