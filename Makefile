# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 18:18:19 by ymanilow          #+#    #+#              #
#    Updated: 2019/09/12 14:26:48 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_C = ./ft_printf.c\
		 ./ft_unsigneditoa_base.c\
		 ./list_filling_functions.c\
		 ./list_functions.c\
		 ./output_digital.c\
		 ./parsing.c\
		 ./pointer.c\
		 ./string.c\
		 ./ft_char.c\
		 ./float.c\
		 ./double.c\
		 ./usage_flags.c

SRCS_O = $(SRCS_C:.c=.o)\
		libft1/*.o


all: $(NAME)

$(NAME):
	@make -C ./libft1/
	@gcc -Wall -Werror -Wextra -Ilibft1/includes/libft.h $(SRCS_C) -c
	@ar rc $(NAME) $(SRCS_O) 

clean:
	@make clean -C ./libft1
	@rm -f $(SRCS_O)

fclean: clean
	@make fclean -C ./libft1
	@rm -f $(NAME)

a:  fclean all
	clear
	@gcc -Wall -Wextra -Werror  main.c libftprintf.a -o ft_printf
	@./ft_printf

c: 	clean
	clear
	@rm -Rf ./ft_printf


re: fclean all
