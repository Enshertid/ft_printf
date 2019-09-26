# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 18:18:19 by ymanilow          #+#    #+#              #
#    Updated: 2019/09/26 21:15:45 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_C = ./ft_printf.c\
		 ./ft_unsigneditoa_base.c\
		 ./list_filling_functions.c\
		 ./list_functions.c\
		 ./output_digital.c\
		 ./output.c\
		 ./parsing.c\
		 ./pointer.c\
		 ./string.c\
		 ./ft_char.c\
		 ./double.c\
		 ./double1.c\
		 ./double2.c\
		 ./color_work.c\
		 ./output_bits.c\
		 ./usage_flags.c

SRCS_O = $(SRCS_C:.c=.o)\
		libft/*.o


all: $(NAME)

$(NAME):
	make -C libft
	@gcc -Wall -Werror -Wextra -Ilibft/includes/ $(SRCS_C) -c
	@ar rc $(NAME) $(SRCS_O)

clean:
	@make clean -C ./libft
	@rm -f $(SRCS_O)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

rc:
	@clear
	@gcc -Wall -Werror -Wextra main.c $(SRCS_C) libft/*.c -Ilibft/includes
	@clear
	@./a.out

c:
	@clear
	@gcc -Wall -Werror -Wextra main.c libftprintf.a -Ilibft/includes
	@clear
	@./a.out

wc:
	@clear
	@gcc main.c libftprintf.a -Ilibft/includes
	@clear
	@./a.out

w:
	make -C libft
	@gcc -Ilibft/includes/ $(SRCS_C) -c
	@ar rc $(NAME) $(SRCS_O)

g:
	@clear
	@gcc -g -Wall -Werror -Wextra *.c libft/glibft.a -Ilibft/includes
	@clear
