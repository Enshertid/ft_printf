# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 18:18:19 by ymanilow          #+#    #+#              #
#    Updated: 2019/09/15 14:31:32 by dbendu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS_C =	double.c					\
			ft_char.c					\
			ft_printf.c					\
			ft_unsigneditoa_base.c		\
			list_filling_functions.c	\
			list_functions.c			\
			output_digital.c			\
			parsing.c					\
			pointer.c					\
			string.c					\
			usage_flags.c

SRCS_C =	ft_printf.c\
		 ./ft_unsigneditoa_base.c\
		 ./list_filling_functions.c\
		 ./list_functions.c\
		 ./output_digital.c\
		 ./parsing.c\
		 ./pointer.c\
		 ./color_work.c\
		 ./string.c\
		 ./ft_char.c\
		 ./double.c\
		 ./usage_flags.c

SRCS_O = $(SRCS_C:.c=.o)\
		libft/*.o


all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -Ilibft/includes/ $(SRCS_C) libft/libft.a -c
	@ar rc $(NAME) $(SRCS_O)

clean:
	@make clean -C ./libft
	@rm -f $(SRCS_O)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

g:
	@gcc -g -Wall -Werror -Wextra 
	@gcc $(SRCS_C) main.o libft/glibft.a
	@clear

c:
	@clear
	@gcc -Wall -Werror -Wextra $(SRCS_C) main.c libft/libft.a -Ilibft/includes
	@clear
	@./a.out

wc:
	@clear
	@gcc $(SRCS_C) main.c libft/libft.a -Ilibft/includes
	@clear
	@./a.out

g:
	@clear
	@gcc -g -Wall -Werror -Wextra $(SRCS_C) main.c libft/glibft.a -Ilibft/includes
	@clear
