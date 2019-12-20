# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 21:35:46 by hlorrine          #+#    #+#              #
#    Updated: 2019/09/06 22:40:08 by hlorrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = ft_display_file.c

all:
		gcc -c -Wall -Werror -Wextra $(SRC)
		gcc -o $(NAME) ft_display_file.o

clean:
		rm -rf ft_display_file.o

fclean: clean
		rm -rf $(NAME)

re: fclean all
