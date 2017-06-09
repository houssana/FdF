# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houssana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/06 16:26:13 by houssana          #+#    #+#              #
#    Updated: 2017/06/06 17:12:58 by houssana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =fdf
SRC =srcs/
INCL =-I includes/ -I libft/
SRC_FILES =*.c

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(SRC)*.c libft/libft.a $(INCL) -L/usr/X11/lib -lmlx -lXext -lX11 -lm

clean:
	make -C libft/ clean

fclean:
	make -C	libft/ fclean
	rm -f $(NAME)

re: fclean all
