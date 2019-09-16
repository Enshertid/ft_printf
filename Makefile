# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 18:18:19 by ymanilow          #+#    #+#              #
#    Updated: 2019/09/16 18:57:31 by ymanilow         ###   ########.fr        #
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
	@gcc -Wall -Werror -Wextra -Ilibft/includes/ $(SRCS_C) -c
	@ar rc $(NAME) $(SRCS_O)

clean:
	@make clean -C ./libft
	@rm -f $(SRCS_O)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

a:  fclean all
	clear
	@gcc -Wall -Wextra -Werror  libftprintf.a -o ft_printf -Ilibft/includes main.c
	@./ft_printf


re: fclean all

c:
	@clear
	@gcc -Wall -Werror -Wextra *.c libft/libft.a -Ilibft/includes
	@clear
	@./a.out

wc:
	@clear
	@gcc *.c libft/libft.a -Ilibft/includes
	@clear
	@./a.out


g:
	@clear
	@gcc -g -Wall -Werror -Wextra *.c libft/libft.a -Ilibft/includes
	@clear

wg:
	@clear
	@gcc -g *.c libft/libft.a -Ilibft/includes
	@clear

a:
	gcc -Wall -Werror -Wextra
