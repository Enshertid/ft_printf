# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 18:18:19 by ymanilow          #+#    #+#              #
#    Updated: 2019/09/12 20:10:16 by dbendu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_C =	ft_printf.c\
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
		libft/*.o


all: $(NAME)

$(NAME):
	make -C libft
	@gcc -Wall -Werror -Wextra -Ilibft/includes/libft.h $(SRCS_C) -c
	@ar rc $(NAME) $(SRCS_O)

clean:
	@make clean -C ./libft
	@rm -f $(SRCS_O)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

a:  fclean all
	clear
	@gcc -Wall -Wextra -Werror  main.c libftprintf.a -o ft_printf
	@./ft_printf

c: 	clean
	clear
	@rm -Rf ./ft_printf


re: fclean all

g:
	@gcc -g -Wall -Werror -Wextra -Ilibft/includes/libft.h $(SRCS_C) -c
	@gcc $(SRCS_O) libft/glibft.a
	@clear
