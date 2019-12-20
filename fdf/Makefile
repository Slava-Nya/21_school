# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2019/12/17 21:37:13 by hlorrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf


SRC = main_0.c 
O = main_0.c

all:
		gcc $(SRC) ../libft/libft.a -L/usr/local/lib/ -g -lmlx -framework OpenGL -framework AppKit

clean:
		@/bin/rm -f $(O)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all