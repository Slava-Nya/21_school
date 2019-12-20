# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 18:26:50 by hlorrine          #+#    #+#              #
#    Updated: 2019/09/08 17:29:12 by hlorrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
O = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
INCLUDE = includes

all:
			gcc -c $(SRC) -I $(INCLUDE)
			ar rc $(NAME) $(O)
			ranlib $(NAME)

clean:
			/bin/rm -f $(O)

fclean: clean
			/bin/rm -f $(NAME)

re: fclean all
