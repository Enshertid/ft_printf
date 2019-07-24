all:
	@clear
	@gcc -Wall -Werror -Wextra main.c libft/libft.a
	@./a.out

g:
	@clear
	@gcc -g -Wall -Werror -Wextra main.c libft/ft_lstappend.c libft/ft_lstnew.c libft/ft_strlen.c libft/ft_memchr.c libft/ft_memcpy.c libft/ft_lstclear.c -Ilibft/includes
