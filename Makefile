SRCS = main.c printf.c

all:
	@clear
	@gcc -Wall -Werror -Wextra $(SRCS) libft/libft.a -Ilibft/includes
	@./a.out

g:
	@clear
	@gcc -g -Wall -Werror -Wextra $(SRCS) libft/libft.a -Ilibft/includes