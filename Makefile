# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/06 18:18:19 by ymanilow          #+#    #+#              #
#    Updated: 2019/09/15 20:33:57 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
